#include <iostream>

//TODO: have 10000 items
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

// TODO operations
// Insert() is used to add a new node to the current BST. If it’s the first time we have added a node, the node we inserted will be a root node.
// PrintTreeInOrder() is used to print all of the keys in the BST, sorted from the smallest key to the greatest key, by a recursive algorithm known as inorder tree walk.
// Search() is used to find a given key in the BST. If the key exists it returns TRUE, otherwise it returns FALSE.
// FindMin() and FindMax() are used to find the minimum key and the maximum key that exist in the BST.
// Successor() and Predecessor() are used to find the successor and predecessor of a given key. We are going to discuss these later in the upcoming section.
// Remove() is used to remove a given key from BST.
}

void print_all(BinarySearchTree::Node* node)
{
    std::cout << "node value: " << node->key << std::endl;

    if(node->left_child != nullptr)
    {
        std::cout << "going left" <<std::endl;
        print_all(node->left_child);
    }

    if(node->right_child != nullptr)
    {
        std::cout << "going right" <<std::endl;
        print_all(node->right_child);
    }
}

int main(int, char**) {


    //create everything
    BinarySearchTree::Node node;
    node.key = 5;
    BinarySearchTree::Node node_l_0;
    node_l_0.key = 4;
    BinarySearchTree::Node node_r_0;
    node_r_0.key = 10;

    //link everything
    node.left_child = &node_l_0;
    node.right_child = &node_r_0;

    print_all(&node);

}