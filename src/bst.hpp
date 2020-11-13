#pragma once

#include <iostream>
#include <vector>

// -----------------------------------------------------
// Binary Search Tree
// -----------------------------------------------------
// Can use search tree as both a dictionary, and as a priority queue
// Basic operations on a binary search tree take time proportional to the height of the tree
// For a complete binary tree with n nodes, such operations run in O(log n) worst-case time.
// If the tree is a linear chain of n nodes, however, the operations take O(n) worst-case time.
// The keys in a binary search tree are always stored in such a way as to satisfy the binary-search-tree property.

// -----------------------------------------------------
// Binary Search Tree Property
// -----------------------------------------------------
// Let x be a node in a binary search tree. 
// If y is a node in the left subtree of x, then y:key <= x:key. 
// If y is a node in the right subtree of x, then y:key >= x:key.

namespace BinarySearchTree {

struct BSTNode
{
public:
    int key = 0;    
    BSTNode* parent = nullptr;
    BSTNode* left_child = nullptr;
    BSTNode* right_child = nullptr;    

public:
    BSTNode(int key) : key(key) {};
};

// prints the binary search tree to the console
// in-order-tree-walk takes o(n) time
constexpr void print_in_order_tree_walk(BSTNode* node)
{
    if(node == nullptr)
        return;

    if(node->left_child != nullptr)
        print_in_order_tree_walk(node->left_child);

    std::cout << node->key << " ";

    if(node->right_child != nullptr)
        print_in_order_tree_walk(node->right_child);
}

// running time is O(h) where h is height of the tree
// on most computers, the iterative version is more efficient
constexpr BSTNode* iterative_tree_search(BSTNode* node, int key)
{
    while(node != nullptr && key != node->key )
    {   
        if(key < node->key)
            node = node->left_child;
        else
            node = node->right_child;
    }
    return node;
}

// this function searches the left side of the tree before the right side
// Note: prefer to use the iterative search function
constexpr BSTNode* non_iterative_tree_search(BSTNode* node, int key)
{
    if(node == nullptr || node->key == key)
        return node;

    if(key < node->key)
        return non_iterative_tree_search(node->left_child, key);
    else
        return non_iterative_tree_search(node->right_child, key);
}

// we can find an element in a binary search tree for the minimum
// by following the left child pointers from the root until we encounter a nullptr
// done in O(h)
constexpr BSTNode* minimum(BSTNode* node)
{
    while(node->left_child != nullptr)
    {
        node = node->left_child;
    }
    return node;
}

// we can find an element in a binary search tree for the maximum
// by following the right child pointers from the root until we encounter a nullptr
constexpr BSTNode* maximum(BSTNode* node)
{
    while(node->right_child != nullptr)
    {
        node = node->right_child;
    }
    return node;
}

// done in O(h)
// find the successor of a node, determined by in-order-tree-walk
// if all the keys are distinct, the successor of a node is the 
// node with the smallest key greater than the node's key
constexpr BSTNode* successor(BSTNode* node)
{

    //if the right subtree is non-empty, 
    //then the successor is the left-most node in node's right subtree

    if ( node->right_child != nullptr )
        return minimum( node->right_child );
    
    // if the right subtree of the node is empty, 
    // and node has a successor, y, then y is the 
    // lowest ancestor of the node who's left child is also an 
    // ancestor of the node

    // we simply go up the tree from the current node until we 
    // encounter a node that is the left child of it's parent

    BSTNode* y = node->parent;

    while ( y != nullptr && node == y->right_child )
    {
        node = y;
        y = y->parent;
    }
    
    return y;
}

constexpr BSTNode* predecessor(BSTNode* node)
{
    return nullptr;
}


}
