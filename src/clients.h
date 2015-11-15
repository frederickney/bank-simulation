#ifndef CLIENT_H
#define CLIENT_H

#include<pthread.h>
#include<stdlib.h>
#include"tickets.h"

typedef struct {
	unsigned int ticket;
	unsigned int walking;
	double probability_of_waiting;
} customers_t;

void *customers(void *argv);

pthread_t *create_customers(int nb_customers, tickets_t tickets);

#endif // CLIENT_H