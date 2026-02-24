#include "raylib.h"
#include <deque>

class Snake {

    std::deque<Vector2> snake_body;
    Vector2 direction;
    int cell_size = 1;

public:

    void move();
    void grow();
    void setDirection(Vector2 direction);
    bool checkSelfCollision();
    void draw();
    Vector2 getHead() {return snake_body.front();};

};