//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "linked_stack.h"

stack_head* initialize_stack(stack_head* pstack)
{
	stack_node* current;
	stack_node* pre;
	if (pstack == NULL)
	{
		pstack = (stack_head*)malloc(sizeof(stack_head));
		pstack->node_count = 0;
		pstack->rear = NULL;
	}
	else if (pstack->rear == NULL)
	{
		pstack->node_count = 0;
	}
	else
	{
		current = pstack->rear;
		while (current)
		{
			pre = current;
			current = current->next;
			free(pre);
		}
		pstack->rear = NULL;
		pstack->node_count = 0;
	}
	return pstack;
}


bool stack_is_empty(stack_head* pstack)
{
	//assume pstack is not NULL
	return pstack->node_count == 0 ? true : false;
}

ElementType stack_top_item(stack_head* pstack)
{
	return pstack->rear->data;
}

void push(stack_head* pstack, ElementType elem)
{
	//assume pstack is not NULL
	stack_node* pnew = (stack_node*)malloc(sizeof(stack_node));
	pnew->data = elem;
	pnew->next = NULL;

	if (pstack->rear == NULL)
	{
		pstack->rear = pnew;
	}
	else
	{
		pnew->next = pstack->rear;
		pstack->rear = pnew;
	}
	pstack->node_count++;
	return;
}

//do not check stack is empty or not, check by programmer
ElementType pop(stack_head* pstack)
{
	ElementType receiver;
	stack_node* temp;
	
	temp = pstack->rear;
	pstack->rear = temp->next;

	receiver = temp->data;
	free(temp);
	pstack->node_count--;
	return receiver;
}

int stack_length(stack_head* pstack)
{
	//assume pstack is not NULL
	return pstack->node_count;
}

void wipe_stack(stack_head* pstack)
{
	stack_node* current;
	stack_node* pre;

	if (pstack == NULL)
	{
		;
	}
	else if (pstack->rear == NULL)
	{
		free(pstack);
	}
	else
	{
		current = pstack->rear;
		while (current)
		{
			pre = current;
			current = current->next;
			free(pre);
		}
		free(pstack);
	}
	return;
}