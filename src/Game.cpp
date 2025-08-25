
#include "Game.h"

#include <SDL.h>

#include "Log.h"

namespace Pong {
    class GameBoundary;
}

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