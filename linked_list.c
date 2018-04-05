//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "linked_list.h"

llist_head* initialize_llist(llist_head* pllist)
{
	if (!pllist)
	{
		pllist = (llist_head*)malloc(sizeof(llist_head));
		pllist->counter = 0;
		pllist->next = NULL;
	}
	else if (pllist->next == NULL)
	{
		pllist->counter = 0;
	}
	else
	{
		llist_node* current = pllist->next;
		llist_node* temp;
		while (current)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		pllist->next = NULL;
		pllist->counter = 0;
	}
	return pllist;
}

bool llist_is_empty(llist_head* pllist)
{
	//assume pllist is not NULL
	return pllist->next ? false : true;
}

bool is_last_llist_node(llist_head* pllist, llist_node* pllist_node)
{
	//assume pllist is not NULL
	llist_node* current = pllist->next;
	while (current->next)
	{
		current = current->next;
	}
	return current == pllist_node ? true : false;
}

bool delete_llist_node(llist_head* pllist, ElementType x)
{
	llist_node* current = pllist->next;
	llist_node* pre;
	llist_node* temp;
	while (current && current->data != x)
	{
		current = current->next;
	}

	if (!current)
	{
		return false;
	}
	else if (pllist->next == current)
	{
		temp = current;
		pllist->next = current->next;
		free(current);
		pllist->counter--;
		return true;
	}
	else
	{
		pre = find_previous(pllist, current);
		temp = current;
		pre->next = current->next;
		free(current);
		pllist->counter--;
		return true;
	}
}

llist_node* find_previous(llist_head* pllist, llist_node* pllist_node)
{
	//assume pllist is not NULL
	llist_node* current = pllist->next;
	while (current && current->next != pllist_node)
	{
		current = current->next;
	}
	return current;
}

//this function guarantees that after insertion, the given element is in the given position
bool llist_insertion(llist_head* pllist, ElementType x, int position)
{
	//assume pllist is not NULL
	llist_node* current;
	llist_node* pre;
	llist_node* pnew;
	int i;
	if (position <= 0 || position > pllist->counter + 1)
	{
		return false;
	}
	else
	{
		pnew = (llist_node*)malloc(sizeof(llist_node));
		pnew->data = x;
		pnew->next = NULL;
		current = pllist->next;
		for (i = 1; i < position; i++)
		{
			current = current->next;
		}
		if (current == pllist->next)
		{
			pnew->next = current;
			pllist->next = pnew;
		}
		else
		{
			pre = find_previous(pllist, current);
			pnew->next = current;
			pre->next = pnew;
		}
		pllist->counter++;
		return true;
	}
}

void wipe_llist(llist_head* pllist)
{
	if (!pllist)
	{
		;
	}
	else if (pllist->next == NULL)
	{
		free(pllist);
	}
	else
	{
		llist_node* current = pllist->next;
		llist_node* temp;
		while (current)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		free(pllist);
	}
	return;
}

llist_node* get_first_llist_node(llist_head* pllist)
{
	//assume pllist is not NULL
	return pllist->next;
}

void delete_first_llist_node(llist_head* pllist)
{
	llist_node* temp;
	llist_node* current = pllist->next;
	temp = current;
	pllist->next = current->next;
	free(current);
	pllist->counter--;
	return;
}