#include "node.hpp"

void right_rotate(Node *&root)
{
	Node *x = root->left;
	root->left = x->right;
	x->right = root;
	x->color = root->color;
	root->color = RED;
	root = x;
}

void left_rotate(Node *&root)
{
	Node *x = root->right;
	root->right = x->left;
	x->left = root;
	x->color = root->color;
	root->color = RED;
	root = x;
}
