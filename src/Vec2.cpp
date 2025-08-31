#include <cmath>
#include "Vec2.h"

Pong::Vec2 Pong::Vec2::Zero() {
    return Vec2(0.0f, 0.0f);
}

Pong::Vec2::Vec2(const float x, const float y) {
    this->x = x;
    this->y = y;
}

float Pong::Vec2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Pong::Vec2 Pong::Vec2::operator+(const Vec2 &other) const {
    return Vec2(x + other.x, y + other.y);
}

Pong::Vec2 Pong::Vec2::operator-(const Vec2 &other) const {
    return Vec2(x - other.x, y - other.y);
}

Pong::Vec2 Pong::Vec2::operator*(const float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Pong::Vec2 Pong::Vec2::operator/(const float scalar) const {
    return Vec2(x / scalar, y / scalar);
}

Pong::Vec2 &Pong::Vec2::operator+=(const Vec2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Pong::Vec2 &Pong::Vec2::operator-=(const Vec2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Pong::Vec2 &Pong::Vec2::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Pong::Vec2 &Pong::Vec2::operator/=(const float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}
