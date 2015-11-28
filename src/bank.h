#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>
#include <unistd.h>
#include"tickets.h"
#include"list.h"

typedef struct {
	list_t *customers_list;
	tickets_t *tickets;
	int nb_customers;
	unsigned int current;
} banker_t;

void *banker (void *argv);

pthread_t *create_banks (banker_t *bankers_data);

#endif //BANK_H