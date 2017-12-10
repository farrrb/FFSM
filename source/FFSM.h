//
// Created by farrrb on 09-Dec-17.
//

#ifndef FFSM_H__
#define FFSM_H__

typedef int FFSM_Event_t;
#define FFSM_EVENT_NONE   ((FFSM_Event_t)( 0))
#define FFSM_EVENT_ENTRY  ((FFSM_Event_t)(-1))
#define FFSM_EVENT_EXIT   ((FFSM_Event_t)(-2))

typedef int FFSM_Status_t;
#define FFSM_STATUS_HANDLED ((FFSM_Status_t)(0))

// prototype for all state function implementations
typedef FFSM_Status_t (*FFSM_State_t)(FFSM_Event_t event, void *data);
#define FFSM_STATE_NONE  ((FFSM_State_t)(0))


typedef struct
{
  FFSM_State_t current_state;
  void *data;
} FFSM_t;

void FFSM_init(FFSM_t * const self, FFSM_State_t init_state, void *data);
void FFSM_transit(FFSM_t * const self, FFSM_State_t new_state);
void FFSM_dispatchEvent(FFSM_t * const self, FFSM_Event_t event);

#endif // FFSM_H__
