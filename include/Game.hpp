#pragma once

#include "Snake.hpp"
#include "raylib.h"
#include <random>

class Game {

    const int nb_cell_width = 10;
    const int nb_cell_height = 10;
    const int cell_size = 60;
    Snake snake;
    Vector2 nourriture;
    int move_interval = 1;
    int score;
    bool is_running = true;
    std::mt19937 rng{std::random_device{}()};

public:

    void update(Vector2 direction);
    void draw();
    void spawnfood();
    void checkCollisions();
    void reset();

};