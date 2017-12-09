//
// Created by farrrb on 09-Dec-17.
//

#ifndef FFSM_H__
#define FFSM_H__



#define FFSM_SIG_NONE   (0)
#define FFSM_SIG_ENTRY  (-1)
#define FFSM_SIG_EXIT   (-2)

typedef int FFSM_Event_t;

// prototype for all state function implementations
typedef void* (*FFSM_State_t)(FFSM_Event_t event, void *data);

#define FFSM_STATE_NONE  ((FFSM_State_t)(0))

typedef struct
{
  FFSM_State_t current_state;
  void *data;
} FFSM_t;


void FFSM_init(FFSM_t * const self, FFSM_State_t init_state, void *data);
void FFSM_transit(FFSM_t * const self, FFSM_State_t new_state);
void FFSM_sendSignal(FFSM_t * const self, int event);

#endif // FFSM_H__
