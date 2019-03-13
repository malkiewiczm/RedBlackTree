#pragma once

static constexpr bool BLACK = false;
static constexpr bool RED = true;

struct Node {
	Node *left;
	Node *right;
	int value;
	bool color;
	Node(int v) : left { nullptr }, right { nullptr }, value { v }, color { RED } {}
	~Node() {
		if (left)
			delete left;
		if (right)
			delete right;
	}
};

static inline bool is_red(const Node *node)
{
	if (node == nullptr)
		return false;
	return node->color == RED;
}

void right_rotate(Node *&);
void left_rotate(Node *&);
