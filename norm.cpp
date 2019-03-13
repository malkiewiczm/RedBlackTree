#include "common.hpp"

void norm_insert(Node *&root, int value)
{
	if (root == nullptr) {
		root = new Node(value);
	}
	else if (value < root->value) {
		norm_insert(root->left, value);
	}
	else {
		norm_insert(root->right, value);
	}
}
