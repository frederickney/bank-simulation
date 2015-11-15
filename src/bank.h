#ifndef BANK_H
#define BANK_H

#include<pthread.h>
#include<stdlib.h>
#include"tickets.h"

void *banker(void *argv);

pthread_t *create_banks(tickets_t *tickets);

#endif //BANK_H
