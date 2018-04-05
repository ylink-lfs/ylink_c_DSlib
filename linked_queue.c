//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "linked_queue.h"

queue_head* initialize_queue(queue_head* pqueue)
{
	queue_node* current;
	queue_node* pre;
	if (pqueue == NULL)
	{
		pqueue = (queue_head*)malloc(sizeof(queue_head));
		pqueue->front = pqueue->rear = NULL;
		pqueue->queue_length = 0;
	}
	else if (pqueue->front == NULL)
	{
		pqueue->queue_length = 0;
	}
	else
	{
		current = pqueue->front;
		while (current)
		{
			pre = current;
			current = current->next;
			free(pre);
		}
		pqueue->queue_length = 0;
	}
	return pqueue;
}

bool queue_is_empty(queue_head* pqueue)
{
	return pqueue->queue_length == 0 ? true : false;
}

ElementType get_queue_front_elem(queue_head* pqueue)
{
	//assume queue is not empty
	return pqueue->front->data;
}

void enqueue(queue_head* pqueue, ElementType elem)
{
	queue_node* pnew;
	pnew = (queue_node*)malloc(sizeof(queue_node));
	pnew->data = elem;
	pnew->next = NULL;
	if (pqueue->front == NULL)
	{
		pqueue->front = pqueue->rear = pnew;
	}
	else
	{
		pqueue->rear->next = pnew;
		pqueue->rear = pnew;
	}
	pqueue->queue_length++;
	return;
}

ElementType dequeue(queue_head* pqueue)
{
	queue_node* temp;
	ElementType receiver;

	temp = pqueue->front;
	pqueue->front = temp->next;
	receiver = temp->data;
	free(temp);
	pqueue->queue_length--;
	if (pqueue->queue_length == 0)
	{
		pqueue->front = pqueue->rear = NULL;
	}

	return receiver;
}

int queue_length(queue_head* pqueue)
{
	//assume queue is not empty
	return pqueue->queue_length;
}

void wipe_queue(queue_head* pqueue)
{
	queue_node* current;
	queue_node* pre;
	if (pqueue == NULL)
	{
		;
	}
	else if (pqueue->front == NULL)
	{
		free(pqueue);
	}
	else
	{
		current = pqueue->front;
		while (current)
		{
			pre = current;
			current = current->next;
			free(pre);
		}
		free(pqueue);
	}
	return;
}