//
// Created by farrrb on 09-Dec-17.
//
#include <FFSM_Types.h>
#include "test_helper.h"
#include "unity.h"

#include "FFSM_Stack.h"

#define TEST_STACK_SIZE (3)
FFSM_Stack_t test_stack; ///< my test stack
FFSM_State_t test_data[TEST_STACK_SIZE] = {(FFSM_State_t)0xF, (FFSM_State_t)0xA, (FFSM_State_t)0xB};

// test: setup
void setUp(void)
{
}

// test: tear down
void tearDown(void)
{
}

// the actual test
void test_init(void)
{
  int ret;

  ret = FFSM_Stack_init((FFSM_Stack_t *)0, (FFSM_State_t *)0, 0);
  TEST_ASSERT_EQUAL(ret, -1);

  TEST_ASSERT_EQUAL_PTR((FFSM_State_t)0xF, test_data[0]);
  TEST_ASSERT_EQUAL_PTR((FFSM_State_t)0xA, test_data[1]);
  TEST_ASSERT_EQUAL_PTR((FFSM_State_t)0xB, test_data[2]);

  ret = FFSM_Stack_init(&test_stack, test_data, TEST_STACK_SIZE);
  TEST_ASSERT_EQUAL(ret, 0);

  TEST_ASSERT_EQUAL(test_stack.size, TEST_STACK_SIZE);
  TEST_ASSERT_EQUAL(test_stack.top, 0);
  TEST_ASSERT_EQUAL(test_stack.data, test_data);

  TEST_ASSERT_EQUAL_PTR(FFSM_STATE_NONE, test_data[0]);
  TEST_ASSERT_EQUAL_PTR(FFSM_STATE_NONE, test_data[1]);
  TEST_ASSERT_EQUAL_PTR(FFSM_STATE_NONE, test_data[2]);


  // push tests
  TEST_ASSERT_EQUAL(test_stack.top, 0);
  TEST_ASSERT_EQUAL_PTR(test_stack.data[0], (FFSM_State_t)0);

  TEST_ASSERT_EQUAL(FFSM_Stack_push(&test_stack, (FFSM_State_t)1), 0);
  TEST_ASSERT_EQUAL(test_stack.top, 1);
  TEST_ASSERT_EQUAL_PTR(test_stack.data[0], (FFSM_State_t)1);

  TEST_ASSERT_EQUAL(FFSM_Stack_push(&test_stack, (FFSM_State_t)2), 0);
  TEST_ASSERT_EQUAL_PTR(test_stack.top, 2);
  TEST_ASSERT_EQUAL_PTR(test_stack.data[1], (FFSM_State_t)2);

  TEST_ASSERT_EQUAL(FFSM_Stack_push(&test_stack, (FFSM_State_t)3), 0);
  TEST_ASSERT_EQUAL(test_stack.top, 3);
  TEST_ASSERT_EQUAL_PTR(test_stack.data[2], (FFSM_State_t)3);

  TEST_ASSERT_EQUAL(FFSM_Stack_push(&test_stack, (FFSM_State_t)4), -1);
  TEST_ASSERT_EQUAL(test_stack.top, 3);
  TEST_ASSERT_EQUAL_PTR(test_stack.data[2], (FFSM_State_t)3);

  TEST_ASSERT_EQUAL(test_stack.size, TEST_STACK_SIZE);


  // pop tests
  TEST_ASSERT_EQUAL_PTR(FFSM_Stack_pop(&test_stack), (FFSM_State_t)3);
  TEST_ASSERT_EQUAL(test_stack.top, 2);
  TEST_ASSERT_EQUAL_PTR(FFSM_Stack_pop(&test_stack), (FFSM_State_t)2);
  TEST_ASSERT_EQUAL(test_stack.top, 1);
  TEST_ASSERT_EQUAL_PTR(FFSM_Stack_pop(&test_stack), (FFSM_State_t)1);
  TEST_ASSERT_EQUAL(test_stack.top, 0);
  TEST_ASSERT_EQUAL_PTR(FFSM_Stack_pop(&test_stack), (FFSM_State_t)1);
  TEST_ASSERT_EQUAL(test_stack.top, 0);
  TEST_ASSERT_EQUAL_PTR(FFSM_Stack_pop(&test_stack), (FFSM_State_t)1);

  TEST_ASSERT_EQUAL_PTR(FFSM_Stack_pop((FFSM_Stack_t *)0), FFSM_STATE_NONE);

}

int main(int argc, char *argv[])
{
  UNITY_BEGIN();

  UNUSED_PARAM(argc);
  UNUSED_PARAM(argv);

  RUN_TEST(test_init);

  return UNITY_END();
}