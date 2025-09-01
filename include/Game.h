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
        Ball ball;
        Paddle player1;
        Paddle player2;
        GameBoundary boundary;
        GameInput input;
        Renderer renderer;
        int score1;
        int score2;

        void render() const;
        void handleBallWallCollisions();
        void handleBallPaddleCollisions(const Paddle& paddle);
        void resetPositions();

        void updatePaddles(float deltaTime);
    };
} // Pong

#endif //PONG_GAME_H