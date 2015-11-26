#include "tickets.h"

tickets_t get_tickets_t() {
	tickets_t tickets;
	tickets.count = 1;
	tickets.current = 0;
	sem_init(&tickets.sem_count_id, 0, 1);
	sem_init(&tickets.sem_current_id, 0, 1);
	return tickets;
}
unsigned int get_ticket(tickets_t *tickets) {
	int count;
	sem_wait(&(tickets->sem_count_id));
	count = tickets->count++;
	sem_post(&(tickets->sem_count_id));
	return count;
}

unsigned int set_current(tickets_t *tickets) {
	int current;
	sem_wait(&(tickets->sem_current_id));
	current = tickets->current++;
	sem_post(&(tickets->sem_current_id));
	return current;
}

unsigned int get_current(tickets_t *tickets) {
	int current;
  sem_wait(&(tickets->sem_current_id));
  current = tickets->current;
  sem_post(&(tickets->sem_current_id));
  return current;
}
