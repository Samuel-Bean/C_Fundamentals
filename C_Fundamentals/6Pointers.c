#include <stdio.h>
//#include <stdlib.h>
#define size 100

int buffer[size];
int * begin = buffer;
int * end = buffer;// = &buffer[size-1];
int* write_pointer = buffer;
int* read_pointer = NULL;

int getFilled();
int add( const int data);
int read(int* buffer, int* write_pointer, int* read_pointer);


int main(int argsc, char *argsv[]){

	printf("Chapter 6: 6.6 simple circular buffer\n\n");

	printf("begin: %p \nend: %p\n\n",begin,end);


	printf("we add and get a result: %i\n", add( 6 ));
	printf("we add and get a result: %i\n", add( 6 ));
	printf("Fill count: %i\n",  getFilled());

	return 0;
}

int getFilled( void ){
	int count = ((long)begin - (long)end)/sizeof(int);
	if((int)count < 0){
		count = ((long)end - (long)begin)/sizeof(int);
	}
	return count;
}

int add( const int data){
	if(begin <= write_pointer && end >= write_pointer ){// then we are good.
		*write_pointer = data;

		if( write_pointer == end ){
			write_pointer = begin;
			return 0;
		}else{
			write_pointer+=sizeof(int);
		}
	}else{

		//TODO add circular bit
		return -1;
	}
	return 0;
}

int read(int* buffer, int* write_pointer, int* read_pointer){
	return 0;
}
