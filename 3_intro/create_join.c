#include "common_threads.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct { int a; int b; } myarg_t; 
typedef struct { int x; int y; } myret_t;

void *my_thread(void *arg) {
//	myret_t *value = malloc(sizeof(myret_t));
	myret_t *stack;

	stack -> x = 1;
	stack -> y = 2;

	return (void*) stack;
}

int main(int argc, char* argv[]) {
	pthread_t p;
	myret_t *value;
	myarg_t args = { 10, 20};
	Pthread_create(&p, NULL, my_thread, &args);
	Pthread_join(p, (void **) &value);

	printf("Returned %d %d \n", value -> x, value -> y);

	free(value);
	return 0;
}
