
#include "Game.h"

#include <SDL.h>

#include "CollisionDetector.h"
#include "Log.h"

Pong::Game::Game() {
    SDL_Init (SDL_INIT_EVERYTHING);

    this->boundary = std::make_unique<GameBoundary>(600.0f, 800.0f);

    this->ball = std::make_unique<Ball>(
        Vec2(400.0f, 300.0f),
        Vec2(200.0f, 200.0f)
    );

    this->player1 = std::make_unique<Paddle>(
        100.0f,
        20.0f,
        300.0f,
        Vec2(50.0f, 250.0f)
    );

    this->player2 = std::make_unique<Paddle>(
        100.0f,
        20.0f,
        300.0f,
        Vec2(730.0f, 250.0f)
    );

    this->input = std::make_unique<GameInput>();

    this->renderer = std::make_unique<Renderer>(800, 600);

    this->score1 = 0;
    this->score2 = 0;
}

Pong::Game::~Game() {
    SDL_Quit();
}

void Pong::Game::update(float delta_time) {
    input->update();

    if (input->isEscapePressed) {
        this->isRunning = false;
    }

    player1->update(input->isPlayer1UpPressed, input->isPlayer1DownPressed, delta_time, 0, boundary->height);
    player2->update(input->isPlayer2UpPressed, input->isPlayer2DownPressed, delta_time, 0, boundary->height);

    ball->position += ball->velocity * delta_time;
    handleBallWallCollisions();
    handleBallPaddleCollisions();

    render();
}


void Pong::Game::render() const {
    renderer->clear();

    renderer->drawPaddle(*player1);
    renderer->drawPaddle(*player2);
    renderer->drawBall(*ball);
    renderer->drawScore(score1, score2);

    renderer->present();
}

void Pong::Game::handleBallWallCollisions() const {
    if (CollisionDetector::isCollidingWithBottomWall(*ball, 0.0f)) {
        ball->position.y = ball->size;
        ball->reflectVertical();
    }

    if (CollisionDetector::isCollidingWithTopWall(*ball, boundary->height)) {
        ball->position.y = boundary->height - ball->size;
        ball->reflectVertical();
    }

    if (CollisionDetector::isCollidingWithLeftWall(*ball, 0.0f)) {
        ball->position.x = ball->size;
        ball->reflectHorizontal();
    }

    if (CollisionDetector::isCollidingWithRightWall(*ball, boundary->width)) {
        ball->position.x = boundary->width - ball->size;
        ball->reflectHorizontal();
    }
}

// TODO: Change circle to be square
// TODO: Update AABB collision detection

void Pong::Game::handleBallPadsdleCollisions() const {
    if (CollisionDetector::isColliding(*player1, *ball)) {
        ball->position.x = player1->getRight();
        ball->reflectHorizontal();
        const float hitPosition = (ball->position.y - player1->position.y) / (player1->height / 2.0f);
        ball->velocity.y = std::clamp(ball->velocity.y + hitPosition * 150.0f, Ball::MIN_VERTICAL_VELOCITY, Ball::MAX_VERTICAL_VELOCITY);
    }

    if (CollisionDetector::isColliding(*player2, *ball)) {
        ball->position.x = player2->getLeft();
        ball->reflectHorizontal();
        const float hitPosition = (ball->position.y - player2->position.y) / (player2->height / 2.0f);
        ball->velocity.y = std::clamp(ball->velocity.y + hitPosition * 150.0f, Ball::MIN_VERTICAL_VELOCITY, Ball::MAX_VERTICAL_VELOCITY);
    }
}
