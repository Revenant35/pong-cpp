#include "Renderer.h"
#include "Log.h"

Pong::Renderer::Renderer(const int width, const int height) {
    this->windowWidth = width;
    this->windowHeight = height;

    // Create window
    window = SDL_CreateWindow(
        "Pong",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        PONG_ERROR("Failed to create window: {}", SDL_GetError());
        return;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == nullptr) {
        PONG_ERROR("Failed to create renderer: {}", SDL_GetError());
        return;
    }
}

Pong::Renderer::~Renderer() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

void Pong::Renderer::clear() const {
    // Set background color (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Pong::Renderer::present() const {
    SDL_RenderPresent(renderer);
}

void Pong::Renderer::drawPaddle(const Paddle& paddle) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White

    SDL_Rect rect = {
        static_cast<int>(paddle.position.x - paddle.width/2),
        static_cast<int>(paddle.position.y - paddle.height/2),
        static_cast<int>(paddle.width),
        static_cast<int>(paddle.height)
    };

    SDL_RenderFillRect(renderer, &rect);
}

void Pong::Renderer::drawBall(const Ball& ball) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White

    // For a proper circle, you'd need a more complex algorithm
    // This is a simplified version using a filled square
    int radius = 10; // You might want to add radius to Ball class

    SDL_Rect rect = {
        static_cast<int>(ball.position.x - radius),
        static_cast<int>(ball.position.y - radius),
        radius * 2,
        radius * 2
    };

    SDL_RenderFillRect(renderer, &rect);
}

void Pong::Renderer::drawScore(const int score1, const int score2) const {
    // For basic score display, you'd typically use SDL_ttf
    // This is placeholder code - you'll need to implement text rendering
    // with SDL_ttf library for proper text display

    // For now just draw rectangles to represent scores
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Draw score1 indicators
    for (int i = 0; i < score1; i++) {
        SDL_Rect rect = {20 + i*15, 20, 10, 10};
        SDL_RenderFillRect(renderer, &rect);
    }

    // Draw score2 indicators
    for (int i = 0; i < score2; i++) {
        SDL_Rect rect = {windowWidth - 30 - i*15, 20, 10, 10};
        SDL_RenderFillRect(renderer, &rect);
    }
}
