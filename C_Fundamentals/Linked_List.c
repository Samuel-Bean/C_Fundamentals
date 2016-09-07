#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct LinkedList{

	int count;
	struct Node *first;

} linkedlist;

typedef struct Node{

	int payload;
	struct Node *previous;
	struct Node *next;

} node;

node* get_node_at_list_index(linkedlist *ll, int index);
int list_insert_after(linkedlist *ll, node *n, int payload);
int list_insert_before(linkedlist *ll, node *n, int i);
int list_count(linkedlist *ll);

void init_linked_list(linkedlist *ll);


int main( int argsc, char *argsv[] ){

	linkedlist *ll = {0,NULL};

	init_linked_list(ll);
	
	int i = 0;

	printf("List size: %i\n", list_count(ll));

	int ercode = list_insert_after(ll, NULL, 1337);

	printf("Added first element. Ercode: %i\n", ercode);
	printf("List size: %i\n", list_count(ll));

	for(i = 1; i<10; i++){
		node *cnode = get_node_at_list_index(ll, i-1);
		
		if(cnode == NULL){
			printf("something went wrong\n");
			exit(0);
		}

		list_insert_after( ll, cnode, i );
		printf("List size: %i\n",list_count( ll ));
	}

	free(ll); // free the linked-list and all of its nodes

}

node* get_node_at_list_index(linkedlist *ll, int index){

	if(ll == NULL)
		return NULL;
	
	if(ll->first == NULL)
		return NULL;
	
	assert(ll != NULL);
	assert(ll->first != NULL);


	int i =0;
	node *current_node = ll->first;
	while( i < index && current_node != NULL ){
		
		if(current_node->next != NULL){
			current_node = current_node->next;
		}else{
			return NULL;
		}
		i++;
	}

	return current_node;
}

void free_node(node *n){
	free(n);
}

void free_linked_list(linkedlist *ll){

	if(ll == NULL)
		return;

	node *next = ll->first;

	while(next != NULL){
		node *temp = next->next;
		free(next);
		next = temp;
	}

	free(ll);

}

void init_linked_list(linkedlist *ll){

	//ll = malloc( sizeof(linkedlist) );
	ll->count = 0;

}

void init_node(node *n){

	n->previous = NULL;
	n->next = NULL;
	n->payload = 0;

}

int list_insert_after(linkedlist *ll, node *n, int i){

	if(ll == NULL)
		return -1;// return an error	
	if( n == NULL ){
		if( ll->first == NULL){ // handle the very first node in the list
			node *no = malloc( sizeof(node) );
			
			no->payload = i;
			no->previous = NULL;
			no->next = NULL;

			ll->first = no;
		}else{
			return -1;// we need an actual destination
		}
	}

	if( ll->first != NULL && n != NULL ){

		int found = 0;

		int i=0;
		node *c = ll->first;
		
		for(i=0; i < ll->count; i++){

			if( c == n ){ // we found the node to insert after

				node *new_n = malloc( sizeof(node) );
				init_node(new_n);
				new_n->payload = i;

				new_n->previous = c;
				new_n->next = c->next;

				c->next->previous = new_n;
				c->next = new_n; // insert the new node after the target

				found = 1;
				break;
			}
		}

		if( found != 1 ){
			return -2; // we didn't find the node to place our data behind! bad input!
		}
	}

	printf("added a node\n");
	ll->count++;
	
	return 0; // return no error

}

int list_count( linkedlist *ll){

	assert( ll != NULL);

	if( ll == NULL ){
		return -1;
	}

	return ll->count;
}


int list_insert_before(linkedlist *ll, node *n, int i){

	if(ll == NULL)
		return -1;// return an error	
	if( n == NULL ){
		if( ll->first == NULL){ // handle the very first node in the list
			node *no = malloc( sizeof(node) );
			
			no->payload = i;
			no->previous = NULL;
			no->next = NULL;

			ll->first = no;
		}else{
			return -1;// we need an actual destination
		}
	}

	if( ll->first != NULL && n != NULL ){

		int found = 0;

		int i=0;
		node *c = ll->first;
		
		for(i=0; i < ll->count; i++){

			if( c == n ){ // we found the node to insert after

				node *new_n = malloc( sizeof(node) );
				init_node(new_n);
				new_n->payload = i;

				new_n->next = c;
				new_n->previous = c->previous;
				
				c->previous->next = new_n;
				c->previous = new_n;

				found = 1;
				break;
			}
		}

		if( found != 1 ){
			return -2; // we didn't find the node to place our data behind! bad input!
		}
	}

	ll->count++;
	
	return 0; // return no error

}
