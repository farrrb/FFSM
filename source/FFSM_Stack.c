//
// Created by farrrb on 10-Dec-17.
//

#include "FFSM_Stack.h"

int FFSM_Stack_init(FFSM_Stack_t *stack, FFSM_State_t *data, int size)
{
  if (stack)
  {
    int i = 0;
    stack->data = data;
    stack->size = size;
    stack->top = 0;

    for (i=0; i < stack->size; i++)
    {
      stack->data[i] = FFSM_STATE_NONE;
    }
    return 0;
  }
  return -1;
}
