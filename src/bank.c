#include"bank.h"
#include"tickets.h"


void *banker(void *argv){
	tickets_t *tickets = (tickets_t *) argv;
}

pthread_t *create_banks(tickets_t *tickets){
	pthread_t *bankers;
	bankers = malloc(sizeof (pthread_t));
	pthread_create(bankers, NULL, banker, (void *) tickets);
	return bankers;
}
