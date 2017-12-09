//
// Created by farrrb on 09-Dec-17.
//

const char *FFSM_getStrFromEvent(FFSM_Event_t event)
{
  switch (event)
  {
    case FFSM_EVENT_NONE:
      return "FFSM_EVENT_NONE";
    case FFSM_EVENT_ENTRY:
      return "FFSM_EVENT_ENTRY";
    case FFSM_EVENT_EXIT:
      return "FFSM_EVENT_EXIT";
    default:
      return "FFSM_EVENT_USER_SPECIFIC";
  }
}
