//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

struct Llist_Node
{
	ElementType data;
	struct Llist_Node* next;
};

typedef struct Llist_Node llist_node;

struct Llist_Head
{
	int counter;
	llist_node* next;
};

typedef struct Llist_Head llist_head;

//If list head points to NULL, create head. If list head exists, wipe list to 0 element
llist_head* initialize_llist(llist_head* pllist);

bool llist_is_empty(llist_head* pllist);

bool is_last_llist_node(llist_head* pllist, llist_node* pnode);

bool delete_llist_node(llist_head* pllist, ElementType element);

llist_node* find_previous(llist_head* pllist, llist_node* pnode);

//this function guarantees that after insertion, the given element is in the given position
bool llist_insertion(llist_head* pllist, ElementType element, int position);

void wipe_llist(llist_head* pllist);

llist_node* get_first_llist_node(llist_head* pllist);

void delete_first_llist_node(llist_head* pllist);