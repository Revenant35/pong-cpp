#include "GameInput.h"
#include "Log.h"

#include <SDL_events.h>

Pong::GameInput::GameInput() {
    this->isPlayer1UpPressed = false;
    this->isPlayer1DownPressed = false;
    this->isPlayer2UpPressed = false;
    this->isPlayer2DownPressed = false;
    this->isEscapePressed = false;
}

void Pong::GameInput::update() {
    SDL_Event event;

    while( SDL_PollEvent( &event ) ){
        switch( event.type ){
            case SDL_KEYDOWN:
                this->handleKeydownEvent(event.key);
                break;

            case SDL_KEYUP:
                this->handleKeyupEvent(event.key);
                break;

            default:
                break;
        }
    }
}

void Pong::GameInput::handleKeydownEvent(const SDL_KeyboardEvent& event) {
    switch (event.keysym.scancode) {
        case SDL_SCANCODE_UP:
            if (!this->isPlayer1UpPressed) {
                this->isPlayer1UpPressed = true;
                PONG_TRACE("Player 1 up pressed");
            }
            break;
        case SDL_SCANCODE_DOWN:
            if (!this->isPlayer1DownPressed) {
                this->isPlayer1DownPressed = true;
                PONG_TRACE("Player 1 down pressed");
            }
            break;
        case SDL_SCANCODE_W:
            if (!this->isPlayer2UpPressed) {
                this->isPlayer2UpPressed = true;
                PONG_TRACE("Player 2 up pressed");
            }
            break;
        case SDL_SCANCODE_S:
            if (!this->isPlayer2DownPressed) {
                this->isPlayer2DownPressed = true;
                PONG_TRACE("Player 2 down pressed");
            }
            break;
        case SDL_SCANCODE_ESCAPE:
            if (!this->isEscapePressed) {
                this->isEscapePressed = true;
                PONG_TRACE("Escape pressed");
            }
            break;
        default:
            break;
    }
}


void Pong::GameInput::handleKeyupEvent(const SDL_KeyboardEvent& event) {
    switch (event.keysym.scancode) {
        case SDL_SCANCODE_UP:
            if (this->isPlayer1UpPressed) {
                this->isPlayer1UpPressed = false;
                PONG_TRACE("Player 1 up released");
            }
            break;
        case SDL_SCANCODE_DOWN:
            if (this->isPlayer1DownPressed) {
                this->isPlayer1DownPressed = false;
                PONG_TRACE("Player 1 down released");
            }
            break;
        case SDL_SCANCODE_W:
            if (this->isPlayer2UpPressed) {
                this->isPlayer2UpPressed = false;
                PONG_TRACE("Player 2 up released");
            }
            break;
        case SDL_SCANCODE_S:
            if (this->isPlayer2DownPressed) {
                this->isPlayer2DownPressed = false;
                PONG_TRACE("Player 2 down released");
            }
            break;
        case SDL_SCANCODE_ESCAPE:
            if (this->isEscapePressed) {
                this->isEscapePressed = false;
                PONG_TRACE("Escape released");
            }
            break;
        default:
            break;
    }
}
