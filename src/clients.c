#include"clients.h"
#include"tickets.h"
#include"list.h"

void *customer(void *argv) {
	customers_t *customer_data = (customers_t *) argv;
	while(true) {
		//TODO customer
		customer_data->customer->ticket = get_ticket((customer_data->tickets));
		printf("%d\n", (customer_data->customer->ticket));
	}
}

pthread_t *create_customers(int nb_customers, tickets_t *tickets, double prob) {

	customers_t *customer_data;
	customer_data = malloc (sizeof (customers_t) * nb_customers);
	pthread_t *customers;

	customers = malloc (sizeof (pthread_t) * nb_customers);

	for (int i = 0; i < nb_customers; i++) {
		sem_init(&(tickets->customers_list[i].sem_customer), 0, 0);
	  customer_data[i].tickets = tickets;
	  customer_data[i].prob = prob;
	  customer_data[i].customer = &(tickets->customers_list[i]);
		if (pthread_create(&customers[i], NULL, customer, (void *) &customer_data[i]) != 0) {
			perror("Thread creation error");
			exit(EXIT_FAILURE);
		}
	}

	return customers;
}