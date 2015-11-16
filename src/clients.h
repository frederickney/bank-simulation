#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include"tickets.h"

typedef struct {
	unsigned int ticket;
	unsigned int walking;
	double prob;
	tickets_t *tickets;
} customers_t;

void *customers(void *argv);

pthread_t *create_customers(int nb_customers, tickets_t *tickets, double prob);

#endif // CLIENT_H