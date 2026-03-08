#pragma once

#include "Snake.hpp"
#include <random>
#include "Menu.hpp"

class Game {

    const int nb_cell_width = 10;
    const int nb_cell_height = 10;
    const int cell_size = 60;
    Snake snake;
    Vector2 nourriture;
    int move_interval = 1;
    int score = 0;
    bool is_running = true;
    std::mt19937 rng{std::random_device{}()};
    float timer = 0.0f;
    Menu menu;

public:

    void update(Vector2 direction);
    void draw();
    void spawnfood();
    void checkCollisions();
    void reset();

    Menu& getMenu() {return menu;};
    int getScore() {return score;};
    void setIsRunning(bool is_running) {this->is_running = is_running;};

};