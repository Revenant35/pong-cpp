#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include "Vec2.h"

namespace Pong {
    class Paddle {
    public:
        Paddle(
            const Vec2& position
        );

        Paddle(
            float height,
            float width,
            float velocity,
            const Vec2& position
        );

        float height;
        float width;
        float velocity;
        Vec2 position;
    };
} // Pong

#endif //PONG_PADDLE_H