#include <iostream>
#include <sstream>
#include <initializer_list>
using namespace std;

template <typename T>

class tree_t
{
	struct node_t {
		node_t * left;
		node_t * right;
		T value;
		
		void help_print(ostream & stream, int u) {
			{
				u++;
				if (right) right->help_print(stream, u);
				for (int i = 0; i < u; i++) stream << "----";
				stream << value << endl;
				if (left) left->help_print(stream, u);
			}
		}
	};

	node_t * root = NULL;

public:
        tree_t() {
		root = NULL;
	}
	
	~tree_t() {
		delete root;
	}
	void insert(T value) {
		node_t * add = new node_t;
		add->value = value;
		add->left = NULL;
		add->right = NULL;
		node_t * head = root;
		if (head == NULL) {
			root = add;
		}
		else {
			for (;;) {
				if (value < head->value) {
					if (head->left == NULL) { head->left = add; break; }
					else { head = head->left; }
				}
				else if (value > head->value) {
					if (head->right == NULL) { head->right = add; break; }
					else { head = head->right; }
				}
				else break;
			}
		}
	}

	tree_t(initializer_list<T> keys)
	{
		root = nullptr;
		for (T i : keys) {
			this->insert(i);
		}
	}

	bool find(T value) const
	{
		bool a = false;
		if (root) {
			node_t *search = root;
			for (;;) {
				if (search->value == value) { a = true; break; }
				if (value < search->value) {
					if (search->left == NULL) { break; }
					search = search->left;
				}
				else if (value > search->value) {
					if (search->right == NULL) { break; }
					search = search->right;
				}
			}
		}
		return a;
	}

	bool remove(T value)
		{
			node_t * pointer = root;
			node_t * parent = NULL;

			while (pointer != NULL && pointer->value != value)
			{
				parent = pointer;
				if (value < pointer->value)
					pointer = pointer->left;
				else
					pointer = pointer->right;
			}

			if (pointer != NULL)
			{
				node_t * removed = NULL;

				if (pointer->left == NULL || pointer->right == NULL)
				{
					node_t * child = NULL;
					removed = pointer;

					if (pointer->left != NULL)
						child = pointer->left;
					else if (pointer->right != NULL)
						child = pointer->right;

					if (parent == NULL)
						root = child;
					else
					{
						if (parent->left == pointer)
							parent->left = child;
						else
							parent->right = child;
					}
				}
				else 
				{
					node_t * mostLeft = pointer->right;
					node_t * mostLeftParent = pointer;

					while (mostLeft->left != NULL)
					{
						mostLeftParent = mostLeft;
						mostLeft = mostLeft->left;
					}

					pointer->value = mostLeft->value;
					removed = mostLeft;

					if (mostLeftParent->left == mostLeft)
						mostLeftParent->left = mostLeft->right;
					else
						mostLeftParent->right = mostLeft->right;
				}
				delete removed;
			}
		if (find(value)) return false;
		else return true;
		}

	auto operator==(tree_t const & other) const
	{
		return help_op( root, other.get_root());

	}
	
	node_t * get_root() const 
       {
        return root;
       }

	bool help_op ( node_t * ptr_1, node_t * ptr_2) const
	{
		if (ptr_1 && ptr_2) {
			if (ptr_1->value == ptr_2->value && help_op(ptr_1->left, ptr_2->left) && help_op( ptr_1->right, ptr_2->right)) return true;
			else return false;
		}
		else if ((ptr_1 == NULL) && (ptr_2 == NULL)) return true;
		else return false;
	}

	void print(ostream & stream) {
		root->help_print(stream, 0);
	}
};
