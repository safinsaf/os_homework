#include <stdio.h>
struct Cell{
	int data;
	struct Cell *next;
};

struct List{
	struct Cell head;
};

void print_list(struct List L){
	printf("Function print_list: BEGIN\n");
	struct Cell * it = L.head.next;
	while (it != NULL){
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\nFunction print_list: END\n");
}

void insert_node(struct Cell *old, struct Cell *new){
	new->next = old->next;
	old->next = new;
}

//deletes current_node
void delete_node(struct List *L ,struct Cell *cur){ 
	struct Cell *prev = &(L->head);
	struct Cell *it = L->head.next;

	while (it != NULL){
		if (it == cur){
			prev->next = cur->next;
			cur->next = NULL;
			return;	
		}
		prev = it;
		it = it->next;
	}
}

int main(){
	struct List a;
	a.head.next = NULL;

	struct Cell node1;
	node1.data = 1;
	node1.next = NULL;

	struct Cell node2;
	node2.data = 2;
	node2.next = NULL;

	insert_node (&a.head, &node1);
	insert_node (&a.head, &node2);

	printf("There are two elements in the list\n");
	print_list(a);

	delete_node(&a, &node1);
	
	printf("There is one element in the list\n");
	print_list(a);
}

