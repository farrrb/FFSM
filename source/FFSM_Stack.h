//
// Created by farrrb on 10-Dec-17.
//

#ifndef FFSM_STACK_H__
#define FFSM_STACK_H__

#include "FFSM_Types.h"

int FFSM_Stack_init(FFSM_Stack_t *stack, FFSM_State_t *data, unsigned int size);

int FFSM_Stack_push(FFSM_Stack_t *stack, FFSM_State_t state);
FFSM_State_t FFSM_Stack_pop(FFSM_Stack_t *stack);

int FFSM_Stack_getDepth(FFSM_Stack_t *stack);

#endif //FFSM_STACK_H__
