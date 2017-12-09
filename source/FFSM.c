//
// Created by farrrb on 09-Dec-17.
//

#include "FFSM.h"

void FFSM_init(FFSM_t *self, FFSM_State_t init_state)
{
  if (self && init_state)
  {
    self->current_state = init_state;
    init_state(FFSM_SIG_ENTRY);
  }
}

void FFSM_transit(FFSM_t *self, FFSM_State_t new_state)
{
  if (self)
  {
    if (self->current_state)
    {
      self->current_state(FFSM_SIG_EXIT);
    }

    self->current_state = new_state;

    if (self->current_state)
    {
      self->current_state(FFSM_SIG_ENTRY);
    }
  }
}

void FFSM_sendSignal(FFSM_t *self, int signal)
{
  if (self)
  {
    if (self->current_state != FFSM_STATE_NONE)
    {
      self->current_state(signal);
    }
  }
}
