#include"clients.h"
#include"tickets.h"

void *customer(void *argv)
{
	tickets_t *tickets = (tickets_t *) argv;
}

pthread_t *create_customers(int nb_customers, tickets_t tickets)
{
	pthread_t *customers;
	customers = malloc (sizeof (pthread_t) * nb_customers);
	for (int i = 0; i < nb_customers; i++)
	{
		pthread_create(&customers[i], NULL, customer, (void *) &tickets);
	}
	return customers;
}