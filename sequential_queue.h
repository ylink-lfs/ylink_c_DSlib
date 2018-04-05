//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

struct Sequeue
{
	ElementType data[MAXSIZE];
	int rear_index;
	int front_index;
	int queue_length;
	int enqueue_times;
	int dequeue_times;
};

//psequeue: pointer to sequential queue

typedef struct Sequeue sequeue;

sequeue* initialize_sequeue(sequeue* psequeue);

bool sequeue_is_empty(sequeue* psequeue);

bool sequeue_is_full(sequeue* psequeue);

void en_sequeue(sequeue* psequeue, ElementType elem);

ElementType de_sequeue(sequeue* psequeue);

ElementType get_sequeue_front(sequeue* psequeue);

int sequeue_length(sequeue* psequeue);

void wipe_sequeue(sequeue* psequeue);