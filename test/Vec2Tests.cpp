#include "gtest/gtest.h"
#include "Vec2.h"
#include <cmath>

TEST(Vec2InitTest, Constructor) {
    // Arrange & Act
    const Pong::Vec2 vec(3.0f, 4.0f);
    
    // Assert
    EXPECT_FLOAT_EQ(vec.x, 3.0f);
    EXPECT_FLOAT_EQ(vec.y, 4.0f);
}

TEST(Vec2InitTest, ZeroVector) {
    // Arrange & Act
    const Pong::Vec2 vec = Pong::Vec2::Zero();
    
    // Assert
    EXPECT_FLOAT_EQ(vec.x, 0.0f);
    EXPECT_FLOAT_EQ(vec.y, 0.0f);
}

TEST(Vec2MagnitudeTest, CalculatesMagnitude) {
    // Arrange
    const Pong::Vec2 vec(3.0f, 4.0f);
    
    // Act
    const float magnitude = vec.magnitude();
    
    // Assert
    EXPECT_FLOAT_EQ(magnitude, 5.0f);
}

TEST(Vec2MagnitudeTest, ZeroVectorMagnitude) {
    // Arrange
    const Pong::Vec2 vec = Pong::Vec2::Zero();
    
    // Act
    const float magnitude = vec.magnitude();
    
    // Assert
    EXPECT_FLOAT_EQ(magnitude, 0.0f);
}

TEST(Vec2OperatorTest, Addition) {
    // Arrange
    const Pong::Vec2 a(1.0f, 2.0f);
    const Pong::Vec2 b(3.0f, 4.0f);
    
    // Act
    const Pong::Vec2 result = a + b;
    
    // Assert
    EXPECT_FLOAT_EQ(result.x, 4.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
}

TEST(Vec2OperatorTest, Subtraction) {
    // Arrange
    const Pong::Vec2 a(5.0f, 7.0f);
    const Pong::Vec2 b(2.0f, 3.0f);
    
    // Act
    const Pong::Vec2 result = a - b;
    
    // Assert
    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vec2OperatorTest, ScalarMultiplication) {
    // Arrange
    const Pong::Vec2 vec(3.0f, 4.0f);
    constexpr float scalar = 2.0f;
    
    // Act
    const Pong::Vec2 result = vec * scalar;
    
    // Assert
    EXPECT_FLOAT_EQ(result.x, 6.0f);
    EXPECT_FLOAT_EQ(result.y, 8.0f);
}

TEST(Vec2OperatorTest, ScalarDivision) {
    // Arrange
    const Pong::Vec2 vec(6.0f, 8.0f);
    constexpr float scalar = 2.0f;
    
    // Act
    const Pong::Vec2 result = vec / scalar;
    
    // Assert
    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vec2OperatorTest, CompoundAddition) {
    // Arrange
    Pong::Vec2 a(1.0f, 2.0f);
    const Pong::Vec2 b(3.0f, 4.0f);
    
    // Act
    a += b;
    
    // Assert
    EXPECT_FLOAT_EQ(a.x, 4.0f);
    EXPECT_FLOAT_EQ(a.y, 6.0f);
}

TEST(Vec2OperatorTest, CompoundSubtraction) {
    // Arrange
    Pong::Vec2 a(5.0f, 7.0f);
    const Pong::Vec2 b(2.0f, 3.0f);
    
    // Act
    a -= b;
    
    // Assert
    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_FLOAT_EQ(a.y, 4.0f);
}

TEST(Vec2OperatorTest, CompoundMultiplication) {
    // Arrange
    Pong::Vec2 vec(3.0f, 4.0f);
    constexpr float scalar = 2.0f;
    
    // Act
    vec *= scalar;
    
    // Assert
    EXPECT_FLOAT_EQ(vec.x, 6.0f);
    EXPECT_FLOAT_EQ(vec.y, 8.0f);
}

TEST(Vec2OperatorTest, CompoundDivision) {
    // Arrange
    Pong::Vec2 vec(6.0f, 8.0f);
    constexpr float scalar = 2.0f;
    
    // Act
    vec /= scalar;
    
    // Assert
    EXPECT_FLOAT_EQ(vec.x, 3.0f);
    EXPECT_FLOAT_EQ(vec.y, 4.0f);
}

TEST(Vec2EdgeCaseTest, DivisionByZero) {
    // Arrange
    const Pong::Vec2 vec(6.0f, 8.0f);
    constexpr float scalar = 0.0f;
    
    // Act
    const Pong::Vec2 result = vec / scalar;
    
    // Assert
    EXPECT_TRUE(std::isinf(result.x));
    EXPECT_TRUE(std::isinf(result.y));
}

TEST(Vec2EdgeCaseTest, CompoundDivisionByZero) {
    // Arrange
    Pong::Vec2 vec(6.0f, 8.0f);
    constexpr float scalar = 0.0f;
    
    // Act
    vec /= scalar;
    
    // Assert
    EXPECT_TRUE(std::isinf(vec.x));
    EXPECT_TRUE(std::isinf(vec.y));
}
