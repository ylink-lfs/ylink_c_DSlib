//created by ylink
//E-mail: lfs@live.com
#include "UFS.h"

void initialize_UFS(UFS* pufs, int total_elem)
{
	pufs->elem_count = total_elem;
	for (int i = 1; i <= total_elem; i++)
	{
		pufs->father[i] = i;
	}
	return;
}

int find_father(UFS* pufs, int index_to_elem)
{
	int res = index_to_elem;
	int cache_begin = index_to_elem;
	while (pufs->father[res] != res)
	{
		res = pufs->father[res];
	}
	
	//I can return res here, but I want to add optimization
	int cache_it = index_to_elem;
	while (pufs->father[cache_it] != cache_it)
	{
		cache_begin = cache_it;
		cache_it = pufs->father[cache_it];
		pufs->father[cache_begin] = res;
	}
	
	return res;
}

void unionize(UFS* pufs, int index_to_elem1, int index_to_elem2)
{
	int root1 = find_father(pufs, index_to_elem1);
	int root2 = find_father(pufs, index_to_elem2);
	if (root1 != root2)
	{
		pufs->father[root2] = root1;
	}
	return;
}