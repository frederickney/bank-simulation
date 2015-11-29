#include"clients.h"
#include"tickets.h"
#include"list.h"

void *customer (void *argv) {
	//TODO customer
	customers_t *customer_data = (customers_t *) argv;
	int current_tmp;
	int nb_bankers = customer_data->tickets->nb_bankers;
	while (true) {
		customer_data->customer->in_bank = 0;
		sleep(customer_data->tickets->serve_time * random_activity(1, 10));// doing something with random
		//sleep(customer_data->tickets->serve_time * 10); // doing something without random
	entering_into_bank:
		customer_data->customer->ticket = get_ticket ((customer_data->tickets)); // taking ticket
		current_tmp = get_current ((customer_data->tickets)); // taking current ticket
		if (current_tmp < 0) {
			initialize (customer_data->tickets);
			//printf("%d wait %d\n", get_waiting_customers (customer_data->tickets), current_tmp);
			sem_wait (&(customer_data->tickets->initializing_bank));
		}
		if ((customer_data->customer->ticket - current_tmp) > (3 * nb_bankers)) {
		  if (random_prob() < customer_data->prob) {
				sleep (customer_data->tickets->serve_time * (customer_data->customer->ticket - current_tmp) / nb_bankers);// doing something
				if (customer_data->customer->ticket < get_current ((customer_data->tickets))) {
					goto entering_into_bank; // for if the customer need to change ticket
				}
			}
		}
		customer_data->customer->in_bank = 1;
		sem_post (&(customer_data->tickets->sem_banker)); // calling the banker(s)
		sem_wait (&(customer_data->customer->sem_customer)); //waiting for been served
	}
	// free allocated memory for one of array of customers_t
	free(customer_data);
}

pthread_t *create_customers (int nb_customers, tickets_t *tickets, double prob, list_t *customers_list) {
	// initialising array and allocating memory for customers_t structure
	customers_t *customer_data;
	customer_data = malloc (sizeof (customers_t) * nb_customers);
	// initialising array and allocating memory for pthread_t structure
	pthread_t *customers;
	customers = malloc (sizeof (pthread_t) * nb_customers);

	for (int i = 0; i < nb_customers; i++) {
	// setting data to customers_t structure
		sem_init(&(customers_list[i].sem_customer), 0, 0);
		customers_list[i].in_bank = 0;
	  customer_data[i].tickets = tickets;
	  customer_data[i].prob = prob;
	  customer_data[i].customer = &(customers_list[i]);
	  //creating customers threads
		if (pthread_create(&customers[i], NULL, customer, (void *) &customer_data[i]) != 0) {
			perror ("Thread creation error");
			exit(EXIT_FAILURE);
		}
	}

	return customers;
}