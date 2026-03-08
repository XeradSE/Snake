#include "./../include/Game.hpp"
#include "raylib.h"

void Game::update(Vector2 direction) {

    checkCollisions();

    if (is_running) {

        float move_interval = 0.16; //0.16s -> 60fps

        snake.setDirection(direction);

        timer += GetFrameTime();
        if (timer >= move_interval) {
            timer = 0;
            if (snake.getHead().x == nourriture.x && snake.getHead().y == nourriture.y) {
                snake.grow();
                spawnfood();
            } else {
                snake.move();
            }
        }
    } else {
        menu.setGameOver(true);
        reset();
    }
}

void Game::draw() {

    for (int i = 0; i < nb_cell_width; i++) {
        for (int j = 0; j < nb_cell_height; j++) {
            DrawRectangle(i*cell_size, j*cell_size, cell_size, cell_size, YELLOW);
        }
    }

    DrawRectangle(nourriture.x*cell_size, nourriture.y*cell_size, cell_size, cell_size, RED);

    snake.draw();

}

void Game::spawnfood() {

    std::uniform_int_distribution<int> dist_x(0, nb_cell_width - 1);
    std::uniform_int_distribution<int> dist_y(0, nb_cell_height - 1);

    Vector2 temp;
    bool cell_empty = false;

    while (!cell_empty) {
        cell_empty = true;
        temp = {static_cast<float>(dist_x(rng)), static_cast<float>(dist_y(rng))};
        for (const Vector2& v : snake.getSnakeBody()) {
            if (v.x == temp.x && v.y == temp.y) {
                cell_empty = false;
                break;
            }
        }
    }

    nourriture = temp;

}

void Game::checkCollisions() {

    if (snake.checkSelfCollision()) {
        is_running = false;
    } else {
        is_running = true;
    }

    if (is_running) {
        if (snake.getHead().x >= nb_cell_height || snake.getHead().y >= nb_cell_width || snake.getHead().x < 0 || snake.getHead().y < 0) {
            is_running = false;
        }
    }
}

void Game::reset() {
    score = 0;
    snake.reset();
    snake.setDirection(Vector2{0, 0});
}