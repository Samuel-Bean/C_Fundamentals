#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int main(int argsc, char **argsv){

	if( (argsc - 1) < 3){
		printf("Error: there are less than 2 operands or an operator\n");
		return -1;
	}

	if( strlen(argsv[1]) != 1){
		printf("Error: the operator is of invalid length\n");
		return -1;
	}


	int first_item_index = 0;	
	int i,j;
	for(j = 2; j < argsc; j++){
		i=0;
		while(argsv[j][i] != '\0'){
			if (!isdigit(argsv[j][i]) && argsv[j][i] != '.' && argsv[j][i] != '-'){
				if(argsv[j][0] == '-' && argsv[j][1] == 'x'){
					break;
				}
				if(argsv[j][0] == '-' && argsv[j][1] == 'h'){
					break;
				}
				if(argsv[j][0] == '-' && argsv[j][1] == 'o'){
					break;
				}


				printf ("Entered input is not a number\n");
				return -1;
			}

			if( j >= 3 && first_item_index == 0){
				first_item_index = j;
			}
			i++;
		}
	}


	int base = 10;
	char * Pend;
	long output;// = strtol(argsv[2],&Pend,10);
	for( i = 3; i < argsc; i++){


		int new_base = 0;
		if(*argsv[i] != '\0'){
			if(*argsv[i] == '-' && argsv[i][1] == 'x')
				new_base = 16;
			if(*argsv[i] == '-' && *argsv[i] == 'o')
				new_base = 8;
			if(*argsv[i] == '-' && *argsv[i] == 'd')
				new_base = 10;
		
			base = new_base;
		}

		if( i == first_item_index ){
			output = strtol(argsv[2],&Pend,base);
		}

		if(new_base == 0){

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
			if(*argsv[1] == '^'){
				output ^= strtol(argsv[i],&Pend,10);
			}else
			if(*argsv[1] == '&'){
				output &= strtol(argsv[i],&Pend,10);
			}else
			if(*argsv[1] == '|'){
				output |= strtol(argsv[i],&Pend,10);
			}else
			if(*argsv[1] == '~'){
				output = ~strtol(argsv[i],&Pend,10);
			}else
			if(*argsv[1] == '%'){
				output = ((int)output) % (int)strtol(argsv[i],&Pend,10);
			}else{
				printf("invalid operator\n");
				return -1;
			}
		}
	}
	printf("%ld\n",output);


}
