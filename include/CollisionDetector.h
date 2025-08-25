#ifndef PONG_COLLISION_DETECTOR_H
#define PONG_COLLISION_DETECTOR_H

#include "Ball.h"
#include "Paddle.h"

namespace Pong {
    class CollisionDetector {
    public:
        static bool isColliding(const Paddle &box, const Ball &circle);

        static bool isCollidingWithBottomWall(const Ball &circle, float bottomY);

        static bool isCollidingWithTopWall(const Ball &circle, float topY);

        static bool isCollidingWithLeftWall(const Ball &circle, float leftX);

        static bool isCollidingWithRightWall(const Ball &circle, float rightX);
    };
} // Pong


#endif //PONG_COLLISION_DETECTOR_H
