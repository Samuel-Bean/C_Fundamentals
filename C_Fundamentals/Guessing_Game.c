#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>

int main(int argsc, char *argsv[]){

	printf("Exercise 4.4: Guessing game\n\n");

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
	

	long high = strtol(argsv[1],NULL,10);
	long low = strtol(argsv[2],NULL,10);
	long temp;

	if(high < low){
		temp = high;
		high = low;
		low = temp;
	}

	srand(time(NULL));
	long num = rand();

	num = (num%(high-low + 1)) + low;

//	printf("num: %ld\n", num);

	printf("start guessing!\n");


	int count = 0;
	int guess = 0;
	while( guess != num){

		char mystring[100];
		char errcode = 0;
	       	fgets(mystring, 100, stdin);

		for(i = 0; i < 100; i++){
			if(mystring[i] == '\0'){
				break;
			}
			/*if(!isdigit(mystring[i])){
				printf("PANIC\n");
				errcode = 1;// PANIC
				break;
			}*/
		}
		if(errcode == 1)
			continue;
		
		guess = strtol(mystring, NULL, 10);

//		printf("\nGuess: %i\n", guess);

		if(errno == ERANGE || errno == EINVAL  || guess == 0){
			continue;
		}

		if( errno != 0 ){
			printf("there has been an error\n");
			exit(-1);
		}

		if(guess > num){
			printf("Too high!\n");
		}
		if(guess < num){
			printf("Too low!\n");
		}
		count++;
	}

	printf("\nYou got it in %i tries!\n",count);

	return 0;

}
