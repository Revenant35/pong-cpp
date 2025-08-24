#include "Log.h"

int main() {
    Pong::Log::Init();

    PONG_INFO("Initialized");
    return 0;
}
