#include "tree.hpp"
using namespace std;
int main()
{
	char op; int a;
	tree_t<int> tree;
        tree_t<int> tree1{8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	tree_t<int> tree2{8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
  
	tree1.remove(12);
	tree1.remove(8);
	tree1.help_print(cout);
	std::cout << '\n';
  
	cin >> op;
	while (op != 'q') {
		switch (op) {
		case '+':
			cin >> a;
			tree.insert(a);
			tree.help_print(cout);
			break;
		case '?':
			cin >> a;
			cout << tree.find(a) << endl;
			break;
		case '-':
			cin >> a;
			tree.remove(a);
			tree.help_print(cout);
			break;
		case '=':
			tree.help_print(cout);
		}
		cin >> op;
	}
	return 0;
}
