#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"clients.h"
#include"bank.h"
#include"tickets.h"
#include"list.h"

const char *USAGE =
  "usage:\n"
  "%s <number of clients> <probability> <time to serve clients>\n";

void display_usage (char *cmd_name) {
  printf(USAGE, cmd_name);
}

int main (int argc, char **argv) {

	char *cmd_name = argv[0];
	if (argc != 4) {
		display_usage(cmd_name);
		return EXIT_FAILURE;
	}

	double prob = atof(argv[3]);
	unsigned int serve_time = atoi(argv[2]);
	unsigned int nb_customers = atoi(argv[1]);

	pthread_t * customers;
	pthread_t * banker;
	tickets_t tickets = get_tickets_t();
	tickets.serve_time = serve_time;
	tickets.customers_list = malloc (sizeof (list_t) * nb_customers);
	sem_init(&(tickets.sem_banker), 0, 0);
	customers = create_customers(nb_customers, &tickets, prob);
	banker = create_banks(&tickets);

	for (int i = 0; i < nb_customers; i++) {
		if (pthread_join(customers[i] , NULL) != 0) {
			printf("%d\n",i);
			perror("Thread join error");
			exit(EXIT_FAILURE);
		}
	}
	if (pthread_join(*banker , NULL) != 0) {
		perror("Thread join error");
		exit(EXIT_FAILURE);
	}
	free((tickets.customers_list));
	free(customers);
	free(banker);

	return EXIT_SUCCESS;
}