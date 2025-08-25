#ifndef PONG_GAME_BOUNDARY_H
#define PONG_GAME_BOUNDARY_H

namespace Pong {
    class GameBoundary {
    public:
        GameBoundary();
        GameBoundary(float height, float width);

        float height, width;
    };
} // Pong

#endif //PONG_GAME_BOUNDARY_H