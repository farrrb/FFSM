//
// Created by farrrb on 09-Dec-17.
//

#ifndef FFSM_H__
#define FFSM_H__



#define FFSM_SIG_NONE   (0)
#define FFSM_SIG_ENTRY  (-1)
#define FFSM_SIG_EXIT   (-2)

// prototype for all state function implementations
typedef void* (*FFSM_State_t)(int signal);

#define FFSM_STATE_NONE  ((FFSM_State_t)(0))

typedef struct
{
  FFSM_State_t current_state;
} FFSM_t;


void FFSM_init(FFSM_t *self, FFSM_State_t init_state);
void FFSM_transit(FFSM_t *self, FFSM_State_t new_state);
void FFSM_sendSignal(FFSM_t *self, int signal);

#endif // FFSM_H__
