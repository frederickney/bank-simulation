#include"bank.h"
#include"tickets.h"


void *banker(void *argv) {
	tickets_t *tickets = (tickets_t *) argv;
	while(true) {
		//TODO banker
		for (int i = 0; i < tickets->nb_customers; i++)
		{
			sem_wait(&(tickets->sem_banker));
			printf("%d\n", tickets->customers_list[i].ticket);
			sem_post(&(tickets->customers_list[i].sem_customer));
		}
	}
}

pthread_t *create_banks(tickets_t *tickets) {

	pthread_t *bankers;

	bankers = malloc(sizeof (pthread_t));

	if (pthread_create(bankers, NULL, banker, (void *) tickets) != 0) {
		perror("Thread creation error");
    exit(EXIT_FAILURE);
	}

	return bankers;
}