#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//long int strtol (const char* str, char** endptr, int base);
 
int main(int argsc, char **argsv){

	if( (argsc - 1) < 3){
		printf("Error: there are less than 2 operands or an operator\n");
		return -1;
	}

	if( strlen(argsv[1]) != 1){
		printf("Error: the operator is of invalid length\n");
		return -1;
	}


	
	int i,j;
	for(j = 2; j < argsc; j++){
		i=0;
		while(argsv[j][i] != '\0'){
				if (!isdigit(argsv[j][i]) && argsv[j][i] != '.'){
					printf ("Entered input is not a number\n");
					return -1;
				}
				i++;
		}
	}




	char * Pend;
	float output = strtol(argsv[2],&Pend,10);
	for( i = 3; i < argsc; i++){
		
		if(*argsv[1] == '+'){
			output += strtol(argsv[i],&Pend,10);
		}else
		if(*argsv[1] == '-'){
			output -= strtol(argsv[i],&Pend,10);
		}else
		if(*argsv[1] == '*'){
			output *= strtol(argsv[i],&Pend,10);
		}else
		if(*argsv[1] == '/'){
			output /= strtol(argsv[i],&Pend,10);
		}else
		if(*argsv[1] == '%'){
			output = ((int)output) % (int)strtol(argsv[i],&Pend,10);
		}else{
			printf("invalid operator\n");
			return -1;
		}
	}
	printf("%f\n",output);


}
