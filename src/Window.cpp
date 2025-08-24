
#include "Window.h"
#include <SDL2/SDL.h>

void init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // std::cout << "Failed to initialize the SDL2 library\n";
        // return -1;
    }
}

SDL_Window * Pong::Window::CreateWindow(const char *title, int width, int height) {
    return SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
        );
}

void Pong::Window::DestroyWindow(SDL_Window *window) {
    SDL_DestroyWindow(window);
}