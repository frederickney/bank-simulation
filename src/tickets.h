#ifndef TICKETS_H
#define TICKETS_H

#include<semaphore.h>


typedef struct {
	unsigned int count
	sem_t sem_count_id;
	unsigned int current
	sem_t sem_current_id;
	sem_t sem_current_id;
} tickets_t;

tickets_t get_tickets_t()
{
	tickets_t tickets;
	tickets.count = 0;
	tickets.current = 0;
	sem_init(&tickets.sem_count_id, 0, 1);
	sem_init(&tickets.sem_current_id, 0, 1);
	return &tickets;
}

#endif //TICKETS_H