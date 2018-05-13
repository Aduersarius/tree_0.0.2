#include "tree.hpp"
using namespace std;
int main()
{
	char op; int a;
	tree_t<int> tree;
  
	cin >> op;
	while (op != 'q') {
		switch (op) {
		case '+':
			cin >> a;
			tree.insert(a);
			tree.help_print();
			break;
		case '?':
			cin >> a;
			cout << tree.find(a) << endl;
			break;
		case '-':
			cin >> a;
			tree.remove(a);
			tree.help_print();
			break;
		case '=':
			tree.help_print();
		}
		cin >> op;
	}
	return 0;
}
