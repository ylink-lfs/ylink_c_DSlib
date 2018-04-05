//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "sequential_list.h"

slist* initialize_slist(slist* plist)
{
	if (plist == NULL)
	{
		plist = (slist*)malloc(sizeof(slist));
		plist->item_count = 0;
	}
	else
	{
		plist->item_count = 0;
	}
	return plist;
}

void wipe_slist(slist* plist)
{
	if (plist == NULL)
	{
		;
	}
	else
	{
		free(plist);
	}
	return;
}

bool slist_is_empty(slist* plist)
{
	//assume plist is not null
	return plist->item_count == 0 ? true : false;
}

//return data in the given position, return data[0] for invalid input
ElementType get_slist_elem(slist* plist, int position)
{
	//assume plist is not null
	if (position >= 1 && position <= MAXSIZE)
	{
		return plist->data[position];
	}
	else
	{
		return plist->data[0];
	}
}

//return position value. 0 result is not found
int search_elem(slist* plist, ElementType elem)
{
	//assume plist is not null
	int i;
	bool fount_out = false;
	for (i = 1; i <= plist->item_count; i++)
	{
		if (plist->data[i] == elem)
		{
			fount_out = true;
			break;
		}
	}
	if (fount_out)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

//guarantee that after insertion, the given element is in the given position
bool slist_insert(slist* plist, ElementType elem, int position)
{
	//assume plist is not null
	int i;
	if (position < 1 || position > MAXSIZE)
	{
		return false;
	}
	if (plist->item_count == MAXSIZE)
	{
		return false;
	}
	for (i = plist->item_count; i >= position + 1; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[position] = elem;
	plist->item_count++;
	return true;
}

bool slist_delete(slist* plist, ElementType elem)
{
	//assume plist is not null
	int pos = search_elem(plist, elem);
	int i;
	if (pos == 0)
	{
		return false;
	}
	else
	{
		for (i = pos + 1; i <= plist->item_count; i++)
		{
			plist->data[i - 1] = plist->data[i];
		}
		plist->item_count--;
		return true;
	}
}