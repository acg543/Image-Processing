#include "gtest/gtest.h"
#include "movement.h"
#include "drone.h"
#include "beeline.h"

class MovementTest : public ::testing::Test {
 public:
    void SetUp( ) {
    }
    protected:
};

// Testing Beeline::Move Function
TEST_F(MovementTest, Move) {
    Drone d = Drone(0,0,0);
    d.SetJoystick(7,4,4,0);
    double dir[] = {d.GetDirection(0), d.GetDirection(1), d.GetDirection(2)};
    auto bee = std::unique_ptr<Movement>(new Beeline());
    bee->Move(d, dir, 1, 9, 0.5);

    EXPECT_EQ(d.GetPosition(0), 3.5);
    EXPECT_EQ(d.GetPosition(1), 2);
    EXPECT_EQ(d.GetPosition(2), 2);
}