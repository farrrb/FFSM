//
// Created by farrrb on 10-Dec-17.
//

#ifndef TEST_HELPER_H__
#define TEST_HELPER_H__

#include <stdio.h>

#include "FFSM_Types.h"
#include "FFSM_Strings.h"

#define UNUSED_PARAM(par) ((void)(par))

void print_event(FFSM_Event_t event)
{
  printf("\nevent: %s:(%d)", FFSM_getStrFromEvent(event), event);
}

#endif //TEST_HELPER_H__
