#ifndef PONG_INPUT_H
#define PONG_INPUT_H

#include <SDL_events.h>

namespace Pong {
    class GameInput {
    public:
        GameInput();

        bool isPlayer1UpPressed;
        bool isPlayer1DownPressed;
        bool isPlayer2UpPressed;
        bool isPlayer2DownPressed;
        bool isEscapePressed;

        void update();
    private:
        void handleKeydownEvent(const SDL_KeyboardEvent& event);
        void handleKeyupEvent(const SDL_KeyboardEvent& event);
    };
} // Pong

#endif //PONG_INPUT_H