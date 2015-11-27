#ifndef LIST_H
#define LIST_H

#include<semaphore.h>

typedef struct{
	sem_t sem_customer;
	short unsigned int in_bank;
	unsigned int ticket;

} list_t;

#endif //LIST_H