//
// Created by farrrb on 23-Dec-17.
//

#include "FFSM.h"
#include "test_helper.h"
#include "unity.h"

FFSM_t windshield_wipers;

#define SIGNAL_WW_SWITCH_ON  1
#define SIGNAL_WW_SWITCH_OFF 2

FFSM_Status_t ww_off(FFSM_t *self, FFSM_Event_t event, void *data);
FFSM_Status_t ww_on(FFSM_t *self, FFSM_Event_t event, void *data);
  FFSM_Status_t ww_speed_low(FFSM_t *self, FFSM_Event_t event, void *data);
  FFSM_Status_t ww_speed_high(FFSM_t *self, FFSM_Event_t event, void *data);
  FFSM_Status_t ww_wash(FFSM_t *self, FFSM_Event_t event, void *data);


FFSM_Status_t ww_off(FFSM_t *self, FFSM_Event_t event, void *data)
{
  UNUSED_PARAM(data);

  print_event(event);
  switch (event)
  {
    case SIGNAL_WW_SWITCH_ON:
      FFSM_transit(self, ww_on);
    case FFSM_EVENT_NONE:
    case FFSM_EVENT_ENTRY:
    case FFSM_EVENT_EXIT:
    default:
      break;
  }
  return FFSM_STATUS_HANDLED;
}

FFSM_Status_t ww_on(FFSM_t *self, FFSM_Event_t event, void *data)
{
  UNUSED_PARAM(data);

  print_event(event);
  switch (event)
  {
    case SIGNAL_WW_SWITCH_OFF:
      FFSM_transit(self, ww_off);
    case FFSM_EVENT_NONE:
    case FFSM_EVENT_ENTRY:
    case FFSM_EVENT_EXIT:
    default:
      break;
  }
  return FFSM_STATUS_HANDLED;
}

FFSM_Status_t ww_speed_low(FFSM_t *self, FFSM_Event_t event, void *data)
{
  UNUSED_PARAM(self);
  UNUSED_PARAM(event);
  UNUSED_PARAM(data);
  return FFSM_STATUS_UNHANDLED;
}

FFSM_Status_t ww_speed_high(FFSM_t *self, FFSM_Event_t event, void *data)
{
  UNUSED_PARAM(self);
  UNUSED_PARAM(event);
  UNUSED_PARAM(data);
  return FFSM_STATUS_UNHANDLED;
}

FFSM_Status_t ww_wash(FFSM_t *self, FFSM_Event_t event, void *data)
{
  UNUSED_PARAM(self);
  UNUSED_PARAM(event);
  UNUSED_PARAM(data);
  return FFSM_STATUS_UNHANDLED;
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
void test(void)
{
  FFSM_init(&windshield_wipers, ww_off, (void *)0);
  FFSM_dispatchEvent(&windshield_wipers, SIGNAL_WW_SWITCH_ON);
  FFSM_dispatchEvent(&windshield_wipers, SIGNAL_WW_SWITCH_OFF);
}

int main(int argc, char *argv[])
{
  UNITY_BEGIN();

  UNUSED_PARAM(argc);
  UNUSED_PARAM(argv);

  RUN_TEST(test);

  return UNITY_END();
}