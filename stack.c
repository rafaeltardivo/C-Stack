#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{

	int data;
	struct node* previous;

}*node_ptr;


node_ptr top = NULL;


bool is_empty(){

	return (top == NULL);
}

void display_top(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return;
	}

	printf("\n[%d]\n", top->data);
}

void display(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return;
	}

	node_ptr temp = top;

	printf("\n");

	while(temp->previous != NULL){
		printf("\t[%d]\n", temp->data);
		temp = temp->previous;
	}

	printf("\t[%d]\n", temp->data);
}

bool clear(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return false;
	}

	node_ptr current = top;
	node_ptr previous = NULL;

	while(current->previous != NULL){

		previous = current->previous;
		free(current);
		current = previous;
	}

	top = NULL;

}

bool push(int value){


	node_ptr item = (node_ptr) malloc(sizeof(struct node));

	if(item == NULL)
		return false;

	item->data = value;

	if(top == NULL)
		item->previous = NULL;
	else
		item->previous = top;

	top = item;

	return true;

}

bool pop(){

	if(is_empty()){

		printf("\nThe stack is empty!");
		return false;
	}

	node_ptr temp = top;
	free(top);
	top = temp->previous;

	return true;

}

void main(){

	int option = 0, value = 0;

	do{
		
		printf("\nSTACK Menu\n"
			   "\n1 - Is Empty?"
			   "\n2 - Push"
			   "\n3 - Pop"
			   "\n4 - Show Top"
			   "\n5 - Display elements"
			   "\n6 - Clear stack"
			   "\n\n0 - EXIT\n\n");

		printf("option: ");
		scanf("%d", &option);

		switch(option){

			case 0:
				if(top != NULL)
					clear();
				break;
				
			case 1:
				printf(is_empty() ? "\nTrue\n" : "\nFalse\n");
				break;

			case 2:
				printf("\nInsert a integer value to push: ");
				scanf("%d", &value);
				printf(push(value) ? "\nPushed :)\n" : "\nSomething went wrong :(\n");
				break;

			case 3:
				printf(pop() ? "\nPopped :)\n" : "\nSomething went wrong :(\n");
				break;

			case 4:
				display_top();
				break;

			case 5:
				display();
				break;

			case 6:
				printf(clear() ? "\nCleared :)\n": "\nSomething went wrong :(\n");
				break;

			default:
				printf("\nINVALID OPTION!!!\n");
				break;

		}

	}while(option != 0);

	printf("\n\n** See more at: https://github.com/rafaeltardivo \n\n");
}

