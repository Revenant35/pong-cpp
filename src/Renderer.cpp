#include "Renderer.h"
#include "Log.h"
#include <string>

Pong::Renderer::Renderer(const int width, const int height) : font(nullptr) {
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
    
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        PONG_ERROR("Failed to initialize SDL_ttf: {}", TTF_GetError());
        return;
    }
    
    // Try to load fonts from common macOS system locations
    const char* fontPaths[] = {
        "/System/Library/Fonts/Helvetica.ttc",
        "/System/Library/Fonts/Supplemental/Arial.ttf",
        "/System/Library/Fonts/SF-Pro-Display-Regular.otf",
        "/Library/Fonts/Arial.ttf",
        "/Library/Fonts/Courier New.ttf",
        "/System/Library/Fonts/Supplemental/Courier New.ttf",
        "/System/Library/Fonts/Monaco.ttf",
        "/System/Library/Fonts/AppleGothic.ttf",
        "/System/Library/Fonts/SFNSMono.ttf"
    };
    
    const int numFonts = sizeof(fontPaths) / sizeof(fontPaths[0]);
    for (int i = 0; i < numFonts; i++) {
        font = TTF_OpenFont(fontPaths[i], 28); // Increased size for better visibility
        if (font != nullptr) {
            PONG_ERROR("Loaded font: {}", fontPaths[i]);
            break;
        }
    }
    
    if (font == nullptr) {
        PONG_ERROR("Failed to load any fonts: {}", TTF_GetError());
        // Continue without font - we'll fall back to the original score display method
    }
}

Pong::Renderer::~Renderer() {
    if (font != nullptr) {
        TTF_CloseFont(font);
    }
    
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    
    TTF_Quit();
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
    const auto position = paddle.getPosition();
    const auto height = paddle.getHeight();
    const auto width = paddle.getWidth();

    const SDL_Rect rect = {
        static_cast<int>(position.x - width/2),
        static_cast<int>(position.y - height/2),
        static_cast<int>(width),
        static_cast<int>(height)
    };

    SDL_RenderFillRect(renderer, &rect);
}

void Pong::Renderer::drawBall(const Ball& ball) const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White
    const auto position = ball.getPosition();
    const auto size = ball.getSize();

    const SDL_Rect rect = {
        static_cast<int>(position.x - size / 2),
        static_cast<int>(position.y - size / 2),
        static_cast<int>(size),
        static_cast<int>(size)
    };

    SDL_RenderFillRect(renderer, &rect);
}

void Pong::Renderer::drawScore(const int score1, const int score2) const {
    // Set text color to white
    SDL_Color textColor = {255, 255, 255, 255};
    
    if (font != nullptr) {
        // Convert scores to strings
        std::string score1Text = std::to_string(score1);
        std::string score2Text = std::to_string(score2);
        
        // Render score1 text
        SDL_Surface* textSurface1 = TTF_RenderText_Solid(font, score1Text.c_str(), textColor);
        if (textSurface1 != nullptr) {
            SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(renderer, textSurface1);
            if (textTexture1 != nullptr) {
                int textWidth1 = textSurface1->w;
                int textHeight1 = textSurface1->h;
                
                // Position score1 on left side
                SDL_Rect renderRect1 = {50, 30, textWidth1, textHeight1};
                SDL_RenderCopy(renderer, textTexture1, nullptr, &renderRect1);
                
                SDL_DestroyTexture(textTexture1);
            }
            SDL_FreeSurface(textSurface1);
        }
        
        // Render score2 text
        SDL_Surface* textSurface2 = TTF_RenderText_Solid(font, score2Text.c_str(), textColor);
        if (textSurface2 != nullptr) {
            SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(renderer, textSurface2);
            if (textTexture2 != nullptr) {
                int textWidth2 = textSurface2->w;
                int textHeight2 = textSurface2->h;
                
                // Position score2 on right side
                SDL_Rect renderRect2 = {windowWidth - 50 - textWidth2, 30, textWidth2, textHeight2};
                SDL_RenderCopy(renderer, textTexture2, nullptr, &renderRect2);
                
                SDL_DestroyTexture(textTexture2);
            }
            SDL_FreeSurface(textSurface2);
        }
    } else {
        // Fallback to drawing rectangles if font loading failed
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
}

void Pong::Renderer::drawCenterLine() const {
    // Set drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Define parameters for the dotted line
    const int centerX1 = windowWidth / 2 - 2;
    const int centerX2 = windowWidth / 2 + 2;
    const int dashLength = 30;
    const int gapLength = 10;
    const int combinedLength = dashLength + gapLength;
    
    // Draw dashed line from top to bottom
    for (int y = windowHeight; y > 0; y -= combinedLength) {
        // const int endY = std::max(y - dashLength, 0);

        const auto rect = SDL_Rect{
            centerX1,
            y,
            4,
            dashLength
        };
        
        SDL_RenderDrawRect(
            renderer,
            &rect
        );
    }
}
