#ifndef PONG_COLLISION_BOX_H
#define PONG_COLLISION_BOX_H

#include <array>

#include "Vec2.h"

namespace Pong {
    class CollisionBox {
    public:
        float height, width, x, y;

        static bool contains(const CollisionBox &box, const Vec2 &point);
        static bool contains(const CollisionBox &box, const CollisionBox &other);
        static bool overlaps(const CollisionBox &a, const CollisionBox &b);

        CollisionBox(float height, float width, const Vec2 &position);
        CollisionBox(float height, float width, float x, float y);

        bool contains(const Vec2 &point) const;
        bool contains(const CollisionBox &other) const;
        bool overlaps(const CollisionBox &other) const;
    private:
        float getLeft() const;
        float getRight() const;
        float getTop() const;
        float getBottom() const;
        std::array<Vec2, 4> getCorners() const;
    };
} // Pong

#endif //PONG_COLLISION_BOX_H