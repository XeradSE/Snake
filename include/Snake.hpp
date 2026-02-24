#include "raylib.h"
#include <deque>

class Snake {

    const int cell_size = 60;
    std::deque<Vector2> snake_body;
    Vector2 direction;

public:

    void move();
    void grow();
    void setDirection(Vector2 direction);
    bool checkSelfCollision();
    void draw();
    Vector2 getHead() const {return snake_body.front();};

};