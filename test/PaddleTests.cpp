#include "gtest/gtest.h"
#include "Paddle.h"
#include "CollisionBox.h"
#include "Vec2.h"

TEST(PaddleInitTest, Constructor) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    
    // Act
    const Pong::Paddle paddle(position);
    
    // Assert
    EXPECT_FLOAT_EQ(paddle.getPosition().x, position.x);
    EXPECT_FLOAT_EQ(paddle.getPosition().y, position.y);
    EXPECT_FLOAT_EQ(paddle.getHeight(), Pong::Paddle::DEFAULT_HEIGHT);
    EXPECT_FLOAT_EQ(paddle.getWidth(), Pong::Paddle::DEFAULT_WIDTH);
    EXPECT_FLOAT_EQ(paddle.getVelocity().x, 0.0f);
    EXPECT_FLOAT_EQ(paddle.getVelocity().y, 0.0f);
}

TEST(PaddlePositionTest, SetPosition) {
    // Arrange
    const Pong::Vec2 initialPosition(100.0f, 200.0f);
    Pong::Paddle paddle(initialPosition);
    const Pong::Vec2 newPosition(300.0f, 400.0f);
    
    // Act
    paddle.setPosition(newPosition);
    
    // Assert
    EXPECT_FLOAT_EQ(paddle.getPosition().x, newPosition.x);
    EXPECT_FLOAT_EQ(paddle.getPosition().y, newPosition.y);
    
    // Verify collision box is also updated
    const Pong::CollisionBox collisionBox = paddle.getCollisionBox();
    EXPECT_FLOAT_EQ(collisionBox.x, newPosition.x);
    EXPECT_FLOAT_EQ(collisionBox.y, newPosition.y);
}

TEST(PaddleVelocityTest, SetVelocity) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    Pong::Paddle paddle(position);
    const Pong::Vec2 velocity(15.0f, -25.0f);
    
    // Act
    paddle.setVelocity(velocity);
    
    // Assert
    EXPECT_FLOAT_EQ(paddle.getVelocity().x, velocity.x);
    EXPECT_FLOAT_EQ(paddle.getVelocity().y, velocity.y);
}

TEST(PaddleDimensionTest, GetHeight) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    const Pong::Paddle paddle(position);
    
    // Act
    const float height = paddle.getHeight();
    
    // Assert
    EXPECT_FLOAT_EQ(height, Pong::Paddle::DEFAULT_HEIGHT);
}

TEST(PaddleDimensionTest, GetWidth) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    const Pong::Paddle paddle(position);
    
    // Act
    const float width = paddle.getWidth();
    
    // Assert
    EXPECT_FLOAT_EQ(width, Pong::Paddle::DEFAULT_WIDTH);
}

TEST(PaddleCollisionTest, GetCollisionBox) {
    // Arrange
    const Pong::Vec2 position(100.0f, 200.0f);
    const Pong::Paddle paddle(position);
    
    // Act
    const Pong::CollisionBox collisionBox = paddle.getCollisionBox();
    
    // Assert
    EXPECT_FLOAT_EQ(collisionBox.height, Pong::Paddle::DEFAULT_HEIGHT);
    EXPECT_FLOAT_EQ(collisionBox.width, Pong::Paddle::DEFAULT_WIDTH);
    EXPECT_FLOAT_EQ(collisionBox.x, position.x);
    EXPECT_FLOAT_EQ(collisionBox.y, position.y);
}

TEST(PaddlePositionVelocityTest, SetPositionUpdateOnlyPosition) {
    // Arrange
    const Pong::Vec2 initialPosition(100.0f, 200.0f);
    const Pong::Vec2 initialVelocity(10.0f, 20.0f);
    Pong::Paddle paddle(initialPosition);
    paddle.setVelocity(initialVelocity);
    
    const Pong::Vec2 newPosition(300.0f, 400.0f);
    
    // Act
    paddle.setPosition(newPosition);
    
    // Assert - position changes but velocity remains the same
    EXPECT_FLOAT_EQ(paddle.getPosition().x, newPosition.x);
    EXPECT_FLOAT_EQ(paddle.getPosition().y, newPosition.y);
    EXPECT_FLOAT_EQ(paddle.getVelocity().x, initialVelocity.x);
    EXPECT_FLOAT_EQ(paddle.getVelocity().y, initialVelocity.y);
}

TEST(PaddleVelocityPositionTest, SetVelocityUpdateOnlyVelocity) {
    // Arrange
    const Pong::Vec2 initialPosition(100.0f, 200.0f);
    Pong::Paddle paddle(initialPosition);
    const Pong::Vec2 newVelocity(15.0f, -25.0f);
    
    // Act
    paddle.setVelocity(newVelocity);
    
    // Assert - velocity changes but position remains the same
    EXPECT_FLOAT_EQ(paddle.getPosition().x, initialPosition.x);
    EXPECT_FLOAT_EQ(paddle.getPosition().y, initialPosition.y);
    EXPECT_FLOAT_EQ(paddle.getVelocity().x, newVelocity.x);
    EXPECT_FLOAT_EQ(paddle.getVelocity().y, newVelocity.y);
}
