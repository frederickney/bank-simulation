#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
#include <unistd.h>
#include"tickets.h"
#include"list.h"
#include"functions.h"

typedef struct {
	double prob;
	tickets_t *tickets;
	list_t *customer;
} customers_t;

void *customers (void *argv);

pthread_t *create_customers (int nb_customers, tickets_t *tickets, double prob, list_t *customers_list);

#endif //CLIENT_H