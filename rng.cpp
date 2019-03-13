#include "common.hpp"
#include "norm.hpp"

static void insert_at_root(Node *&root, int value)
{
	if (root == nullptr) {
		root = new Node(value);
	}
	else if (value < root->value) {
		insert_at_root(root->left, value);
		right_rotate(root);
	}
	else {
		insert_at_root(root->right, value);
		left_rotate(root);
	}
}

void rng_insert(Node *&root, int value)
{
	// the number 5 does not have any special meaning
	// try changing it and see how it affects outcomes
	if (rand() % 5 == 0)
		insert_at_root(root, value);
	else
		norm_insert(root, value);
}
