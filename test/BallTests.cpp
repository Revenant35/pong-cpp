#include "gtest/gtest.h"
#include "Ball.h"
#include "CollisionBox.h"
#include "Vec2.h"

TEST(BallInitTest, Constructor) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    const Pong::Vec2 velocity(10.0f, 15.0f);
    
    // Act
    const Pong::Ball ball(position, velocity);
    
    // Assert
    EXPECT_FLOAT_EQ(ball.getPosition().x, position.x);
    EXPECT_FLOAT_EQ(ball.getPosition().y, position.y);
    EXPECT_FLOAT_EQ(ball.getVelocity().x, velocity.x);
    EXPECT_FLOAT_EQ(ball.getVelocity().y, velocity.y);
    EXPECT_FLOAT_EQ(ball.getSize(), Pong::Ball::DEFAULT_SIZE);
}

TEST(BallPositionTest, SetPosition) {
    // Arrange
    const Pong::Vec2 initialPosition(100.0f, 200.0f);
    const Pong::Vec2 initialVelocity(10.0f, 15.0f);
    Pong::Ball ball(initialPosition, initialVelocity);
    const Pong::Vec2 newPosition(300.0f, 400.0f);
    
    // Act
    ball.setPosition(newPosition);
    
    // Assert
    EXPECT_FLOAT_EQ(ball.getPosition().x, newPosition.x);
    EXPECT_FLOAT_EQ(ball.getPosition().y, newPosition.y);
    
    // Verify collision box is also updated
    const Pong::CollisionBox collisionBox = ball.getCollisionBox();
    EXPECT_FLOAT_EQ(collisionBox.x, newPosition.x);
    EXPECT_FLOAT_EQ(collisionBox.y, newPosition.y);
}

TEST(BallVelocityTest, SetVelocity) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    const Pong::Vec2 initialVelocity(10.0f, 15.0f);
    Pong::Ball ball(position, initialVelocity);
    const Pong::Vec2 newVelocity(25.0f, -35.0f);
    
    // Act
    ball.setVelocity(newVelocity);
    
    // Assert
    EXPECT_FLOAT_EQ(ball.getVelocity().x, newVelocity.x);
    EXPECT_FLOAT_EQ(ball.getVelocity().y, newVelocity.y);
}

TEST(BallDimensionTest, GetSize) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    const Pong::Vec2 velocity(10.0f, 15.0f);
    const Pong::Ball ball(position, velocity);
    
    // Act
    const float size = ball.getSize();
    
    // Assert
    EXPECT_FLOAT_EQ(size, Pong::Ball::DEFAULT_SIZE);
}

TEST(BallCollisionTest, GetCollisionBox) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    const Pong::Vec2 velocity(10.0f, 15.0f);
    const Pong::Ball ball(position, velocity);
    
    // Act
    const Pong::CollisionBox collisionBox = ball.getCollisionBox();
    
    // Assert
    EXPECT_FLOAT_EQ(collisionBox.height, Pong::Ball::DEFAULT_SIZE);
    EXPECT_FLOAT_EQ(collisionBox.width, Pong::Ball::DEFAULT_SIZE);
    EXPECT_FLOAT_EQ(collisionBox.x, position.x);
    EXPECT_FLOAT_EQ(collisionBox.y, position.y);
}

TEST(BallPositionVelocityTest, SetPositionUpdateOnlyPosition) {
    // Arrange
    const Pong::Vec2 initialPosition(100.0f, 200.0f);
    const Pong::Vec2 initialVelocity(10.0f, 15.0f);
    Pong::Ball ball(initialPosition, initialVelocity);
    const Pong::Vec2 newPosition(300.0f, 400.0f);
    
    // Act
    ball.setPosition(newPosition);
    
    // Assert - position changes but velocity remains the same
    EXPECT_FLOAT_EQ(ball.getPosition().x, newPosition.x);
    EXPECT_FLOAT_EQ(ball.getPosition().y, newPosition.y);
    EXPECT_FLOAT_EQ(ball.getVelocity().x, initialVelocity.x);
    EXPECT_FLOAT_EQ(ball.getVelocity().y, initialVelocity.y);
}

TEST(BallVelocityPositionTest, SetVelocityUpdateOnlyVelocity) {
    // Arrange
    const Pong::Vec2 initialPosition(100.0f, 200.0f);
    const Pong::Vec2 initialVelocity(10.0f, 15.0f);
    Pong::Ball ball(initialPosition, initialVelocity);
    const Pong::Vec2 newVelocity(25.0f, -35.0f);
    
    // Act
    ball.setVelocity(newVelocity);
    
    // Assert - velocity changes but position remains the same
    EXPECT_FLOAT_EQ(ball.getPosition().x, initialPosition.x);
    EXPECT_FLOAT_EQ(ball.getPosition().y, initialPosition.y);
    EXPECT_FLOAT_EQ(ball.getVelocity().x, newVelocity.x);
    EXPECT_FLOAT_EQ(ball.getVelocity().y, newVelocity.y);
}
