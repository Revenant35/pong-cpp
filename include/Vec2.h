#ifndef PONG_VEC2_H
#define PONG_VEC2_H

namespace Pong {
    struct Vec2 {
        static Vec2 Zero();

        Vec2(float x, float y);

        float x, y;
        float magnitude() const;

        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        Vec2 operator*(float scalar) const;
        Vec2 operator/(float scalar) const;
        Vec2& operator+=(const Vec2& other);
        Vec2& operator-=(const Vec2& other);
        Vec2& operator*=(float scalar);
        Vec2& operator/=(float scalar);
    };
} // Pong

#endif //PONG_VEC2_H