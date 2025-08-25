#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <memory>

#include "Ball.h"
#include "GameInput.h"
#include "Paddle.h"

namespace Pong {
    class Game {
    public:
        Game();
        ~Game();

        bool isRunning = true;

        void update(float delta_time);
    private:
        std::unique_ptr<Ball> ball;
        std::unique_ptr<Paddle> player1;
        std::unique_ptr<Paddle> player2;
        std::unique_ptr<GameInput> input;
        int score1;
        int score2;
    };
} // Pong

#endif //PONG_GAME_H