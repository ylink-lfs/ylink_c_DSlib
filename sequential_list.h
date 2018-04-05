//created by ylink
//E-mail: lfs@live.com

//to avoid name conflict, sequential list are all called slist in file
//position count from 1 to MAXSIZE
//didnt' set plist->data[0] , so use it for dealing with invalid input
#pragma once
#include <stdbool.h>
#include "general.h"

struct Sequential_List
{
	ElementType data[MAXSIZE + 1];
	int item_count;
};

typedef struct Sequential_List slist;

slist* initialize_slist(slist* plist);

void wipe_slist(slist* plist);

bool slist_is_empty(slist* plist);

ElementType get_slist_elem(slist* plist, int position);

ElementType search_elem(slist* plist, ElementType elem);

bool slist_insert(slist* plist, ElementType elem, int position);

bool slist_delete(slist* plist, ElementType elem);