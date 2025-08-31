#ifndef PONG_GAME_BOUNDARY_H
#define PONG_GAME_BOUNDARY_H

#include "CollisionBox.h"

namespace Pong {
    class GameBoundary {
    public:
        const static float DEFAULT_HEIGHT;
        const static float DEFAULT_WIDTH;

        GameBoundary();

        float getHeight() const;
        float getWidth() const;

        bool isCollidingWithTopWall(const CollisionBox &box) const;
        bool isCollidingWithBottomWall(const CollisionBox &box) const;
        bool isCollidingWithLeftWall(const CollisionBox &box) const;
        bool isCollidingWithRightWall(const CollisionBox &box) const;
    private:
        float height, width;
        CollisionBox top_wall;
        CollisionBox bottom_wall;
        CollisionBox left_wall;
        CollisionBox right_wall;
    };
} // Pong

#endif //PONG_GAME_BOUNDARY_H