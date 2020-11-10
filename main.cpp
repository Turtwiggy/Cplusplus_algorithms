#include <iostream>
#include <vector>

// TODO: have 1000000000 items
// search for an item in a (sorted) vector
// search for an item in a hash map
// search for an item in a (sorted) BST
// search for an item in a 
// run the search 50 times
// print out average results

//Can use search tree as both a dictionary, and as a priority queue
//Basic operations on a binary search tree take time proportional to the height of the tree
//For a complete binary tree with n nodes, such operations run in O(log n) worst-case time.
//If the tree is a linear chain of n nodes, however, the operations take O(n) worst-case time.
// The keys in a binary search tree are always stored in such a way as to satisfy the binary-search-tree property:
// Let x be a node in a binary search tree. If y is a node in the left subtree of x, then y:key <= x:key. If y is a node in the right subtree of x, then y:key >= x:key.

namespace BinarySearchTree {
struct Node
{
    int key = 0;    

    Node* parent = nullptr;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
};

// Insert() is used to add a new node to the current BST. If it’s the first time we have added a node, the node we inserted will be a root node.
// Search() is used to find a given key in the BST.
// FindMin() done in O(h)
// FindMax() done in O(h)
// Successor() done in O(h)
// Predecessor() done in O(h) 
// Remove() is used to remove a given key from BST.

//in-order-tree-walk takes o(n) time
void print_in_order_tree_walk(BinarySearchTree::Node* node)
{
    if(node == nullptr)
        return;

    if(node->left_child != nullptr)
        print_in_order_tree_walk(node->left_child);

    std::cout << "node value: " << node->key << std::endl;

    if(node->right_child != nullptr)
        print_in_order_tree_walk(node->right_child);
}

BinarySearchTree* search(BinarySearchTree::Node* node, int key)
{
    if(node == nullptr || node->key == key)
        return node;

    if(key < node->key)
        return search(node->left_child, key);
    else
        return search(node->right_child, key);
}



}


int main(int, char**) 
{



    //print_in_order_tree_walk(&node);

}