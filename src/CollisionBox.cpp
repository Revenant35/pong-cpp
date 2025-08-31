#include "CollisionBox.h"


bool Pong::CollisionBox::contains(const CollisionBox &box, const Vec2 &point) {
    return point.x >= box.getLeft() && point.x <= box.getRight() &&
           point.y >= box.getBottom() && point.y <= box.getTop();
}

bool Pong::CollisionBox::contains(const CollisionBox &box, const CollisionBox &other) {
    return other.getLeft() >= box.getLeft() &&
           other.getRight() <= box.getRight() &&
           other.getBottom() >= box.getBottom() &&
           other.getTop() <= box.getTop();
}

bool Pong::CollisionBox::overlaps(const CollisionBox &a, const CollisionBox &b) {
    const bool noOverlap =
        a.getRight() < b.getLeft() ||
        a.getLeft() > b.getRight() ||
        a.getTop() < b.getBottom() ||
        a.getBottom() > b.getTop();

    return !noOverlap;
}

Pong::CollisionBox::CollisionBox(const float height, const float width, const Vec2 &position) :
    CollisionBox(height, width, position.x, position.y) {}

Pong::CollisionBox::CollisionBox(const float height, const float width, const float x, const float y) {
    this->height = height;
    this->width = width;
    this->x = x;
    this->y = y;
}

bool Pong::CollisionBox::contains(const Vec2 &point) const {
    return contains(*this, point);
}

bool Pong::CollisionBox::contains(const CollisionBox &other) const {
    return contains(*this, other);
}

bool Pong::CollisionBox::overlaps(const CollisionBox &other) const {
    return overlaps(*this, other);
}

float Pong::CollisionBox::getLeft() const {
    return x - width / 2.0f;
}

float Pong::CollisionBox::getRight() const {
    return x + width / 2.0f;
}

float Pong::CollisionBox::getTop() const {
    return y + height / 2.0f;
}

float Pong::CollisionBox::getBottom() const {
    return y - height / 2.0f;
}

std::array<Pong::Vec2, 4> Pong::CollisionBox::getCorners() const {
    const auto left = getLeft();
    const auto right = getRight();
    const auto top = getTop();
    const auto bottom = getBottom();

    return {
        Vec2{left, top},
        Vec2{right, top},
        Vec2{left, bottom},
        Vec2{right, bottom}
    };
}
