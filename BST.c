#include <stdlib.h>
#include "BST.h"

BST_node* find_min(BST_node* root)
{
	if(!root)
	{
		return NULL;
	}
	else
	{
		if(root->left_branch == NULL)
		{
			return root;
		}
		else
		{
			return find_min(root->left_branch);
		}
	}
}

BST_node* find_max(BST_node* root)
{
	if(!root)
	{
		return NULL;
	}
	else
	{
		if(root->right_branch == NULL)
		{
			return root;
		}
		else
		{
			return find_max(root->right_branch);
		}
	}
}

BST_node* BST_tree_insertion(BST_node* root, ElementType elem)
{
	BST_node* pnew = (BST_node*)malloc(sizeof(BST_node));
	pnew->data = elem;
	pnew->left_branch = pnew->right_branch = NULL;

	if(!root)
	{
		root = pnew;
	}
	else if (root->data > elem)
	{
		root->left_branch = BST_tree_insertion(root->left_branch, elem);
	}
	else if (root->data < elem)
	{
		root->right_branch = BST_tree_insertion(root->right_branch, elem);
	}
	else
	{
		;  //the elemnet already exist, do nothing
	}
	return root;
}

BST_node* BST_tree_deletion(BST_node* root, ElementType elem)
{
	if(!root)
	{
		;
	}
	else if (root->data > elem)
	{
		root->left_branch = BST_tree_deletion(root->left_branch, elem);
	}
	else if (root->data < elem)
	{
		root->right_branch = BST_tree_deletion(root->right_branch, elem);
	}
	else
	{
		BST_node* temp;
		if(root->left_branch && root->right_branch)
		{
			temp = find_min(root->left_branch);
			root->data = temp->data;
			root->right_branch = BST_tree_deletion(root->right_branch, root->data);
		}
		else
		{
			if(root->left_branch == NULL)
			{
				temp = root;
				root = root->right_branch;
				free(temp);
				temp = NULL;
			}
			else
			{
				temp = root;
				root = root->left_branch;
				free(temp);
				temp = NULL;
			}
		}
	}
	return root;
}

BST_node* BST_search(BST_node* root, ElementType elem)
{
	if(!root)
	{
		return NULL;
	}
	else if (root->data > elem)
	{
		return BST_search(root->left_branch, elem);
	}
	else if (root->data < elem)
	{
		return BST_search(root->right_branch, elem);
	}
	else
	{
		return root;
	}
}

BST_node* wipe_BST(BST_node* root)
{
	if(!root)
	{
		return NULL;
	}
	else
	{
		wipe_BST(root->left_branch);
		wipe_BST(root->right_branch);
		free(root);
	}
}