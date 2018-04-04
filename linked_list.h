//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

struct Node
{
	ElementType data;
	struct Node* next;
};

typedef struct Node node;

struct List_Head
{
	int counter;
	node* next;
};

typedef struct List_Head list_head;

//If list head points to NULL, create head. If list head exists, wipe list to 0 element
list_head* initialize_list(list_head* plist);

bool list_is_empty(list_head* plist);

bool is_last_node(list_head* plist, node* pnode);

bool delete_node(list_head* plist, ElementType element);

node* find_previous(list_head* plist, node* pnode);

//this function guarantees that after insertion, the given element is in the given position
bool insertion(list_head* plist, ElementType element, int position);

void wipe_list(list_head* plist);

node* get_first_node(list_head* plist);

void delete_first_node(list_head* plist);