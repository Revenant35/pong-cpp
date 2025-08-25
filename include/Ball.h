#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "Vec2.h"

namespace Pong {
    class Ball {
    public:
        const static float HORIZONTAL_VELOCITY;
        const static float MIN_VERTICAL_VELOCITY;
        const static float MAX_VERTICAL_VELOCITY;

        Ball(const Vec2 &position, const Vec2 &velocity);
        Ball(const Vec2 &position, const Vec2 &velocity, float size);

        float size;
        Vec2 position, velocity;

        void reflectHorizontal();
        void reflectVertical();
    };
} // Pong

#endif //PONG_BALL_H
