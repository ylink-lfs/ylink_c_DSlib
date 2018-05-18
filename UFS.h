//created by ylink
//E-mail: lfs@live.com
//To use UFS, u need to initialize an array whose index corresponds with father in UFS
//index are calculate from 1
#pragma once
#include "general.h"

struct uFS
{
	int father[MAXSIZE];
	int elem_count;
};

typedef struct uFS UFS;

void initialize_UFS(UFS* pufs, int total_elem);

int find_father(UFS* pufs, int index_to_elem);

void unionize(UFS* pufs, int index_to_elem1, int index_to_elem2);