#include "Game.h"

#include <SDL.h>

#include "Log.h"

Pong::Game::Game() : ball(
                         Vec2(400.0f, 300.0f),
                         Vec2(200.0f, 200.0f)
                     ),
                     player1(
                         Vec2(50.0f, 250.0f)
                     ),
                     player2(
                         Vec2(730.0f, 250.0f)
                     ),
                     renderer(800, 600) {
    SDL_Init(SDL_INIT_EVERYTHING);

    this->score1 = 0;
    this->score2 = 0;
}

Pong::Game::~Game() {
    SDL_Quit();
}

void Pong::Game::update(const float delta_time) {
    input.update();

    if (input.isEscapePressed) {
        this->isRunning = false;
    }

    updatePaddles(delta_time);
    ball.setPosition(ball.getPosition() + ball.getVelocity() * delta_time);

    handleBallWallCollisions();
    handleBallPaddleCollisions(player1);
    handleBallPaddleCollisions(player2);

    render();
}


void Pong::Game::render() const {
    renderer.clear();

    renderer.drawPaddle(player1);
    renderer.drawPaddle(player2);
    renderer.drawBall(ball);
    renderer.drawScore(score1, score2);

    renderer.present();
}

void Pong::Game::handleBallWallCollisions() {
    if (boundary.isCollidingWithTopWall(ball.getCollisionBox())) {
        auto ballPosition = ball.getPosition();
        ballPosition.y = boundary.getHeight() - ball.getSize();
        ball.setPosition(ballPosition);

        auto ballVelocity = ball.getVelocity();
        ballVelocity.y = -ballVelocity.y;
        ball.setVelocity(ballVelocity);
    }

    if (boundary.isCollidingWithBottomWall(ball.getCollisionBox())) {
        auto ballPosition = ball.getPosition();
        ballPosition.y = ball.getSize();
        ball.setPosition(ballPosition);

        auto ballVelocity = ball.getVelocity();
        ballVelocity.y = -ballVelocity.y;
        ball.setVelocity(ballVelocity);
    }

    if (boundary.isCollidingWithLeftWall(ball.getCollisionBox())) {
        auto ballPosition = ball.getPosition();
        ballPosition.x = ball.getSize();
        ball.setPosition(ballPosition);

        auto ballVelocity = ball.getVelocity();
        ballVelocity.x = -ballVelocity.x;
        ball.setVelocity(ballVelocity);
    }

    if (boundary.isCollidingWithRightWall(ball.getCollisionBox())) {
        auto ballPosition = ball.getPosition();
        ballPosition.x = boundary.getWidth() - ball.getSize();
        ball.setPosition(ballPosition);

        auto ballVelocity = ball.getVelocity();
        ballVelocity.x = -ballVelocity.x;
        ball.setVelocity(ballVelocity);
    }
}

void Pong::Game::handleBallPaddleCollisions(const Paddle& paddle) {
    if (ball.getCollisionBox().overlaps(paddle.getCollisionBox())) {
        // TODO: Find closest side of paddle, and "reflect" ball off of it.
        auto ballPosition = ball.getPosition();
        ballPosition.x = ball.getSize();
        ball.setPosition(ballPosition);

        auto ballVelocity = ball.getVelocity();
        ballVelocity.x = -ballVelocity.x;
        ball.setVelocity(ballVelocity);
    }
}

void Pong::Game::updatePaddles(const float deltaTime) {
    if (!input.isPlayer1UpPressed && input.isPlayer1DownPressed) {
        auto position = player1.getPosition();
        const auto desiredHeight = position.y + 300.0f * deltaTime;
        const auto maxHeight = boundary.getHeight() - player1.getHeight() / 2;
        position.y = std::min(desiredHeight, maxHeight);
        player1.setPosition(position);
    }

    if (input.isPlayer1UpPressed && !input.isPlayer1DownPressed) {
        auto position = player1.getPosition();
        const auto desiredHeight = position.y - 300.0f * deltaTime;
        const auto minHeight = player1.getHeight() / 2;
        position.y = std::max(desiredHeight, minHeight);
        player1.setPosition(position);
    }

    if (!input.isPlayer2UpPressed && input.isPlayer2DownPressed) {
        auto position = player2.getPosition();
        const auto desiredHeight = position.y + 300.0f * deltaTime;
        const auto maxHeight = boundary.getHeight() - player2.getHeight() / 2;
        position.y = std::min(desiredHeight, maxHeight);
        player2.setPosition(position);
    }

    if (input.isPlayer2UpPressed && !input.isPlayer2DownPressed) {
        auto position = player2.getPosition();
        const auto desiredHeight = position.y - 300.0f * deltaTime;
        const auto minHeight = player2.getHeight() / 2;
        position.y = std::max(desiredHeight, minHeight);
        player2.setPosition(position);
    }
}
