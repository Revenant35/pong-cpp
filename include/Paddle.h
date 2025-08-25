#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include "Vec2.h"

namespace Pong {
    class Paddle {
    public:
        Paddle(const Vec2 &position);

        Paddle(float height, float width, float velocity, const Vec2 &position);

        float height;
        float width;
        float velocity;
        Vec2 position;

        void update(bool moveUp, bool moveDown, float deltaTime, float minHeight, float maxHeight);

        float getLeft() const;

        float getRight() const;

        float getTop() const;

        float getBottom() const;
    };
} // Pong

#endif //PONG_PADDLE_H
