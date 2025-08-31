#include "gtest/gtest.h"
#include "GameBoundary.h"
#include "CollisionBox.h"

TEST(GameBoundaryInitTest, Constructor) {
    // Arrange & Act
    const Pong::GameBoundary boundary;
    
    // Assert
    EXPECT_FLOAT_EQ(boundary.getHeight(), Pong::GameBoundary::DEFAULT_HEIGHT);
    EXPECT_FLOAT_EQ(boundary.getWidth(), Pong::GameBoundary::DEFAULT_WIDTH);
}

TEST(GameBoundaryDimensionTest, GetHeight) {
    // Arrange
    const Pong::GameBoundary boundary;
    
    // Act
    const float height = boundary.getHeight();
    
    // Assert
    EXPECT_FLOAT_EQ(height, Pong::GameBoundary::DEFAULT_HEIGHT);
}

TEST(GameBoundaryDimensionTest, GetWidth) {
    // Arrange
    const Pong::GameBoundary boundary;
    
    // Act
    const float width = boundary.getWidth();
    
    // Assert
    EXPECT_FLOAT_EQ(width, Pong::GameBoundary::DEFAULT_WIDTH);
}

TEST(GameBoundaryCollisionTest, TopWallCollision) {
    // Arrange
    const Pong::GameBoundary boundary;
    // Box at the top edge of the game area
    const Pong::CollisionBox topBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH / 2.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT - 5.0f);
    // Box far from the top edge
    const Pong::CollisionBox centerBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH / 2.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT / 2.0f);
    
    // Act & Assert
    EXPECT_TRUE(boundary.isCollidingWithTopWall(topBox));
    EXPECT_FALSE(boundary.isCollidingWithTopWall(centerBox));
}

TEST(GameBoundaryCollisionTest, BottomWallCollision) {
    // Arrange
    const Pong::GameBoundary boundary;
    // Box at the bottom edge of the game area
    const Pong::CollisionBox bottomBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH / 2.0f, 
        5.0f);
    // Box far from the bottom edge
    const Pong::CollisionBox centerBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH / 2.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT / 2.0f);
    
    // Act & Assert
    EXPECT_TRUE(boundary.isCollidingWithBottomWall(bottomBox));
    EXPECT_FALSE(boundary.isCollidingWithBottomWall(centerBox));
}

TEST(GameBoundaryCollisionTest, LeftWallCollision) {
    // Arrange
    const Pong::GameBoundary boundary;
    // Box at the left edge of the game area
    const Pong::CollisionBox leftBox(20.0f, 20.0f, 
        5.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT / 2.0f);
    // Box far from the left edge
    const Pong::CollisionBox centerBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH / 2.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT / 2.0f);
    
    // Act & Assert
    EXPECT_TRUE(boundary.isCollidingWithLeftWall(leftBox));
    EXPECT_FALSE(boundary.isCollidingWithLeftWall(centerBox));
}

TEST(GameBoundaryCollisionTest, RightWallCollision) {
    // Arrange
    const Pong::GameBoundary boundary;
    // Box at the right edge of the game area
    const Pong::CollisionBox rightBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH - 5.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT / 2.0f);
    // Box far from the right edge
    const Pong::CollisionBox centerBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH / 2.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT / 2.0f);
    
    // Act & Assert
    EXPECT_TRUE(boundary.isCollidingWithRightWall(rightBox));
    EXPECT_FALSE(boundary.isCollidingWithRightWall(centerBox));
}

TEST(GameBoundaryCollisionTest, MultipleWallCollisions) {
    // Arrange
    const Pong::GameBoundary boundary;
    // Box in the top-left corner
    const Pong::CollisionBox cornerBox(20.0f, 20.0f, 
        5.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT - 5.0f);
    
    // Act & Assert - should collide with both top and left walls
    EXPECT_TRUE(boundary.isCollidingWithTopWall(cornerBox));
    EXPECT_TRUE(boundary.isCollidingWithLeftWall(cornerBox));
    EXPECT_FALSE(boundary.isCollidingWithBottomWall(cornerBox));
    EXPECT_FALSE(boundary.isCollidingWithRightWall(cornerBox));
}

TEST(GameBoundaryCollisionTest, NoCollisions) {
    // Arrange
    const Pong::GameBoundary boundary;
    // Box in the center of the game area
    const Pong::CollisionBox centerBox(20.0f, 20.0f, 
        Pong::GameBoundary::DEFAULT_WIDTH / 2.0f, 
        Pong::GameBoundary::DEFAULT_HEIGHT / 2.0f);
    
    // Act & Assert - should not collide with any walls
    EXPECT_FALSE(boundary.isCollidingWithTopWall(centerBox));
    EXPECT_FALSE(boundary.isCollidingWithBottomWall(centerBox));
    EXPECT_FALSE(boundary.isCollidingWithLeftWall(centerBox));
    EXPECT_FALSE(boundary.isCollidingWithRightWall(centerBox));
}
