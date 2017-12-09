//
// Created by farrrb on 09-Dec-17.
//

#include "FFSM.h"
#include "unity.h"

FFSM_t fsm_test;

struct fsm_data
{
  int test_var;
};

struct fsm_data fsm_test_data;

#define FFSM_SIG_TRANS_TO_NONE 1

void *test_init_state(FFSM_Event_t event, void * data)
{
  switch (event)
  {
    case FFSM_SIG_NONE:
    {
      break;
    }
    case FFSM_SIG_ENTRY:
    {
      break;
    }
    case FFSM_SIG_EXIT:
    {
      break;
    }
    case FFSM_SIG_TRANS_TO_NONE:
    {
      FFSM_transit(&fsm_test, FFSM_STATE_NONE);
    }
    default:
    {
      break;
    }
  }
}

void *test_final_state(FFSM_Event_t event, void * data)
{
  (void)event;
  (void)data;
}


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
  FFSM_init(&fsm_test, test_init_state, &fsm_test_data);
  TEST_ASSERT_EQUAL_PTR(fsm_test.current_state, test_init_state);
  TEST_ASSERT_EQUAL_PTR(fsm_test.data, &fsm_test_data);

  FFSM_sendSignal(&fsm_test, FFSM_SIG_TRANS_TO_NONE);
  TEST_ASSERT_EQUAL_PTR(fsm_test.current_state, FFSM_STATE_NONE);

  FFSM_transit(&fsm_test, test_final_state);
  TEST_ASSERT_EQUAL_PTR(fsm_test.current_state, test_final_state);

}

int main(int argc, char *argv[])
{
  UNITY_BEGIN();

  RUN_TEST(test_init);

  return UNITY_END();
}