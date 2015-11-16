#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"clients.h"
#include"bank.h"
#include"tickets.h"

int main (int argc, char **argv) {

	pthread_t * customers;
	pthread_t * banker;
	tickets_t tickets = get_tickets_t();
	customers = create_customers(atoi(argv[2]), &tickets);
	banker = create_banks(&tickets);

	for (int i = 0; i < atoi(argv[2]); i++) {
		if (pthread_join(customers[i] , NULL) != 0) {
			perror("Thread join error");
			exit(EXIT_FAILURE);
		}
	}
	if (pthread_join(*banker , NULL) != 0) {
		perror("Thread join error");
		exit(EXIT_FAILURE);
	}
	free(customers);
	free(banker);
	return EXIT_SUCCESS;
}