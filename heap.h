//created by ylink
//E-mail: lfs@live.com
#pragma once
#include "general.h"

//assume the followint heap is max heap
struct Heap
{
	int* hfield;
	int size;
	int capacity;
};

typedef struct Heap heap;

void initialize_heap(heap* pheap);

int create_heap(heap* pheap, int* src, int total_count);

void heap_insertion(heap* pheap, ElementType elem);

ElementType heap_top(heap* pheap);

void heap_pop(heap* pheap);

//lower is the lower bound of heap array, upper is the element waiting for adjustment
void up_adjust(heap* pheap, int lower, int upper);

//upper is the upper bound of heap array, lower is the element waiting for adjustment
void down_adjust(heap* pheap, int lower, int upper);

void terminate_heap(heap* pheap);