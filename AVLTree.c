//created by ylink
//E-mail: lfs@live.com
#include <stdlib.h>
#include "linked_stack.h"
#include "AVLTree.h"
#undef ElementType
#define ElementType int


static AVL_node* LL_rotation(AVL_node*);
static AVL_node* RR_rotation(AVL_node*);
static AVL_node* LR_rotation(AVL_node*);
static AVL_node* RL_rotation(AVL_node*);
static int abs_height(int);
static int get_height(AVL_node*);
static int max_height(int, int);

AVL_node* wipe_AVL(AVL_node* root)
{
	if (!root)
	{
		;
	}
	else
	{
		wipe_AVL(root->left_branch);
		wipe_AVL(root->right_branch);
		free(root);
	}
	return NULL;
}

AVL_node* AVL_search(AVL_node* root, ElementType elem)
{
	if (!root || (root->data == elem && root->deleted == true))
	{
		return NULL;
	}
	else if (root->data > elem)
	{
		return AVL_search(root->left_branch, elem);
	}
	else if (root->data < elem)
	{
		return AVL_search(root->right_branch, elem);
	}
	else
	{
		return root;
	}
}

AVL_node* AVL_min(AVL_node* root)
{
	if (!root)
		return NULL;

	stack_head* avl_stack = NULL;
	avl_stack = initialize_stack(avl_stack);
	AVL_node* current = root;
	while (current->left_branch)
	{
		push(avl_stack, current);
		current = current->left_branch;
	}
	while (current->deleted == true)
	{
		current = pop(avl_stack);
	}
	wipe_stack(avl_stack);
	return current;
}

AVL_node* AVL_max(AVL_node* root)
{
	if (!root)
		return NULL;
	stack_head* avl_stack = NULL;
	avl_stack = initialize_stack(avl_stack);
	AVL_node* current = root;
	while (current->right_branch)
	{
		push(avl_stack, current);
		current = current->right_branch;
	}
	while (current->deleted == true)
	{
		current = pop(avl_stack);
	}
	wipe_stack(avl_stack);
	return current;
}

AVL_node* AVL_insertion(AVL_node* root, ElementType elem)
{
	if (!root)
	{
		AVL_node* pnew = (AVL_node*)malloc(sizeof(AVL_node));
		pnew->data = elem;
		pnew->left_branch = pnew->right_branch = NULL;
		pnew->height = 0;
		pnew->deleted = false;
		root = pnew;
	}
	else if (root->data > elem)
	{
		root->left_branch = AVL_insertion(root->left_branch, elem);
		if (abs_height(get_height(root->left_branch) - get_height(root->right_branch)) == 2)
		{
			if (elem < root->left_branch->data)
			{
				root = LL_rotation(root);
			}
			else
			{
				root = LR_rotation(root);
			}
		}
	}
	else if (root->data < elem)
	{
		root->right_branch = AVL_insertion(root->right_branch, elem);
		if (abs_height(get_height(root->left_branch) - get_height(root->right_branch)) == 2)
		{
			if (elem > root->right_branch->data)
			{
				root = RR_rotation(root);
			}
			else
			{
				root = RL_rotation(root);
			}
		}
	}
	else
	{
		if (root->deleted == true)
		{
			root->deleted = false;
		}
	}
	root->height = max_height(get_height(root->left_branch), get_height(root->right_branch)) + 1;
	return root;
}

AVL_node* AVL_deletion(AVL_node* root, ElementType elem)
{
	AVL_node* current = root;
	while (current && current->data != elem)
	{
		if (root->data > elem)
		{
			current = current->left_branch;
		}
		else
		{
			current = current->right_branch;
		}
	}
	if (!current)
	{
		;
	}
	else
	{
		if (current->deleted == true)
		{
			;
		}
		else
		{
			current->deleted = true;
		}
	}
	return root;
}

static AVL_node* LL_rotation(AVL_node* root)
{
	AVL_node* assist = root->left_branch;
	root->left_branch = assist->right_branch;
	assist->right_branch = root;

	assist->height = max_height(get_height(assist->left_branch), get_height(assist->right_branch)) + 1;
	root->height = max_height(get_height(root->left_branch), get_height(root->right_branch)) + 1;
	return assist;
}

static AVL_node* RR_rotation(AVL_node* root)
{
	AVL_node* assist = root->right_branch;
	root->right_branch = assist->left_branch;
	assist->left_branch = root;

	assist->height = max_height(get_height(assist->left_branch), get_height(assist->right_branch)) + 1;
	root->height = max_height(get_height(root->left_branch), get_height(root->right_branch)) + 1;
	return assist;
}

static AVL_node* LR_rotation(AVL_node* root)
{
	root->left_branch = LL_rotation(root->left_branch);
	return RR_rotation(root);
}

static AVL_node* RL_rotation(AVL_node* root)
{
	root->right_branch = RR_rotation(root->right_branch);
	return LL_rotation(root);
}

static int max_height(int h1, int h2)
{
	return h1 > h2 ? h1 : h2;
}

static int abs_height(int h)
{
	return h >= 0 ? h : -h;
}

static int get_height(AVL_node* node)
{
	if (node == NULL)
	{
		return -1;
	}
	else
	{
		return node->height;
	}
}