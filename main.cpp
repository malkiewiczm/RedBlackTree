#include "common.hpp"
#include "norm.hpp"
#include "rb.hpp"
#include "rng.hpp"

static int height(const Node *root)
{
	if (root == nullptr) {
		return 0;
	} else {
		return std::max(height(root->left), height(root->right)) + 1;
	}
}

static bool contains(const Node *root, int value)
{
	while (root) {
		if (value < root->value)
			root = root->left;
		else if (value > root->value)
			root = root->right;
		else
			return true;
	}
	return false;
}

typedef void(*InsertFunc)(Node *&, int v);

static constexpr int N = 2000;
static int data[N];

static void populate_random()
{
	for (int i = 0; i < N; ++i) {
		data[i] = rand();
	}
}

static void populate_order()
{
	for (int i = 0; i < N; ++i) {
		data[i] = i;
	}
}

static void run_test(InsertFunc insert, const char *name)
{
	Node *root = nullptr;
	for (int i = 0; i < N; ++i) {
		insert(root, data[i]);
	}
	const int h = height(root);
	const char *all_found = "yes";
	for (int i = 0; i < N; ++i) {
		if (! contains(root, data[i])) {
			all_found = "no";
		}
	}
	printf("%s: (height, all_found) = (%d, %s)\n", name, h, all_found);
	if (root) {
		delete root;
	}
}

#define test(func)(run_test((func), #func))

static void bench(const char *const title)
{
	puts(title);
	test(norm_insert);
	test(rng_insert);
	test(rb_insert);
	puts("-------");
}

int main()
{
	srand(time(nullptr));
	populate_random();
	bench("Random data");
	populate_order();
	bench("Ordered data");
}
