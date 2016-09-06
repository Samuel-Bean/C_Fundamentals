#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>


int main(int argsc, char *argsv[]){

	if(argsc != 3){
		printf("There should be two inputs!\n\n");
		return -1;
	}

	// Gaurentee the inputs are numbers
	int i;
	for(i = 1; i < argsc; i++){
		int j = 0;
		while( argsv[i][j] != '\0' ){ 
			if( isdigit( argsv[i][j] ) ){
				// do nothing
			}else{
				// we have a problem
				printf("Input %i is not a number!\n", i);
				return -1;
			}
			j++;
		}
	}
	

	long high = strtol(argsv[0],NULL,10);
	long low = strtol(argsv[1],NULL,10);
	long temp;

	if(high < low){
		temp = high;
		high = low;
		low = temp;
	}

	srand(time(NULL));
	long num = rand();

	num = (num%(high-low)) + low;

	printf("num: %ld\n", num);


	return 0;

}
