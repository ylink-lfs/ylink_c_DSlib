//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

struct AVL_Node
{
	ElementType data;
	struct AVL_Node* left_branch;
	struct AVL_Node* right_branch;
	int height;
	bool deleted;
};

typedef struct AVL_Node AVL_node;

AVL_node* wipe_AVL(AVL_node* root);

AVL_node* AVL_search(AVL_node* root, ElementType elem);

AVL_node* AVL_min(AVL_node* root);

AVL_node* AVL_max(AVL_node* root);

AVL_node* AVL_insertion(AVL_node* root, ElementType elem);

AVL_node* AVL_deletion(AVL_node* root, ElementType elem);