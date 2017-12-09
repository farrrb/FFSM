//
// Created by farrrb on 09-Dec-17.
//

#include "unity.h"
#include "fbpfsm.h"

// test: setup
void setUp(void)
{
}

// test: tear down
void tearDown(void)
{
}

// the actual test
void test_Template(void)
{
  TEST_ASSERT_EQUAL(11, my_test_func(23));
}

int main(int argc, char *argv[])
{
  UNITY_BEGIN();

  RUN_TEST(test_Template);

  return UNITY_END();
}