//created by ylink
//E-mail: lfs@live.com
#pragma once
#include <stdbool.h>
#include "general.h"

//use direct names, and try to write compatible code for later tree ADTs
//there ADTs assume that no same element exist in one BST tree
//add "appear times" field for vital same elements

struct BST_Node
{
	ElementType data;
	struct BST_Node* left_branch;
	struct BST_Node* right_branch;
};

typedef struct BST_Node BST_node;

BST_node* find_min(BST_node* root);

BST_node* find_max(BST_node* root);

BST_node* BST_tree_insertion(BST_node* root, ElementType elem);

BST_node* BST_tree_deletion(BST_node* root, ElementType elem);

BST_node* BST_search(BST_node* root, ElementType elem);

BST_node* wipe_BST(BST_node* root);