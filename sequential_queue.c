//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "sequential_queue.h"

//programmers have responsibility to guarantee the following funcs
//operate a valid queue

sequeue* initialize_sequeue(sequeue* psequeue)
{
	if (psequeue == NULL)
	{
		psequeue = (sequeue*)malloc(sizeof(sequeue));		
	}
	psequeue->dequeue_times = psequeue->enqueue_times = 0;
	psequeue->queue_length = 0;
	psequeue->front_index = psequeue->rear_index = 0;
	return psequeue;
}

bool sequeue_is_empty(sequeue* psequeue)
{
	return psequeue->dequeue_times == psequeue->enqueue_times ? true : false;
}

bool sequeue_is_full(sequeue* psequeue)
{
	return psequeue->enqueue_times - psequeue->dequeue_times >=
		MAXSIZE ? true : false;
}

void en_sequeue(sequeue* psequeue, ElementType elem)
{
	psequeue->enqueue_times++;
	psequeue->queue_length++;
	if (psequeue->enqueue_times - 1 == psequeue->dequeue_times)
	{
		;
	}
	else
	{
		psequeue->rear_index = (psequeue->rear_index + 1) % MAXSIZE;
	}
	psequeue->data[psequeue->rear_index] = elem;
	return;
}

ElementType de_sequeue(sequeue* psequeue)
{
	ElementType receiver;
	psequeue->dequeue_times++;
	psequeue->queue_length--;
	receiver = psequeue->data[psequeue->front_index];
	psequeue->front_index = (psequeue->front_index + 1) % MAXSIZE;
	return receiver;
}

ElementType get_sequeue_front(sequeue* psequeue)
{
	return psequeue->data[psequeue->front_index];
}

int sequeue_length(sequeue* psequeue)
{
	return psequeue->queue_length;
}

void wipe_sequeue(sequeue* psequeue)
{
	free(psequeue);
	return;
}