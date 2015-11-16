#include "tickets.h"

tickets_t get_tickets_t() {
	tickets_t tickets;
	tickets.count = 0;
	tickets.current = 0;
	sem_init(&tickets.sem_count_id, 0, 1);
	sem_init(&tickets.sem_current_id, 0, 1);
	return tickets;
}
unsigned int get_ticket(tickets_t *ticket) {
	sem_wait(&(ticket->sem_count_id));
	return (ticket->count++);
	sem_post(&(ticket->sem_count_id));
}

unsigned int set_current(tickets_t *ticket) {
	sem_wait(&(ticket->sem_current_id));
	return (ticket->current++);
	sem_post(&(ticket->sem_current_id));
}

unsigned int get_current(tickets_t *ticket) {
	sem_wait(&(ticket->sem_current_id));
  return (ticket->current);
  sem_post(&(ticket->sem_current_id));
}
