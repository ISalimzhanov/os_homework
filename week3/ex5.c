#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next, *prev;
} Node;

Node *new_node(int value){
	Node *res = (Node *)(malloc(sizeof(Node)));
	res->next = NULL;
	res->prev = NULL;
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
	list->start->prev = node;
	list->start = node;
}

void delete_node(LinkedList *list, int index){
	if(!index){
		Node *node = list->start;
		node->next->prev = NULL;
		list->start = node->next;
		free(node);
		return;	
	}	
	Node *cur = list->start;	
	for(int i = 0; i < index; ++i){
		cur = cur->next;			
	}
	if(cur->next == NULL){
		cur->prev->next = NULL;	
	} else {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;	
	}
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
