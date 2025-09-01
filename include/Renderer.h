#ifndef PONG_RENDERER_H
#define PONG_RENDERER_H

#include <SDL.h>
#include <SDL_ttf.h>

#include "Ball.h"
#include "Paddle.h"

namespace Pong {
    class Renderer {
    public:
        Renderer(int width, int height);
        ~Renderer();

        void clear() const;
        void present() const;
        void drawPaddle(const Paddle& paddle) const;
        void drawBall(const Ball& ball) const;
        void drawScore(int score1, int score2) const;
        void drawCenterLine() const;

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        TTF_Font* font;
        int windowWidth;
        int windowHeight;
    };
} // Pong

#endif //PONG_RENDERER_H