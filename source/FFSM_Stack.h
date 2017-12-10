//
// Created by farrrb on 10-Dec-17.
//

#ifndef FBPFSM_ROOT_FFSM_STACK_H
#define FBPFSM_ROOT_FFSM_STACK_H

#include "FFSM_Types.h"

int FFSM_Stack_init(FFSM_Stack_t *stack, FFSM_State_t *data, int size);

int FFSM_Stack_push(FFSM_Stack_t *stack, FFSM_State_t state);
FFSM_State_t FFSM_Stack_pop(FFSM_Stack_t *stack);

#endif //FBPFSM_ROOT_FFSM_STACK_H
