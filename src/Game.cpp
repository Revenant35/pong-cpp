
#include "Game.h"

#include <SDL.h>

#include "Log.h"

Pong::Game::Game() {
    SDL_Init (SDL_INIT_EVERYTHING);

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

    if (input->isPlayer1UpPressed) {
        player1->position.y -= player1->velocity * delta_time;
    }
    if (input->isPlayer1DownPressed) {
        player1->position.y += player1->velocity * delta_time;
    }

    if (input->isPlayer2UpPressed) {
        player2->position.y -= player2->velocity * delta_time;
    }
    if (input->isPlayer2DownPressed) {
        player2->position.y += player2->velocity * delta_time;
    }

    ball->position += ball->velocity * delta_time;
}
