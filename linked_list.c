//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "linked_list.h"

list_head* initialize_list(list_head* plist)
{
	if (!plist)
	{
		plist = (list_head*)malloc(sizeof(list_head));
		plist->counter = 0;
		plist->next = NULL;
	}
	else if (plist->next == NULL)
	{
		plist->counter = 0;
	}
	else
	{
		node* current = plist->next;
		node* temp;
		while (current)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		plist->next = NULL;
		plist->counter = 0;
	}
	return plist;
}

bool list_is_empty(list_head* plist)
{
	//assume plist is not NULL
	return plist->next ? false : true;
}

bool is_last_node(list_head* plist, node* pnode)
{
	//assume plist is not NULL
	node* current = plist->next;
	while (current->next)
	{
		current = current->next;
	}
	return current == pnode ? true : false;
}

bool delete_node(list_head* plist, ElementType x)
{
	node* current = plist->next;
	node* pre;
	node* temp;
	while (current && current->data != x)
	{
		current = current->next;
	}

	if (!current)
	{
		return false;
	}
	else if (plist->next == current)
	{
		temp = current;
		plist->next = current->next;
		free(current);
		plist->counter--;
		return true;
	}
	else
	{
		pre = find_previous(plist, current);
		temp = current;
		pre->next = current->next;
		free(current);
		plist->counter--;
		return true;
	}
}

node* find_previous(list_head* plist, node* pnode)
{
	//assume plist is not NULL
	node* current = plist->next;
	while (current && current->next != pnode)
	{
		current = current->next;
	}
	return current;
}

//this function guarantees that after insertion, the given element is in the given position
bool insertion(list_head* plist, ElementType x, int position)
{
	//assume plist is not NULL
	node* current;
	node* pre;
	node* pnew;
	int i;
	if (position <= 0 || position > plist->counter + 1)
	{
		return false;
	}
	else
	{
		pnew = (node*)malloc(sizeof(node));
		pnew->data = x;
		pnew->next = NULL;
		current = plist->next;
		for (i = 1; i < position; i++)
		{
			current = current->next;
		}
		if (current == plist->next)
		{
			pnew->next = current;
			plist->next = pnew;
		}
		else
		{
			pre = find_previous(plist, current);
			pnew->next = current;
			pre->next = pnew;
		}
		plist->counter++;
		return true;
	}
}

void wipe_list(list_head* plist)
{
	if (!plist)
	{
		;
	}
	else if (plist->next == NULL)
	{
		free(plist);
	}
	else
	{
		node* current = plist->next;
		node* temp;
		while (current)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		free(plist);
	}
	return;
}

node* get_first_node(list_head* plist)
{
	//assume plist is not NULL
	return plist->next;
}

void delete_first_node(list_head* plist)
{
	node* temp;
	node* current = plist->next;
	temp = current;
	plist->next = current->next;
	free(current);
	plist->counter--;
	return;
}