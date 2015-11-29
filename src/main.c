#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"clients.h"
#include"bank.h"
#include"tickets.h"
#include"list.h"
#include"functions.h"

const char *USAGE =
  "usage:\n"
  "%s <number of clients> <probability> <time to serve clients> <number of bankers [optional]>\n";

void display_usage (char *cmd_name) {
  printf(USAGE, cmd_name);
}

int main (int argc, char **argv) {

	char *cmd_name = argv[0];
	if (argc != 4 && argc != 5) {
		display_usage (cmd_name);
		return EXIT_FAILURE;
	}
	// initialising initial value, structures and pointer
	double prob = atof (argv[2]);
	unsigned int serve_time = atoi (argv[3]);
	unsigned int nb_customers = atoi (argv[1]);
	pthread_t *customers;
	pthread_t *banker;
	list_t *customers_list;
	banker_t *bankers_data;
	tickets_t tickets;
	// allocating memory
	customers_list = malloc (sizeof (list_t) * nb_customers);
	// setting data to structures
	tickets = get_tickets_t();
	tickets.serve_time = serve_time;
	sem_init (&(tickets.sem_banker), 0, 0); // initializing semaphore for banker(s) to 0 for waiting for clients
	if (argc == 5) {
		tickets.nb_bankers = atoi (argv[4]);
		tickets.current = (1 - tickets.nb_bankers);
		bankers_data = malloc (sizeof (banker_t) * tickets.nb_bankers);
	}
	else {
		bankers_data = malloc (sizeof (banker_t) * tickets.nb_bankers);
	}
	for (int i = 0; i < tickets.nb_bankers; i++) {
		bankers_data[i].customers_list = customers_list;
    bankers_data[i].tickets = &tickets;
    bankers_data[i].nb_customers = nb_customers;
	}

	// creating customers threads and banker(s) threads
	customers = create_customers (nb_customers, &tickets, prob, customers_list);
	banker = create_banks (bankers_data);

	// waiting for customers threads and banker(s) threads
	for (int i = 0; i < nb_customers; i++) {
		if (pthread_join (customers[i] , NULL) != 0) {
			perror ("Thread join error");
			exit (EXIT_FAILURE);
		}
	}
	if (pthread_join(*banker , NULL) != 0) {
		perror ("Thread join error");
		exit (EXIT_FAILURE);
	}

	// free allocated memory
	free (customers_list);
	free (customers);
	free (banker);
	free (bankers_data);

	return EXIT_SUCCESS;
}