//
// Created by farrrb on 09-Dec-17.
//

#ifndef FFSM_H__
#define FFSM_H__

#include "FFSM_Types.h"

void FFSM_init(FFSM_t *const self, FFSM_State_t init_state, void *data, FFSM_Stack_t *const stack);
void FFSM_transit(FFSM_t * const self, FFSM_State_t new_state);
void FFSM_dispatchEvent(FFSM_t * const self, FFSM_Event_t event);

#endif // FFSM_H__
