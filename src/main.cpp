#include "Game.h"
#include "Log.h"
#include "Paddle.h"
#include "Vec2.h"
#include "Window.h"

int main() {
    Pong::Log::Init();

    Pong::Log::GetLogger()->set_level(spdlog::level::trace);

    PONG_INFO("Initialized");

    // Pong::Window::CreateWindow("foobar", 800, 600);

    auto game = std::make_unique<Pong::Game>();
    PONG_TRACE("Game created");

    while (game->isRunning) {
        game->update(0.0f);
    }
    return 0;
}
