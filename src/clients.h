#ifndef CLIENT_H
#define CLIENT_H

#include<pthread.h>

typedef struct {
	unsigned int ticket;
	unsigned int walking;
	double probability_of_waiting;
} customers_t;

void *customers(void argv);

void create_customers(int nb_customers);

#endif // CLIENT_H