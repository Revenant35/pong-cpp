#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "Vec2.h"
#include "CollisionBox.h"

namespace Pong {
    class Ball {
    public:
        const static float DEFAULT_SIZE;

        Ball(const Vec2 &position, const Vec2 &velocity);

        CollisionBox getCollisionBox() const;

        Vec2 getPosition() const;
        void setPosition(const Vec2 &newPosition);

        Vec2 getVelocity() const;
        void setVelocity(const Vec2 &newVelocity);

        float getSize() const;
    private:
        Vec2 position;
        Vec2 velocity;
        CollisionBox collision_box;
        float size;
    };
} // Pong

#endif //PONG_BALL_H
