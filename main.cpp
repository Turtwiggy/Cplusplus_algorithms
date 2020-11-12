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

// insert() is used to add a new node to the current BST. If it’s the first time we have added a node, the node we inserted will be a root node.
// tree_search() is used to find a given key in the BST.
// iterative_tree_search()
// minimum() done in O(h)
// maximum() done in O(h)
// successor() done in O(h)
// predecessor() done in O(h) 
// remove() is used to remove a given key from BST.

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

//running time is O(h) where h is height of the tree
//this function searches the left side of the tree before the right side
//Note: prefer to use the iterative search function
BinarySearchTree::Node* tree_search(BinarySearchTree::Node* node, int key)
{
    if(node == nullptr || node->key == key)
        return node;

    if(key < node->key)
        return tree_search(node->left_child, key);
    else
        return tree_search(node->right_child, key);
}

//A rewrite of tree_search
//on most computers, the iterative version is more efficient
BinarySearchTree::Node* iterative_tree_search(BinarySearchTree::Node* node, int key)
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

//we can find an element in a binary search tree for the minimum
//by following the left child pointers from the root until we encounter a nullptr
BinarySearchTree::Node* minimum(BinarySearchTree::Node* node)
{
    while(node->left_child != nullptr)
    {
        node = node->left_child;
    }
    return node;
}

//we can find an element in a binary search tree for the maximum
//by following the right child pointers from the root until we encounter a nullptr
BinarySearchTree::Node* maximum(BinarySearchTree::Node* node)
{
    while(node->right_child != nullptr)
    {
        node = node->right_child;
    }
    return node;
}



}


int main(int, char**) 
{

    //create everything
    BinarySearchTree::Node node;
    node.key = 6;
    BinarySearchTree::Node node_l_0;
    node_l_0.key = 5;

        BinarySearchTree::Node node_l_1;
        node_l_1.key = 2;

        BinarySearchTree::Node node_r_1;
        node_r_1.key = 5;

    BinarySearchTree::Node node_r_0;
    node_r_0.key = 7;

    //link everything
    node.left_child = &node_l_0;
    node.right_child = &node_r_0;

    node_l_0.left_child = &node_l_1;
    node_l_0.right_child = &node_r_1;

    BinarySearchTree::Node* max = maximum(&node);
    printf("max key: %i", max->key);


    //print_in_order_tree_walk(&node);

}