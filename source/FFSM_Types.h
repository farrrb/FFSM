//
// Created by farrrb on 10-Dec-17.
//

#ifndef FFSM_TYPES_H__
#define FFSM_TYPES_H__

typedef int FFSM_Event_t;
#define FFSM_EVENT_NONE   ((FFSM_Event_t)( 0))
#define FFSM_EVENT_ENTRY  ((FFSM_Event_t)(-1))
#define FFSM_EVENT_EXIT   ((FFSM_Event_t)(-2))

typedef int FFSM_Status_t;
#define FFSM_STATUS_HANDLED   ((FFSM_Status_t)(0))
#define FFSM_STATUS_UNHANDLED ((FFSM_Status_t)(1))

// the FFSM
typedef struct FFSM
{
  FFSM_Status_t (*current_state)(struct FFSM *self, FFSM_Event_t event, void *data);
  void *data;
} FFSM_t;

// prototype for all state function implementations
typedef FFSM_Status_t (*FFSM_State_t)(FFSM_t *self, FFSM_Event_t event, void *data);
#define FFSM_STATE_NONE  ((FFSM_State_t)(0))

typedef struct
{
  FFSM_State_t *data;
  unsigned int size;
  int top;
} FFSM_Stack_t;

#endif //FFSM_TYPES_H__
