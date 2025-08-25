#include "Paddle.h"

#include <algorithm>

Pong::Paddle::Paddle(const float height, const float width, const float velocity, const Vec2& position) : position(position) {
    this->height = height;
    this->width = width;
    this->velocity = velocity;
}

Pong::Paddle::Paddle(const Vec2& position) : Paddle(100.0f, 20.0f, 300.0f, position) {}

void Pong::Paddle::update(
    const bool moveUp,
    const bool moveDown,
    const float deltaTime,
    const float minHeight,
    const float maxHeight
) {
    if ((moveUp && moveDown) || (!moveUp && !moveDown)) {
        return;
    }

    if (moveUp) {
        const auto newPosition = position.y - velocity * deltaTime;
        position.y = std::max(minHeight + height / 2, newPosition);
    } else {
        const auto newPosition = position.y + velocity * deltaTime;
        position.y = std::min(maxHeight - height / 2, newPosition);
    }
}
