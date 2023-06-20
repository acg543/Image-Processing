#include "gtest/gtest.h"
#include "drone.h"


class DroneTest : public ::testing::Test {
 public:
    void SetUp( ) {
    }
    protected:
};

// Testing Drone::GetPosition Function
TEST_F(DroneTest, GetPosition) {
    Drone d = Drone(100, 200, 300);
    EXPECT_EQ(d.GetPosition(0), 100) << "Drone's X Position is Incorrect";
    EXPECT_EQ(d.GetPosition(1), 200) << "Drone's Y Position is Incorrect";
    EXPECT_EQ(d.GetPosition(2), 300) << "Drone's Z Position is Incorrect";
    d.SetPosition(1, 2, 3);
    EXPECT_EQ(d.GetPosition(0), 1) << "Drone's X Position is Incorrect";
    EXPECT_EQ(d.GetPosition(1), 2) << "Drone's Y Position is Incorrect";
    EXPECT_EQ(d.GetPosition(2), 3) << "Drone's Z Position is Incorrect";
}

// Testing Drone::GetDirection Function
TEST_F(DroneTest, GetDirection) {
    Drone d = Drone();
    d.SetDirection(0, 10, 100);
    EXPECT_EQ(d.GetDirection(0), 0) << "Drone's X Direction is Incorrect";
    EXPECT_EQ(d.GetDirection(1), 10) << "Drone's Y Direction is Incorrect";
    EXPECT_EQ(d.GetDirection(2), 100) << "Drone's Z Direction is Incorrect";
}

// Testing Drone::GetSpeed Function
TEST_F(DroneTest, GetSpeed) {
    Drone d = Drone();
    d.SetSpeed(10.543);
    EXPECT_EQ(d.GetSpeed(), 10.543) << "Drone's Speed is Incorrect";
}

// Testing Drone::GetID Function
TEST_F(DroneTest, GetID) {
    Drone d = Drone();
    d.SetID(5);
    EXPECT_EQ(d.GetID(), 5) << "Drone's ID is Incorrect";
}

// Testing Drone::SetJoystick Function
TEST_F(DroneTest, SetJoystick) {
    Drone d = Drone();
    d.SetJoystick(-1, 0, 1, 1000);
    EXPECT_EQ(d.GetDirection(0), -1) << "Drone's X Direction is Incorrect";
    EXPECT_EQ(d.GetDirection(1), 0) << "Drone's Y Direction is Incorrect";
    EXPECT_EQ(d.GetDirection(2), 1) << "Drone's Z Direction is Incorrect";
}

// Testing Drone::UpdateDrone Function
TEST_F(DroneTest, UpdateDrone) {
    Drone d = Drone(0,0,0);
    d.SetSpeed(2);
    d.SetJoystick(1,2,3,1);
    d.UpdateDrone(1);

    EXPECT_EQ(d.GetPosition(0), 2);
    EXPECT_EQ(d.GetPosition(1), 4);
    EXPECT_EQ(d.GetPosition(2), 6);
}