#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
} Node;

Node *new_node(int value){
	Node *res = (Node *)(malloc(sizeof(Node)));
	res->next = NULL;
	res->value = value;
	return res;
}

typedef struct LinkedList{
	Node *start;
} LinkedList;

LinkedList *new_list(){
	LinkedList *res = (LinkedList *)(malloc(sizeof(LinkedList)));
	res->start = NULL;
	return res;
}

void insert_node(LinkedList *list, Node *node){
	if(list->start == NULL){
		list->start = node;
		return;	
	}
	node->next = list->start;
	list->start = node;
}

void delete_node(LinkedList *list, int index){
	if(!index){
		Node *node = list->start;
		list->start = node->next;
		free(node);
		return;	
	}	
	Node *prev = list->start;	
	for(int i = 0; i < index - 1; ++i){
		prev = prev->next;			
	}
	Node *cur = prev->next;
	if(cur->next == NULL){
		prev->next = NULL;
		free(cur);
		return;	
	}
	Node *next = cur->next;
	prev->next = next;
	free(cur);
	return;
}

void print_list(LinkedList *list){
	Node *node = list->start;
	while(node != NULL){
		printf("%d ", node->value);
		node = node->next;	
	}	
}

int main(){
	LinkedList *list = new_list();
	insert_node(list, new_node(4));
	insert_node(list, new_node(1));
	insert_node(list, new_node(3));
	insert_node(list, new_node(1));
	delete_node(list, 1);
	delete_node(list, 2);
	print_list(list);
}
