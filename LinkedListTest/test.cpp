#include "gtest/gtest.h"

extern "C" {
#include "LinkedList.h"
}

class ProductionTest : public ::testing::Test {
protected:
	void SetUp() override {}
	void TearDown() override {}
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}