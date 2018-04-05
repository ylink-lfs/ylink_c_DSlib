//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

//use direct name in linked queue ADT

struct Queue_Node
{
	ElementType data;
	struct Queue_Node* next;
};

typedef struct Queue_Node queue_node;

struct Queue_Head
{
	queue_node* front;
	queue_node* rear;
	int queue_length;
};

typedef struct Queue_Head queue_head;

queue_head* initialize_queue(queue_head* pqueue);

bool queue_is_empty(queue_head* pqueue);

ElementType get_queue_front_elem(queue_head* pqueue);

void enqueue(queue_head* pqueue, ElementType elem);

ElementType dequeue(queue_head* pqueue);

int queue_length(queue_head* pqueue);

void wipe_queue(queue_head* pqueue);