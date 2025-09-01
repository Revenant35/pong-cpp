#include "Game.h"

#include <SDL.h>

#include "Log.h"

Pong::Game::Game() : ball(
                         Vec2(400.0f, 300.0f),
                         Vec2(200.0f, 200.0f)
                     ),
                     player1(
                         Vec2(50.0f, 250.0f)
                     ),
                     player2(
                         Vec2(730.0f, 250.0f)
                     ),
                     renderer(800, 600) {
    SDL_Init(SDL_INIT_EVERYTHING);

    this->score1 = 0;
    this->score2 = 0;
}

Pong::Game::~Game() {
    SDL_Quit();
}

void Pong::Game::update(const float delta_time) {
    input.update();

    if (input.isEscapePressed) {
        this->isRunning = false;
    }

    updatePaddles(delta_time);
    ball.setPosition(ball.getPosition() + ball.getVelocity() * delta_time);

    handleBallWallCollisions();
    handleBallPaddleCollisions(player1);
    handleBallPaddleCollisions(player2);

    render();
}


void Pong::Game::render() const {
    renderer.clear();

    renderer.drawCenterLine();
    renderer.drawPaddle(player1);
    renderer.drawPaddle(player2);
    renderer.drawBall(ball);
    renderer.drawScore(score1, score2);

    renderer.present();
}

void Pong::Game::handleBallWallCollisions() {
    if (boundary.isCollidingWithTopWall(ball.getCollisionBox())) {
        auto ballPosition = ball.getPosition();
        ballPosition.y = boundary.getHeight() - ball.getSize();
        ball.setPosition(ballPosition);

        auto ballVelocity = ball.getVelocity();
        ballVelocity.y = -ballVelocity.y;
        ball.setVelocity(ballVelocity);
    }

    if (boundary.isCollidingWithBottomWall(ball.getCollisionBox())) {
        auto ballPosition = ball.getPosition();
        ballPosition.y = ball.getSize();
        ball.setPosition(ballPosition);

        auto ballVelocity = ball.getVelocity();
        ballVelocity.y = -ballVelocity.y;
        ball.setVelocity(ballVelocity);
    }

    // Player 2 scores (ball hits left wall)
    if (boundary.isCollidingWithLeftWall(ball.getCollisionBox())) {
        score2++;
        resetPositions();
    }

    // Player 1 scores (ball hits right wall)
    if (boundary.isCollidingWithRightWall(ball.getCollisionBox())) {
        score1++;
        resetPositions();
    }
}

void Pong::Game::handleBallPaddleCollisions(const Paddle& paddle) {
    if (ball.getCollisionBox().overlaps(paddle.getCollisionBox())) {
        // Get positions and dimensions
        const Vec2 ballPos = ball.getPosition();
        const Vec2 paddlePos = paddle.getPosition();
        const float ballSize = ball.getSize();
        const float paddleWidth = paddle.getWidth();
        const float paddleHeight = paddle.getHeight();

        // Calculate paddle boundaries
        const float paddleLeft = paddlePos.x - paddleWidth/2;
        const float paddleRight = paddlePos.x + paddleWidth/2;
        const float paddleTop = paddlePos.y + paddleHeight/2;
        const float paddleBottom = paddlePos.y - paddleHeight/2;

        // Calculate penetration depths on each axis
        const float penetrationLeft = ballPos.x + ballSize - paddleLeft;
        const float penetrationRight = paddleRight - (ballPos.x - ballSize);
        const float penetrationTop = paddleTop - (ballPos.y - ballSize);
        const float penetrationBottom = ballPos.y + ballSize - paddleBottom;

        // Find minimum penetration to determine collision side
        float minPenetration = penetrationLeft;
        enum CollisionSide { LEFT, RIGHT, TOP, BOTTOM } side = LEFT;

        if (penetrationRight < minPenetration) {
            minPenetration = penetrationRight;
            side = RIGHT;
        }

        if (penetrationTop < minPenetration) {
            minPenetration = penetrationTop;
            side = TOP;
        }

        if (penetrationBottom < minPenetration) {
            minPenetration = penetrationBottom;
            side = BOTTOM;
        }

        // Apply reflection and position correction based on collision side
        auto ballVelocity = ball.getVelocity();
        auto newBallPos = ballPos;

        switch (side) {
            case LEFT:
                newBallPos.x = paddleLeft - ballSize;
                ballVelocity.x = -std::abs(ballVelocity.x); // Ensure moving left
                break;

            case RIGHT:
                newBallPos.x = paddleRight + ballSize;
                ballVelocity.x = std::abs(ballVelocity.x); // Ensure moving right
                break;

            case TOP:
                newBallPos.y = paddleTop + ballSize;
                ballVelocity.y = std::abs(ballVelocity.y); // Ensure moving up
                break;

            case BOTTOM:
                newBallPos.y = paddleBottom - ballSize;
                ballVelocity.y = -std::abs(ballVelocity.y); // Ensure moving down
                break;
        }

        // Use paddle velocity to influence the ball's trajectory on collision
        // (only for horizontal collisions)
        if (side == LEFT || side == RIGHT) {
            // Get paddle's velocity
            Vec2 paddleVel = paddle.getVelocity();
            
            // Transfer some of paddle's y-velocity to the ball (with a multiplier for effect)
            const float paddleInfluence = 0.75f;  // How much paddle motion affects ball
            
            // Add paddle's velocity component to the ball's velocity
            ballVelocity.y += paddleVel.y * paddleInfluence;
            
            // Optional: Cap the maximum vertical velocity to prevent extreme angles
            const float maxVerticalVelocity = 350.0f;
            if (ballVelocity.y > maxVerticalVelocity) {
                ballVelocity.y = maxVerticalVelocity;
            } else if (ballVelocity.y < -maxVerticalVelocity) {
                ballVelocity.y = -maxVerticalVelocity;
            }
        }

        // Update ball position and velocity
        ball.setPosition(newBallPos);
        ball.setVelocity(ballVelocity);
    }
}

void Pong::Game::resetPositions() {
    // Reset ball position to center
    ball.setPosition(Vec2(boundary.getWidth() / 2.0f, boundary.getHeight() / 2.0f));
    
    // Reset ball velocity with a random direction to keep gameplay interesting
    float speed = 250.0f;
    float directionX = (rand() % 2 == 0) ? 1.0f : -1.0f; // Randomly choose left or right
    float directionY = ((float)rand() / RAND_MAX * 2.0f - 1.0f) * 0.7f; // Random Y direction between -0.7 and 0.7
    ball.setVelocity(Vec2(speed * directionX, speed * directionY));
    
    // Reset paddle positions
    player1.setPosition(Vec2(50.0f, boundary.getHeight() / 2.0f));
    player2.setPosition(Vec2(boundary.getWidth() - 50.0f, boundary.getHeight() / 2.0f));
    
    // Reset paddle velocities
    player1.setVelocity(Vec2::Zero());
    player2.setVelocity(Vec2::Zero());
}

void Pong::Game::updatePaddles(const float deltaTime) {
    player1.setVelocity(Vec2::Zero());
    player2.setVelocity(Vec2::Zero());
    if (!input.isPlayer1UpPressed && input.isPlayer1DownPressed) {
        auto position = player1.getPosition();
        const auto desiredHeight = position.y + 300.0f * deltaTime;
        const auto maxHeight = boundary.getHeight() - player1.getHeight() / 2;
        position.y = std::min(desiredHeight, maxHeight);
        player1.setPosition(position);

        auto velocity = player1.getVelocity();
        velocity.y = 300.0f;
        player1.setVelocity(velocity);
    }

    if (input.isPlayer1UpPressed && !input.isPlayer1DownPressed) {
        auto position = player1.getPosition();
        const auto desiredHeight = position.y - 300.0f * deltaTime;
        const auto minHeight = player1.getHeight() / 2;
        position.y = std::max(desiredHeight, minHeight);
        player1.setPosition(position);

        auto velocity = player1.getVelocity();
        velocity.y = -300.0f;
        player1.setVelocity(velocity);
    }

    if (!input.isPlayer2UpPressed && input.isPlayer2DownPressed) {
        auto position = player2.getPosition();
        const auto desiredHeight = position.y + 300.0f * deltaTime;
        const auto maxHeight = boundary.getHeight() - player2.getHeight() / 2;
        position.y = std::min(desiredHeight, maxHeight);
        player2.setPosition(position);

        auto velocity = player2.getVelocity();
        velocity.y = 300.0f;
        player2.setVelocity(velocity);
    }

    if (input.isPlayer2UpPressed && !input.isPlayer2DownPressed) {
        auto position = player2.getPosition();
        const auto desiredHeight = position.y - 300.0f * deltaTime;
        const auto minHeight = player2.getHeight() / 2;
        position.y = std::max(desiredHeight, minHeight);
        player2.setPosition(position);

        auto velocity = player2.getVelocity();
        velocity.y = -300.0f;
        player2.setVelocity(velocity);
    }
}
