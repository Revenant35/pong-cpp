#include "Ball.h"


const float Pong::Ball::HORIZONTAL_VELOCITY = 40.0f;
const float Pong::Ball::MIN_VERTICAL_VELOCITY = -300.0f;
const float Pong::Ball::MAX_VERTICAL_VELOCITY = 300.0f;

Pong::Ball::Ball(const Vec2 &position, const Vec2 &velocity) : Ball(position, velocity, 20.0f) {}

Pong::Ball::Ball(const Vec2 &position, const Vec2 &velocity, const float size) : position(position), velocity(velocity) {
    this->size = size;
}

void Pong::Ball::reflectHorizontal() {
    velocity.x = -velocity.x;
}

void Pong::Ball::reflectVertical() {
    velocity.y = -velocity.y;
}
