#include "Paddle.h"

Pong::Paddle::Paddle(const float height, const float width, const float velocity, const Vec2& position) : position(position) {
    this->height = height;
    this->width = width;
    this->velocity = velocity;
}

Pong::Paddle::Paddle(const Vec2& position) : Paddle(100.0f, 20.0f, 300.0f, position) {}
