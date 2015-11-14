#ifndef BANK_H
#define BANK_H

#include<pthread.h>
#include"tickets.h"

void *banker(void argv);

void create_bank(tickets_t tickets);

#endif //BANK_H
