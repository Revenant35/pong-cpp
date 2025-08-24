#ifndef PONG_WINDOW_H
#define PONG_WINDOW_H

#include <SDL_video.h>

namespace Pong {
    class Window {
    public:
        static SDL_Window * CreateWindow(const char* title, int width, int height);
        static void DestroyWindow(SDL_Window* window);
    };
}

#endif //PONG_WINDOW_H