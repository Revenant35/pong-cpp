#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "Vec2.h"

namespace Pong {
    class Ball {
    public:
        Ball(const Vec2& position, const Vec2& velocity);
        Ball(const Vec2& position, const Vec2& velocity, float radius);

        float radius;
        Vec2 position, velocity;
    };
} // Pong

#endif //PONG_BALL_H