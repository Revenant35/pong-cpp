#include "GameBoundary.h"

Pong::GameBoundary::GameBoundary(const float height, const float width) {
    this->height = height;
    this->width = width;
}

Pong::GameBoundary::GameBoundary() : height(600), width(800) {

}
