//
// Created by farrrb on 10-Dec-17.
//

#include "FFSM_Stack.h"

int FFSM_Stack_init(FFSM_Stack_t *stack, FFSM_State_t *data, unsigned int size, FFSM_State_t root)
{
  if (stack && root)
  {
    int i = 0;
    stack->data = data;
    stack->size = size;
    stack->top = 0;

    for (i=0; i < stack->size; i++)
    {
      stack->data[i] = FFSM_STATE_NONE;
    }
    return FFSM_Stack_push(stack, root);
  }
  return -1;
}

int FFSM_Stack_push(FFSM_Stack_t *stack, FFSM_State_t state)
{
  if (stack)
  {
    if (stack->top < stack->size)
    {
      stack->data[(stack->top)++] = state;
      return 0;
    }
  }
  return -1;
}

FFSM_State_t FFSM_Stack_pop(FFSM_Stack_t *stack)
{
  if (stack)
  {
    if (stack->top > 0)
    {
      return stack->data[--(stack->top)];
    }
    return stack->data[0]; // do not pop the last element, just return it
  }
  return FFSM_STATE_NONE;
}

int FFSM_Stack_getDepth(FFSM_Stack_t *stack)
{
  if (stack)
  {
    return stack->top;
  }
  return -1;
}
