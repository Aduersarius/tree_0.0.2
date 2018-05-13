#include <catch.hpp>
#include <sstream>
#include "tree.hpp"



TEST_CASE(" insert and print ")
{
    tree_t<int> tree;
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    string str {
        "------------4\n--------3\n----2\n" };
    ostringstream ostream;
    tree.print(ostream);
    REQUIRE(ostream.str()==str);
}

TEST_CASE(" find ")
{
    tree_t<int> tree;
    tree.insert(3);
    tree.insert(5);
    tree.insert(4);
    REQUIRE(tree.find(4)==true);
    REQUIRE(tree.find(10)==false);
}

TEST_CASE(" remove ")
{
    tree_t<int> tree;
    tree.insert(3);
    tree.insert(5);
    tree.insert(4);
    tree.insert(12);
    REQUIRE(tree.find(5)==true);
    tree.remove(5);
    REQUIRE(tree.find(5)==false);
}


TEST_CASE(" print ")
{
    tree_t<float> tree;
    tree.insert(2.3);
    tree.insert(5.4);
    tree.insert(6.8);
    string wait {
        "------------6.8\n"
        "--------5.4\n"
        "----2.3\n" };
    ostringstream ostream;
    tree.print(ostream);
    REQUIRE(ostream.str()==wait);
    tree.insert(1.2);
    string wait2 {
        "------------6.8\n"
        "--------5.4\n"
        "----2.3\n"
        "--------1.2\n" };
    ostream.str("");
    tree.print(ostream);
    REQUIRE(ostream.str() == wait2);
}

TEST_CASE(" compare ")
{
    tree_t<int> tree1;
    tree_t<int> tree2;
    tree1.insert(4);
    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(12);
    tree2.insert(4);
    tree2.insert(5);
    tree2.insert(3);
    tree2.insert(12);
    REQUIRE((tree1==tree2)==true);
    tree1.insert(1);
    tree2.insert(2);
    REQUIRE((tree1==tree2)==false);
}

TEST_CASE(" initializer_list ")
{
    tree_t<int> tree {1,2,4,7,12} ;
    string str {
        "--------------------12\n----------------7\n------------4\n--------2\n----1\n"     };
    ostringstream ostream;
    tree.print(ostream);
    REQUIRE(ostream.str()==str);
}
