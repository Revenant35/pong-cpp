#include "gtest/gtest.h"

#include "CollisionBox.h"

TEST(InitializationTest, CreateCollisionBox) {
    // Arrange
    constexpr float height = 100.0f;
    constexpr float width = 50.0f;
    constexpr float x = 50.0f;
    constexpr float y = 50.0f;
    
    // Act
    const Pong::CollisionBox box(height, width, x, y);

    // Assert
    EXPECT_EQ(box.height, height);
    EXPECT_EQ(box.width, width);
    EXPECT_EQ(box.x, x);
    EXPECT_EQ(box.y, y);
}


TEST(InitializationTest, CreateCollisionBoxWithPosition) {
    // Arrange
    constexpr float height = 100.0f;
    constexpr float width = 50.0f;
    const Pong::Vec2 position{50.0f, 50.0f};

    // Act
    const Pong::CollisionBox box(height, width, position);

    // Assert
    EXPECT_EQ(box.height, height);
    EXPECT_EQ(box.width, width);
    EXPECT_EQ(box.x, 50.0f);
    EXPECT_EQ(box.y, 50.0f);
}

TEST(ContainsPointTest, PointInsideBox) {
    // Arrange
    const Pong::CollisionBox box(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::Vec2 point{55.0f, 55.0f};
    
    // Act
    const bool contains = box.contains(point);
    
    // Assert
    EXPECT_TRUE(contains);
}

TEST(ContainsPointTest, PointOutsideBox) {
    // Arrange
    const Pong::CollisionBox box(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::Vec2 point{0.0f, 20.0f};
    
    // Act
    const bool contains = box.contains(point);
    
    // Assert
    EXPECT_FALSE(contains);
}

TEST(ContainsPointTest, PointOnEdge) {
    // Arrange
    const Pong::CollisionBox box(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::Vec2 topEdgePoint{50.0f, 100.0f};
    const Pong::Vec2 bottomEdgePoint{50.0f, 0.0f};
    const Pong::Vec2 leftEdgePoint{25.0f, 50.0f};
    const Pong::Vec2 rightEdgePoint{75.0f, 50.0f};
    
    // Act & Assert
    EXPECT_TRUE(box.contains(topEdgePoint));
    EXPECT_TRUE(box.contains(bottomEdgePoint));
    EXPECT_TRUE(box.contains(leftEdgePoint));
    EXPECT_TRUE(box.contains(rightEdgePoint));
}

TEST(ContainsPointTest, PointOnCorner) {
    // Arrange
    const Pong::CollisionBox box(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::Vec2 topLeftCorner{25.0f, 100.0f};
    const Pong::Vec2 topRightCorner{75.0f, 100.0f};
    const Pong::Vec2 bottomLeftCorner{25.0f, 0.0f};
    const Pong::Vec2 bottomRightCorner{75.0f, 0.0f};
    
    // Act & Assert
    EXPECT_TRUE(box.contains(topLeftCorner));
    EXPECT_TRUE(box.contains(topRightCorner));
    EXPECT_TRUE(box.contains(bottomLeftCorner));
    EXPECT_TRUE(box.contains(bottomRightCorner));
}

TEST(ContainsBoxTest, SmallerBoxInside) {
    // Arrange
    const Pong::CollisionBox largerBox(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox smallerBox(50.0f, 25.0f, 50.0f, 50.0f);
    
    // Act
    const bool largerContainsSmaller = largerBox.contains(smallerBox);
    const bool smallerContainsLarger = smallerBox.contains(largerBox);
    
    // Assert
    EXPECT_TRUE(largerContainsSmaller);
    EXPECT_FALSE(smallerContainsLarger);
}

TEST(ContainsBoxTest, BoxOutside) {
    // Arrange
    const Pong::CollisionBox box1(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox box2(50.0f, 25.0f, 150.0f, 150.0f);
    
    // Act
    const bool box1ContainsBox2 = box1.contains(box2);
    const bool box2ContainsBox1 = box2.contains(box1);
    
    // Assert
    EXPECT_FALSE(box1ContainsBox2);
    EXPECT_FALSE(box2ContainsBox1);
}

TEST(ContainsBoxTest, PartiallyOverlapping) {
    // Arrange
    const Pong::CollisionBox box1(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox box2(50.0f, 25.0f, 75.0f, 75.0f);
    
    // Act
    const bool box1ContainsBox2 = box1.contains(box2);
    const bool box2ContainsBox1 = box2.contains(box1);
    
    // Assert
    EXPECT_FALSE(box1ContainsBox2);
    EXPECT_FALSE(box2ContainsBox1);
}

TEST(ContainsBoxTest, BoxOnEdge) {
    // Arrange
    const Pong::CollisionBox box1(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox box2(50.0f, 25.0f, 100.0f, 50.0f);
    
    // Act
    const bool box1ContainsBox2 = box1.contains(box2);
    
    // Assert
    EXPECT_FALSE(box1ContainsBox2);
}

TEST(OverlapsTest, BoxesOverlap) {
    // Arrange
    const Pong::CollisionBox box1(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox box2(50.0f, 25.0f, 75.0f, 75.0f);
    
    // Act
    const bool box1OverlapsBox2 = box1.overlaps(box2);
    const bool box2OverlapsBox1 = box2.overlaps(box1);
    
    // Assert
    EXPECT_TRUE(box1OverlapsBox2);
    EXPECT_TRUE(box2OverlapsBox1);
}

TEST(OverlapsTest, BoxesDoNotOverlap) {
    // Arrange
    const Pong::CollisionBox box1(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox box2(50.0f, 25.0f, 150.0f, 150.0f);
    
    // Act
    const bool box1OverlapsBox2 = box1.overlaps(box2);
    const bool box2OverlapsBox1 = box2.overlaps(box1);
    
    // Assert
    EXPECT_FALSE(box1OverlapsBox2);
    EXPECT_FALSE(box2OverlapsBox1);
}

TEST(OverlapsTest, BoxContainedCompletelyOverlaps) {
    // Arrange
    const Pong::CollisionBox largerBox(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox smallerBox(50.0f, 25.0f, 50.0f, 50.0f);
    
    // Act
    const bool largerOverlapsSmaller = largerBox.overlaps(smallerBox);
    const bool smallerOverlapsLarger = smallerBox.overlaps(largerBox);
    
    // Assert
    EXPECT_TRUE(largerOverlapsSmaller);
    EXPECT_TRUE(smallerOverlapsLarger);
}

TEST(OverlapsTest, BoxesTouching) {
    // Arrange
    const Pong::CollisionBox box1(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox box2(50.0f, 25.0f, 87.5f, 50.0f);
    
    // Act
    const bool box1OverlapsBox2 = box1.overlaps(box2);
    const bool box2OverlapsBox1 = box2.overlaps(box1);
    
    // Assert
    EXPECT_TRUE(box1OverlapsBox2);
    EXPECT_TRUE(box2OverlapsBox1);
}

TEST(OverlapsTest, BoxesNearlyTouching) {
    // Arrange
    const Pong::CollisionBox box1(100.0f, 50.0f, 50.0f, 50.0f);
    const Pong::CollisionBox box2(10.0f, 10.0f, 90.0f, 50.0f);
    const bool shouldOverlap = (50.0f + box1.width/2.0f) >= (90.0f - box2.width/2.0f);
    
    // Act
    const bool overlap = box1.overlaps(box2);
    
    // Assert
    EXPECT_EQ(overlap, shouldOverlap);
}
