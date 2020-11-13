#pragma once

#include <iostream>
#include <vector>

//Can use search tree as both a dictionary, and as a priority queue
//Basic operations on a binary search tree take time proportional to the height of the tree
//For a complete binary tree with n nodes, such operations run in O(log n) worst-case time.
//If the tree is a linear chain of n nodes, however, the operations take O(n) worst-case time.
// The keys in a binary search tree are always stored in such a way as to satisfy the binary-search-tree property:
// Let x be a node in a binary search tree. If y is a node in the left subtree of x, then y:key <= x:key. If y is a node in the right subtree of x, then y:key >= x:key.

// -----------------------------------------------------
// Binary Search Tree
// -----------------------------------------------------

// TODO
// insert() is used to add a new node to the current BST. If it’s the first time we have added a node, the node we inserted will be a root node.
// remove() is used to remove a given key from BST.
// -----------------------------------------------------

namespace BinarySearchTree {

struct BSTNode
{
    int key = 0;    

    BSTNode* parent = nullptr;
    BSTNode* left_child = nullptr;
    BSTNode* right_child = nullptr;
};

//prints the binary search tree to the console
//in-order-tree-walk takes o(n) time
void print_in_order_tree_walk(BSTNode* node);

//running time is O(h) where h is height of the tree
//on most computers, the iterative version is more efficient
BSTNode* iterative_tree_search(BSTNode* node, int key);
//this function searches the left side of the tree before the right side
//Note: prefer to use the iterative search function
BSTNode* non_iterative_tree_search(BSTNode* node, int key);

//we can find an element in a binary search tree for the minimum
//by following the left child pointers from the root until we encounter a nullptr
//done in O(h)
BSTNode* minimum(BSTNode* node);
//we can find an element in a binary search tree for the maximum
//by following the right child pointers from the root until we encounter a nullptr
BSTNode* maximum(BSTNode* node);

//done in O(h)
BSTNode* successor(BSTNode* node);
BSTNode* predecessor(BSTNode* node);

}
