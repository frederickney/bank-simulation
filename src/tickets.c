#include "tickets.h"

unsigned int get_ticket(tickets_t *ticket)
{
	sem_wait(ticket->sem_count_id);
	return ticket = ticket->sem_count_id++;
	sem_post(ticket->sem_count_id);
}

unsigned int set_current(tickets_t ticket)
{
	sem_wait(ticket->sem_current_id);
	return ticket = ticket->sem_current_id++;
	sem_post(ticket->sem_current_id);
}

unsigned int get_current(tickets_t ticket)
{
	sem_wait(ticket->sem_current_id);
  return ticket = ticket->sem_current_id;
  sem_post(ticket->sem_current_id);
}
