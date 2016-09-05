#include <stdio.h>

int main(int argsc, char **argsv){
	printf("Hello World!\n\n\n");
	
	// Exercise 2: Echo Program name
	printf("Exercise #2:\n");
	printf("%s\n", argsv[0] );
	
	// Exercise 3 echo argguments
	printf("Exercise #3:\n");
	int i;
	for(i = 0; i<argsc; i++)
		printf("%s\n", argsv[i]);

	// Exercise 4: Echo Arguments v2
	printf("Exercise #4:\n");
	for(i = 1; i<argsc; i++)
		printf("%s\n", argsv[i]);

	// Exercise 5:
	printf("Exercise #5:\n");
	for(i = argsc-1; i>0; i--)
		printf("%s\n", argsv[i]);



	return 0;
}
