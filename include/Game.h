#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <memory>

#include "Ball.h"
#include "GameBoundary.h"
#include "GameInput.h"
#include "Paddle.h"
#include "Renderer.h"

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
        std::unique_ptr<GameBoundary> boundary;
        std::unique_ptr<GameInput> input;
        std::unique_ptr<Renderer> renderer;
        int score1;
        int score2;

        void render() const;
        void updatePaddle(const std::unique_ptr<Paddle> &paddle, bool moveUp, bool moveDown, float deltaTime) const;
    };
} // Pong

#endif //PONG_GAME_H