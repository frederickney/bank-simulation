#include"clients.h"
#include"tickets.h"

void *customer(void *argv) {
	customers_t *customer_data = (customers_t *) argv;
	while(true) {
	}
}

pthread_t *create_customers(int nb_customers, tickets_t *tickets, double prob) {
	customers_t customer_data[nb_customers];
	pthread_t *customers;
	customers = malloc (sizeof (pthread_t) * nb_customers);
	for (int i = 0; i < nb_customers; i++) {
	  customer_data[i].tickets = tickets;
	  customer_data[i].prob = prob;
		if (pthread_create(&customers[i], NULL, customer, (void *) &customer_data[i]) != 0) {
			perror("Thread creation error");
			exit(EXIT_FAILURE);
		}
	}
	return customers;
}