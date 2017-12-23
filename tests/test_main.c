//
// Created by farrrb on 09-Dec-17.
//
#include <stdio.h>

#include "test_helper.h"
#include "unity.h"

#include "FFSM.h"
#include "FFSM_Strings.h"

FFSM_t fsm_test;

struct fsm_data
{
  int test_var;
};

struct fsm_data fsm_test_data;

#define FFSM_SIG_TRANS_TO_NONE 1

void print_event(FFSM_Event_t event)
{
  printf("\nevent: %s:(%d)", FFSM_getStrFromEvent(event), event);
}

FFSM_Status_t test_init_state(FFSM_Event_t event, void * data)
{
  print_event(event);
  struct fsm_data *p = (struct fsm_data *)data;
  p->test_var++;
  switch (event)
  {
    case FFSM_EVENT_NONE:
    {
      break;
    }
    case FFSM_EVENT_ENTRY:
    {
      break;
    }
    case FFSM_EVENT_EXIT:
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
  return FFSM_STATUS_HANDLED;
}

FFSM_Status_t test_final_state(FFSM_Event_t event, void * data)
{
  print_event(event);
  struct fsm_data *p = (struct fsm_data *)data;
  printf("\ngot data: %d", p->test_var);
  return FFSM_STATUS_HANDLED;
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
  printf("\ninit:");
  FFSM_init(&fsm_test, test_init_state, &fsm_test_data);
  TEST_ASSERT_EQUAL_PTR(test_init_state, fsm_test.current_state);
  TEST_ASSERT_EQUAL_PTR(&fsm_test_data,  fsm_test.data);

  FFSM_dispatchEvent(&fsm_test, FFSM_EVENT_NONE);
  printf("\ntrans to none");
  FFSM_dispatchEvent(&fsm_test, FFSM_SIG_TRANS_TO_NONE);
  TEST_ASSERT_EQUAL_PTR(FFSM_STATE_NONE, fsm_test.current_state);

  printf("\ntrans to final");
  FFSM_transit(&fsm_test, test_final_state);
  TEST_ASSERT_EQUAL_PTR(test_final_state, fsm_test.current_state);

  printf("\n");
}

int main(int argc, char *argv[])
{
  UNITY_BEGIN();

  UNUSED_PARAM(argc);
  UNUSED_PARAM(argv);

  RUN_TEST(test_init);

  return UNITY_END();
}