#include "Ball.h"

Pong::Ball::Ball(const Vec2 &position, const Vec2 &velocity) : Ball(position, velocity, 10.0f) {}

Pong::Ball::Ball(const Vec2 &position, const Vec2 &velocity, const float radius) : position(position), velocity(velocity) {
    this->radius = radius;
}