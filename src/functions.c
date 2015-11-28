#include"functions.h"

double random_prob() {
	return (double)rand() / RAND_MAX;
}

int random_activity (int min, int max) {
	return (double)rand() / (RAND_MAX / (max - min)) + 1; // + 1 needed having minimum 1 as return
}