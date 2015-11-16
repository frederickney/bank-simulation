#ifndef TICKETS_H
#define TICKETS_H

#include<semaphore.h>


typedef struct {
	unsigned int count;
	sem_t sem_count_id;
	unsigned int current;
	sem_t sem_current_id;
	unsigned int serve_time;
} tickets_t;

tickets_t get_tickets_t();

unsigned int get_ticket(tickets_t *ticket);

unsigned int set_current(tickets_t *ticket);

unsigned int get_current(tickets_t *ticket);

#endif //TICKETS_H