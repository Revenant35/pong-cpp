#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <memory>

#include "Ball.h"
#include "Paddle.h"

namespace Pong {
    class Game {
    public:
        Game();

        void update(float delta_time);
    private:
        std::unique_ptr<Ball> ball;
        std::unique_ptr<Paddle> player_1;
        std::unique_ptr<Paddle> player_2;
        int score_1;
        int score_2;
    };
} // Pong

#endif //PONG_GAME_H