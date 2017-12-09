//
// Created by farrrb on 09-Dec-17.
//

#include "FFSM.h"

void FFSM_init(FFSM_t * const self, FFSM_State_t init_state, void *data)
{
  if (self)
  {
    self->current_state = FFSM_STATE_NONE;
    self->data = data;
    if (init_state)
    {
      FFSM_transit(self, init_state);
    }
  }
}

void FFSM_transit(FFSM_t * const self, FFSM_State_t new_state)
{
  if (self)
  {
    if (self->current_state)
    {
      self->current_state(FFSM_EVENT_EXIT, self->data);
    }

    self->current_state = new_state;

    if (self->current_state)
    {
      self->current_state(FFSM_EVENT_ENTRY, self->data);
    }
  }
}

void FFSM_sendSignal(FFSM_t * const self, int event)
{
  if (self)
  {
    if (self->current_state != FFSM_STATE_NONE)
    {
      self->current_state(event, self->data);
    }
  }
}
