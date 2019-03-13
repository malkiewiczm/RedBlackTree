#include "common.hpp"

static void flip_colors(Node* root)
{
	assert(! is_red(root));
	assert(is_red(root->left));
	assert(is_red(root->right));
	root->color = RED;
	root->left->color = BLACK;
	root->right->color = BLACK;
}

void rb_insert(Node *&root, int value)
{
	if (root == nullptr) {
		root = new Node(value);
		return;
	}
	if (value < root->value)
		rb_insert(root->left, value);
	else
		rb_insert(root->right, value);
	// lean left
	if (is_red(root->right) && ! is_red(root->left))
		left_rotate(root);
	// balance 4-node
	if (is_red(root->left) && is_red(root->left->left))
		right_rotate(root);
	// split 4-node
	if (is_red(root->left) && is_red(root->right))
		flip_colors(root);
}
