
#include "Game.h"

Pong::Game::Game() {
    this->ball = std::make_unique<Ball>(
        Vec2(400.0f, 300.0f),
        Vec2(200.0f, 200.0f)
    );

    this->player_1 = std::make_unique<Paddle>(
        100.0f,
        20.0f,
        300.0f,
        Vec2(50.0f, 250.0f)
    );

    this->player_2 = std::make_unique<Paddle>(
        100.0f,
        20.0f,
        300.0f,
        Vec2(730.0f, 250.0f)
    );

    this->score_1 = 0;
    this->score_2 = 0;
}

void Pong::Game::update(float delta_time) {


}
