#include "Game.h"
#include "Log.h"

int main() {
    Pong::Log::Init();

    Pong::Log::GetLogger()->set_level(spdlog::level::trace);

    PONG_INFO("Initialized");

    auto game = std::make_unique<Pong::Game>();
    PONG_TRACE("Game created");

    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double deltaTime = 0;

    while (game->isRunning) {
        // Calculate delta time
        last = now;
        now = SDL_GetPerformanceCounter();

        // Convert to seconds
        deltaTime = ((now - last) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency())) / 1000.0;

        // Cap delta time to prevent physics issues during debugging/breakpoints
        if (deltaTime > 0.05)
            deltaTime = 0.05;

        // Update game with calculated delta time
        game->update(static_cast<float>(deltaTime));
    }
    return 0;
}
