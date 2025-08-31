#include "Ball.h"

const float Pong::Ball::DEFAULT_SIZE = 10.0f;

Pong::Ball::Ball(const Vec2 &position, const Vec2 &velocity)
    : position(position), velocity(velocity), collision_box(DEFAULT_SIZE, DEFAULT_SIZE, position.x, position.y),
      size(DEFAULT_SIZE) {}

Pong::CollisionBox Pong::Ball::getCollisionBox() const {
    return collision_box;
}

Pong::Vec2 Pong::Ball::getPosition() const {
    return position;
}

void Pong::Ball::setPosition(const Vec2 &newPosition) {
    position = newPosition;
    collision_box.x = newPosition.x;
    collision_box.y = newPosition.y;
}

Pong::Vec2 Pong::Ball::getVelocity() const {
    return velocity;
}

void Pong::Ball::setVelocity(const Vec2 &newVelocity) {
    velocity = newVelocity;
}

float Pong::Ball::getSize() const {
    return size;
}
