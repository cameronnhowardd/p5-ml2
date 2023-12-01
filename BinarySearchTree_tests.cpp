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
// Test for trees of various sizes, including small (e.g., 1-3 nodes), medium, and large trees.
// Test for trees with different structures (e.g., balanced, left-heavy, right-heavy).
// height_impl:

// Test for an empty tree (should return 0).
// Test for a tree with a single node (should return 1).
// Test for trees of different heights and structures.
// copy_nodes_impl:

// Test copying an empty tree (should return nullptr).
// Test copying non-empty trees, ensuring the structure and data of nodes are the same in the copy.
// Ensure that modifying the copied tree does not affect the original tree (to test deep copy).
// destroy_nodes_impl:

// After calling this function, ensure that all nodes of the tree are deleted.
// You might use tools or techniques for memory leak detection to confirm that no memory leaks occur.
// find_impl:

// Test finding an element that exists in the tree.
// Test finding an element that does not exist in the tree.
// Test finding elements in various positions (root, leaf, middle of the tree).
// Test on an empty tree.
// insert_impl:

// Test inserting into an empty tree.
// Test inserting into a non-empty tree.
// Test inserting a duplicate item (should be prohibited as per your requirement).
// Test the structure of the tree after insertions to ensure the binary search tree property is maintained.
// min_element_impl and max_element_impl:

// Test finding the minimum and maximum in an empty tree (should return nullptr).
// Test in a tree with one node (should return the root node for both).
// Test in larger trees, ensuring the correct minimum and maximum nodes are returned.
// check_sorting_invariant_impl:

// Test on an empty tree (should return true).
// Test on a correctly sorted tree (should return true).
// Test on a tree that violates the binary search tree properties (should return false).
// traverse_inorder_impl and traverse_preorder_impl:

// Test traversal on an empty tree (should not print anything).
// Test on non-empty trees and verify the output order is correct for in-order and pre-order traversals, respectively.
// min_greater_than_impl:

// Test finding the smallest element greater than a given value in various scenarios including when such an element exists, when it doesn't exist, and in an empty tree.


TEST_MAIN()
