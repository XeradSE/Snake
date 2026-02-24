#include "./../include/Snake.hpp"
#include "raylib.h"

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

    for (Vector2 v : snake_body) {
        if (snake_body.front().x == v.x && snake_body.front().y == v.y) {
            return true;
        }
    }

    return false;

}

void Snake::draw() {

    

}