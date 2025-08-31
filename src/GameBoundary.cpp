#include "GameBoundary.h"

const float Pong::GameBoundary::DEFAULT_HEIGHT = 600.0f;
const float Pong::GameBoundary::DEFAULT_WIDTH = 800.0f;

Pong::GameBoundary::GameBoundary() :
    top_wall(10.0f, DEFAULT_WIDTH, Vec2(DEFAULT_WIDTH / 2.0f, DEFAULT_HEIGHT + 5.0f)),
    bottom_wall(10.0f, DEFAULT_WIDTH, Vec2(DEFAULT_WIDTH / 2.0f, -5.0f)),
    left_wall(DEFAULT_HEIGHT, 10.0f, Vec2(-5.0f, DEFAULT_HEIGHT / 2.0f)),
    right_wall(DEFAULT_HEIGHT, 10.0f, Vec2(DEFAULT_WIDTH + 5.0f, DEFAULT_HEIGHT / 2.0f)) {
    this->height = DEFAULT_HEIGHT;
    this->width = DEFAULT_WIDTH;
}

float Pong::GameBoundary::getHeight() const {
    return height;
}

float Pong::GameBoundary::getWidth() const {
    return width;
}

bool Pong::GameBoundary::isCollidingWithTopWall(const CollisionBox &box) const {
    return top_wall.overlaps(box);
}

bool Pong::GameBoundary::isCollidingWithBottomWall(const CollisionBox &box) const {
    return bottom_wall.overlaps(box);
}

bool Pong::GameBoundary::isCollidingWithLeftWall(const CollisionBox &box) const {
    return left_wall.overlaps(box);
}

bool Pong::GameBoundary::isCollidingWithRightWall(const CollisionBox &box) const {
    return right_wall.overlaps(box);
}

