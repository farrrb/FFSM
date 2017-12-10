//
// Created by farrrb on 10-Dec-17.
//

#ifndef FBPFSM_ROOT_FFSM_TYPES_H
#define FBPFSM_ROOT_FFSM_TYPES_H

typedef int FFSM_Event_t;
#define FFSM_EVENT_NONE   ((FFSM_Event_t)( 0))
#define FFSM_EVENT_ENTRY  ((FFSM_Event_t)(-1))
#define FFSM_EVENT_EXIT   ((FFSM_Event_t)(-2))

typedef int FFSM_Status_t;
#define FFSM_STATUS_HANDLED ((FFSM_Status_t)(0))

// prototype for all state function implementations
typedef FFSM_Status_t (*FFSM_State_t)(FFSM_Event_t event, void *data);
#define FFSM_STATE_NONE  ((FFSM_State_t)(0))

// the FFSM
typedef struct
{
  FFSM_State_t current_state;
  void *data;
} FFSM_t;

typedef struct
{
  FFSM_State_t *data;
  int size;
  int top;
} FFSM_Stack_t;

#endif //FBPFSM_ROOT_FFSM_TYPES_H
