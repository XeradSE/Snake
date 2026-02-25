#include "./../include/Game.hpp"
#include "raylib.h"
#include <iostream>

void Game::update(Vector2 direction) {

    checkCollisions();

    is_running = true;

    int timer = 0;

    if (is_running) {

        timer += GetFrameTime();
        std::cout << timer << std::endl;
        if (timer >= move_interval) {
            timer = 0;
            snake.move();
            checkCollisions();
            std::cout << "print" << std::endl;
        }

        snake.setDirection(direction);
        snake.draw();
        if (snake.getHead().x == nourriture.x && snake.getHead().y == nourriture.y) {
            snake.grow();
            spawnfood();
        } else {
            snake.move();
        }
    }

}

void Game::draw() {

    for (int i = 0; i < nb_cell_width; i++) {
        for (int j = 0; j < nb_cell_height; j++) {
            DrawRectangle(i*cell_size, j*cell_size, cell_size, cell_size, YELLOW);
        }
    }

    DrawRectangle(nourriture.x*cell_size, nourriture.y*cell_size, cell_size, cell_size, RED);

}

void Game::spawnfood() {

    std::uniform_int_distribution<int> dist(nb_cell_height, nb_cell_width);
    Vector2 temp; 
    bool cell_empty = false;

    while (!cell_empty) {
        temp = {static_cast<float>(dist(rng)), static_cast<float>(dist(rng))};
        for (const Vector2& v : snake.getSnakeBody()) {
            if (v.x != temp.x && v.y != temp.y) {
                cell_empty = true;
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
        if (snake.getHead().x == nb_cell_height || snake.getHead().y == nb_cell_width) {
            is_running = false;
        }
    }

}

void Game::reset() {

}