//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

static void h_swap(int* p1, int* p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
	return;
}

void initialize_heap(heap* pheap)
{
	pheap->size = 0;
	pheap->capacity = MAXSIZE + 1;
	pheap->hfield = (int*)malloc(sizeof(int) * (MAXSIZE + 1));
	pheap->hfield[0] = INT_MIN;
	return;
}

int create_heap(heap* pheap, int* src, int total_count)
{
	if(total_count > MAXSIZE)
		return 1;
	for(int i = 0; i < total_count; i++)
	{
		heap_insertion(pheap, src[i]);
	}
	return 0;
}

void heap_insertion(heap* pheap, ElementType elem)
{
	pheap->hfield[++pheap->size] = elem;
	up_adjust(pheap, 1, pheap->size);
	return;
}

ElementType heap_top(heap* pheap)
{
	return pheap->hfield[1];
}

void heap_pop(heap* pheap)
{
	pheap->hfield[1] = pheap->hfield[pheap->size--];
	down_adjust(pheap, 1, pheap->size);
}

void up_adjust(heap* pheap, int lower, int upper)
{
	int father;
	for(father = upper / 2; father >= lower && pheap->hfield[father] < pheap->hfield[upper]; father /= 2, upper /= 2)
	{
		h_swap(&(pheap->hfield[father]), &(pheap->hfield[upper]));
	}
	return;
}

void down_adjust(heap* pheap, int lower, int upper)
{
	int child = lower * 2;
	while(lower * 2 <= upper)
	{
		if(child + 1 <= upper && pheap->hfield[child] < pheap->hfield[child + 1])
			child++;
		if(pheap->hfield[lower] < pheap->hfield[child])
			h_swap(&(pheap->hfield[lower]), &(pheap->hfield[child]));
		lower *= 2;
		child = lower * 2;
	}
	return;
}

void terminate_heap(heap* pheap)
{
	free(pheap->hfield);
	return;
}