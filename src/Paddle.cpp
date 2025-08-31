#include "Paddle.h"

const float Pong::Paddle::DEFAULT_HEIGHT = 100.0f;
const float Pong::Paddle::DEFAULT_WIDTH = 20.0f;

Pong::Paddle::Paddle(const Vec2 &position) :
    collision_box(DEFAULT_HEIGHT, DEFAULT_WIDTH, position.x, position.y),
    position(position),
    velocity(Vec2::Zero()){
    this->height = DEFAULT_HEIGHT;
    this->width = DEFAULT_WIDTH;
}

Pong::CollisionBox Pong::Paddle::getCollisionBox() const {
    return collision_box;
}

Pong::Vec2 Pong::Paddle::getPosition() const {
    return position;
}

void Pong::Paddle::setPosition(const Vec2 &newPosition) {
    position = newPosition;
    collision_box.x = newPosition.x;
    collision_box.y = newPosition.y;
}

Pong::Vec2 Pong::Paddle::getVelocity() const {
    return velocity;
}

void Pong::Paddle::setVelocity(const Vec2 &newVelocity) {
    velocity = newVelocity;
}

float Pong::Paddle::getHeight() const {
    return height;
}

float Pong::Paddle::getWidth() const {
    return width;
}
