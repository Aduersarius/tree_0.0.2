#include <catch.hpp>
#include <sstream>
using namespace std;
#include "tree.hpp"

TEST_CASE("insert,print and remove")
{   string input{"------------15\n----------------12\n--------11\n------------8\n----7\n--------4\n----------------3\n------------2\n"};
    string input1{"------------15\n----------------12\n--------11\n----7\n--------4\n----------------3\n------------2\n"};
    std::ostringstream ostream;
    tree_t<int> tree{7,4,11,2,8,15,3,12};
    tree.help_print(ostream);
    cout << "removing 8:";
    tree.remove(8);
    cout << tree.find(8)<<'\n';
    tree.help_print(ostream);
    REQUIRE(input+input1==ostream.str());
   
}
TEST_CASE("compare"){
     
 std::ostringstream ostream;
    tree_t<int> tree{7,4,11,2,8,15,3,12};
    tree_t<int> tree1{7,4,11,2,8,15,3,12};
    ostream<<(tree==tree1?"equal\n":"not equal\n");
    tree1.insert(8);
    tree1.insert(9);
    tree1.insert(15);
    ostream<<(tree==tree1?"equal\n":"not equal\n");
    ostream<<(tree.find(13)? "found succesfully\n":"not found\n");
    REQUIRE("equal\nnot equal\nfound succesfully\n"==ostream.str());

}
