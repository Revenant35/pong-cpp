#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include "CollisionBox.h"
#include "Vec2.h"

namespace Pong {
    class Paddle {
    public:
        const static float DEFAULT_HEIGHT;
        const static float DEFAULT_WIDTH;

        Paddle(const Vec2 &position);

        CollisionBox getCollisionBox() const;

        Vec2 getPosition() const;
        void setPosition(const Vec2 &newPosition);

        Vec2 getVelocity() const;
        void setVelocity(const Vec2 &newVelocity);

        float getHeight() const;
        float getWidth() const;

    private:
        float height;
        float width;
        CollisionBox collision_box;
        Vec2 position;
        Vec2 velocity;
    };
} // Pong

#endif //PONG_PADDLE_H
