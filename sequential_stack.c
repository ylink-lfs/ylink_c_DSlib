//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "sequential_stack.h"

sestack* initialize_sestack(sestack* psestack)
{
	if (psestack == NULL)
	{
		psestack = (sestack*)malloc(sizeof(sestack));
	}
	psestack->stack_length = 0;
	psestack->top_index = MAXSIZE;

	return psestack;
}

bool sestack_is_empty(sestack* psestack)
{
	return psestack->stack_length == 0 ? true : false;
}

bool sestack_is_full(sestack* psestack)
{
	return psestack->top_index == 0 ? true : false;
}

ElementType sestack_top_item(sestack* psestack)
{
	return psestack->data[psestack->top_index];
}

void push_sestack(sestack* psestack, ElementType elem)
{
	//assume stack is not full nor empty	
	psestack->data[--(psestack->top_index)] = elem;
	psestack->stack_length++;
}

ElementType pop_sestack(sestack* psestack)
{
	//assume stack is not empty
	psestack->stack_length--;
	return psestack->data[(psestack->top_index)++];
}

int sestack_length(sestack* psestack)
{
	return psestack->stack_length;
}

void wipe_sestack(sestack* psestack)
{
	free(psestack);
}