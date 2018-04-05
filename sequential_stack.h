//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

struct Sequential_Stack
{
	ElementType data[MAXSIZE];
	int top_index;
	int stack_length;
};

//psestack: pointer to sequential stack
//like stack in assembly language, stack grow from bigger index to smaller index

typedef struct Sequential_Stack sestack;

sestack* initialize_sestack(sestack* psestack);

bool sestack_is_empty(sestack* psestack);

bool sestack_is_full(sestack* psestack);

ElementType sestack_top_item(sestack* psestack);

void push_sestack(sestack* psestack, ElementType elem);

ElementType pop_sestack(sestack* psestack);

int sestack_length(sestack* psestack);

void wipe_sestack(sestack* psestack);