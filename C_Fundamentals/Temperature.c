#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

float c2k(const float cel);
float f2k(const float fah);
void checkKelvin(float k);

int main(int argsc, char *argsv[]){

	printf("Exercise 2.4\n\n");

	float output = 0.0;
	float input = 0.0;

	if( argsc > 2 ){
		input = strtol(argsv[2], NULL, 10);
	}else{
		printf("Please enter a value to be converted and the operator\n");
		return -1;
	}

	if(errno == EINVAL){
		printf("Error due to an unsupported base value\n");
		return -2;
	}
	if(errno ==  ERANGE){
	
		printf("Error due to the value being out of range!\n");
		return -3;
	}

	if( argsv[1][0] =='c' && argsv[1][1] == '2' && argsv[1][2] == 'k' && argsv[1][3] == '\0'){
		output = c2k(input);
		checkKelvin( output);
		printf("c2k: %s C = %f K\n", argsv[1],output);
	}else
	if( argsv[1][0] =='f' && argsv[1][1] == '2' && argsv[1][2] == 'k' && argsv[1][3] == '\0'){
		output = f2k(input);
		checkKelvin(output);
		printf("f2k: %s F = %f K\n", argsv[1],output);
	}else
		printf("Enter either 'c2k' or 'f2k' \n");

}

float c2k(const float cel){
	
	float kelvin = cel + 273.15;

	return kelvin;
}

float f2k(const float fah){

	float celcius = (fah - 32) * 5 / 9;

	return c2k(celcius);
}

void checkKelvin(float k){
	if(k < 0){
		printf("Temperature is below 0K. That doesn't exist(practically)\n\n");
		exit(-1);	
	}
}


