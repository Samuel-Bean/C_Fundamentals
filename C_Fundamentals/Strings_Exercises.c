#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * String.h @ /usr/include/string.h
 */

 int main(int argsc, char *argsv[]){

	printf("Exercise series 3: Strings\n\n");

	printf("Palindrome w/o spaces\n");

	// Lets concatenate all of the strings!
/*	int a;
	for(a = 1; a < argsc; a++){


	}
*/

	int i;
	for(i = 1; i < argsc ; i++){
		int length = strlen(argsv[i]);
		printf("length: %i\n", length);
		if(length%2 == 1){
//			printf("odd palindrome\n");

			int j = 0;
			int total = (length -1)/2;
			for( j = 0; j < total; j++){
				if( tolower(argsv[i][j]) == tolower(argsv[i][2 * total - j]) ){
					//printf("correct\n");	
				}else{
					printf("This is not a palindrom\n");
					return 0;
				}
			}
		}else{
		
//			printf("even palindrome\n");

			int j = 0;
			int total = length/2;
			for( j = 0; j < total; j++){
				if( tolower(argsv[i][j]) == tolower(argsv[i][2 * total - 1 - j]) ){
					//printf("correct\n");	
				}else{
					printf("This is not a palindrom\n");
					return 0;
				}
			}
		
		}

		printf("That is a palindrom\n");
	}

}
