#include "CollisionDetector.h"

#include <algorithm>

bool Pong::CollisionDetector::isColliding(const Paddle &box, const Ball &circle) {
    const float closestX = std::clamp(circle.position.x, box.getLeft(), box.getRight());
    const float closestY = std::clamp(circle.position.y, box.getTop(), box.getBottom());

    const float dx = circle.position.x - closestX;
    const float dy = circle.position.y - closestY;

    return dx * dx + dy * dy <= circle.size * circle.size;
}

bool Pong::CollisionDetector::isCollidingWithBottomWall(const Ball &circle, const float bottomY) {
    return (circle.position.y - circle.size) <= bottomY;
}

bool Pong::CollisionDetector::isCollidingWithTopWall(const Ball &circle, const float topY) {
    return (circle.position.y + circle.size) >= topY;
}

bool Pong::CollisionDetector::isCollidingWithLeftWall(const Ball &circle, const float leftX) {
    return (circle.position.x - circle.size) <= leftX;
}

bool Pong::CollisionDetector::isCollidingWithRightWall(const Ball &circle, const float rightX) {
    return (circle.position.x + circle.size) >= rightX;
}
