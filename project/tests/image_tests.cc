#include "gtest/gtest.h"
#include "src/image_facade.cc"

class ImageFilter : public ::testing::Test {
//dont know what to put here exactly, just need it for the Tests
};

TEST_F(ImageFilter, ImageApplyTrue) {  
  
  Image input = Image("src/TEST_IMAGES/1.png")
  double output[5] = ApplyImage(input);
  EXPECT_EQ(output[0], 1);
}

TEST_F(ImageFilter, ImageApplyFalse) {
  Image input = Image("src/TEST_IMAGES/10.png")
  double output[5] = ApplyImage(input);
  EXPECT_EQ(output[0], 0);
}