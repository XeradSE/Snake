#include "./../include/Snake.hpp"
#include "raylib.h"

Snake::Snake() {

    snake_body.push_front(Vector2{1, 1});

}

void Snake::move() {

    Vector2 new_head = {snake_body.front().x + direction.x, snake_body.front().y + direction.y};
    snake_body.push_front(new_head);
    snake_body.pop_back();

}

void Snake::grow() {

    Vector2 new_head = {snake_body.front().x + direction.x, snake_body.front().y + direction.y};
    snake_body.push_front(new_head);

}

void Snake::setDirection(Vector2 direction) {

    if (this->direction.x == (-1 * direction.x) && this->direction.y == (-1 * direction.y)) {
        return;
    }
    this->direction = direction;

}

bool Snake::checkSelfCollision() {

    for (int i = 1; i < snake_body.size(); i++) {
        if (snake_body.front().x == snake_body[i].x && snake_body.front().y == snake_body[i].y) {
            return true;
        }
    }
    return false;

}

void Snake::draw() {

    for (const Vector2& v : snake_body) {
        DrawRectangle(v.x*cell_size, v.y*cell_size, cell_size, cell_size, GREEN);
    }
    DrawRectangle(snake_body.front().x*cell_size, snake_body.front().y*cell_size, cell_size, cell_size, DARKGREEN);

}

void Snake::reset() {

    snake_body.clear();
    snake_body.push_front(Vector2{1, 1});

    setHead(1, 1);

}