//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

//I use direct name for linked stack because of my interest. I'll use more disgusting names
//for sequential stack.

struct Stack_Node
{
	ElementType data;
	struct Stack_Node* next;
};

typedef struct Stack_Node stack_node;

struct Stack_Head
{
	stack_node* rear;  //should points to the first node
	int node_count;
};

typedef struct Stack_Head stack_head;

stack_head* initialize_stack(stack_head* pstack);

bool stack_is_empty(stack_head* pstack);

ElementType stack_top_item(stack_head* pstack);

void push(stack_head* pstack, ElementType elem);

ElementType pop(stack_head* pstack);

int stack_length(stack_head* pstack);

void wipe_stack(stack_head* pstack);