#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"

// empty_impl:

// Test that it returns true for a tree with no nodes (i.e., nullptr).
TEST(emptynonodes) {
BinarySearchTree<int> b;
    ASSERT_TRUE(b.empty());
}
// Test that it returns false for a tree with one or more nodes.
TEST(emptywnodes) {
BinarySearchTree<int> b;
b.insert(1);
b.insert(0);
    ASSERT_FALSE(b.empty());
}
// size_impl:

// Test for an empty tree (should return 0).
TEST(sizenonodes) {
BinarySearchTree<int> b;
    ASSERT_TRUE(b.size() == 0);
}
// Test for trees of various sizes, including small (e.g., 1-3 nodes), medium, and large trees.
TEST(smallnodes) {
BinarySearchTree<int> b;
b.insert(1);
b.insert(0);
    ASSERT_TRUE(b.size() == 2);
}

TEST(mediumnodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
    ASSERT_TRUE(b.size() == 25);
}

TEST(largenodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 1000; i++){
    b.insert(i);
}
    ASSERT_TRUE(b.size() == 1000);
}
// Test for trees with different structures (e.g., balanced, left-heavy, right-heavy).
TEST(rightheavynodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 1000; i++){
    b.insert(i);
    
}
b.insert(-1);
    ASSERT_TRUE(b.size() == 1001);
}

TEST(leftheavynodes) {
BinarySearchTree<int> b;
for (int i = 1000; i > 0; i--){
    b.insert(i);
    
}
b.insert(1001);
    ASSERT_TRUE(b.size() == 1001);
}
// height_impl:

// Test for an empty tree (should return 0).
TEST(heightnonodes) {
BinarySearchTree<int> b;
    ASSERT_TRUE(b.height() == 0);
}
// Test for a tree with a single node (should return 1).
TEST(heightonenodes) {
BinarySearchTree<int> b;
b.insert(1);
    ASSERT_TRUE(b.height() == 1);
}
// Test for trees of different heights and structures.
TEST(heightthreenodes) {
BinarySearchTree<int> b;
b.insert(1);
b.insert(-1);
b.insert(2);
    ASSERT_TRUE(b.height() == 2);
}

// TEST(height8nodes) {// insert/sorting problem
// BinarySearchTree<int> b;
// b.insert(4);
// b.insert(3);
// b.insert(5);
// b.insert(2);
// b.insert(6);
// b.insert(7);
// b.insert(4);
//     ASSERT_TRUE(b.height() == 3);
// }
// copy_nodes_impl:

// Test copying an empty tree (should return nullptr).
TEST(copynonodes) {
BinarySearchTree<int> b;
BinarySearchTree<int> a = b;
ASSERT_TRUE(a.size() == 0);
ASSERT_TRUE(a.empty() == true);

}

// Test copying non-empty trees, ensuring the structure and data of nodes are the same in the copy.
TEST(copywnodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int> a = b;
ASSERT_TRUE(a.size() == 25);
ASSERT_TRUE(a.empty() == false);
ASSERT_TRUE(*a.min_element() == 0);

}
// Ensure that modifying the copied tree does not affect the original tree (to test deep copy).
TEST(copywnodesdeep) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int> a = b;
a.insert(26);
ASSERT_TRUE(a.size() == 26);
ASSERT_TRUE(a.empty() == false);
ASSERT_TRUE(b.size() == 25);
ASSERT_TRUE(*b.max_element() == 24);
ASSERT_TRUE(*a.min_element() == 0);

}
// destroy_nodes_impl:

// After calling this function, ensure that all nodes of the tree are deleted.
// You might use tools or techniques for memory leak detection to confirm that no memory leaks occur.
// find_impl:

// Test finding an element that exists in the tree.
TEST(findwnodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int>::Iterator found = b.find(23);
ASSERT_TRUE(found != b.end());
ASSERT_TRUE(*found == 23); 
}
// Test finding an element that does not exist in the tree.
TEST(finddne) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int>::Iterator found = b.find(27);
ASSERT_TRUE(found == b.end());

}
// Test finding elements in various positions (root, leaf, middle of the tree).
TEST(findmultiple) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int>::Iterator found = b.find(0);
BinarySearchTree<int>::Iterator found2 = b.find(1);
BinarySearchTree<int>::Iterator found3 = b.find(20);
ASSERT_TRUE(found == b.begin());
ASSERT_TRUE(*found2 == 1);
ASSERT_TRUE(*found3 == 20);

}
// Test on an empty tree.
TEST(findempty) {
BinarySearchTree<int> b;
BinarySearchTree<int>::Iterator found = b.find(1);
ASSERT_TRUE(found == b.end());
}
// insert_impl:



// Test inserting into a non-empty tree.
TEST(insertmultiple) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
b.insert(26);
ASSERT_TRUE(b.size() == 26);
}
// Test inserting a duplicate item (should be prohibited as per your requirement).
// Test the structure of the tree after insertions to ensure the binary search tree property is maintained.
// min_element_impl and max_element_impl:

// Test finding the minimum and maximum in an empty tree (should return nullptr).
TEST(minmaxempty) {
BinarySearchTree<int> b;
ASSERT_TRUE(b.max_element() == b.end());
ASSERT_TRUE(b.min_element() == b.end());
}
// Test in a tree with one node (should return the root node for both).
TEST(minmaxone) {
BinarySearchTree<int> b;
b.insert(1);
ASSERT_TRUE(*b.max_element() == 1);
ASSERT_TRUE(*b.min_element() == 1);
}
// Test in larger trees, ensuring the correct minimum and maximum nodes are returned.
// check_sorting_invariant_impl:

// Test on an empty tree (should return true).
TEST(sortempty) {
BinarySearchTree<int> b;
ASSERT_TRUE(b.check_sorting_invariant());
}
// Test on a correctly sorted tree (should return true).
// TEST(sortcorrect) {
// BinarySearchTree<int> b;
// for (int i = 0; i < 25; i++){
//     b.insert(i);
// }
// ASSERT_TRUE(b.check_sorting_invariant());
// }
// Test on a tree that violates the binary search tree properties (should return false).
// traverse_inorder_impl and traverse_preorder_impl:

// // Test traversal on an empty tree (should not print anything).
// TEST(traverseempty) {
// BinarySearchTree<int> b;
// std::string correct = b.trave();
// }
// // Test on non-empty trees and verify the output order is correct for in-order and pre-order traversals, respectively.
// // min_greater_than_impl:

// Test finding the smallest element greater than a given value in various scenarios including when such an element exists, when it doesn't exist, and in an empty tree.
TEST(mingreaterall) {
BinarySearchTree<int> b;
ASSERT_TRUE(b.min_greater_than(2) == b.end());
for (int i = 0; i < 25; i++){
    b.insert(i);
}
//ASSERT_TRUE(*b.min_greater_than(2) == 3);
//ASSERT_TRUE(b.min_greater_than(26) == b.end());

}


TEST_MAIN()