
#include "bst.hpp"

namespace BinarySearchTree {

void print_in_order_tree_walk( BSTNode* node )
{
    if(node == nullptr)
        return;

    if(node->left_child != nullptr)
        print_in_order_tree_walk(node->left_child);

    std::cout << "node value: " << node->key << std::endl;

    if(node->right_child != nullptr)
        print_in_order_tree_walk(node->right_child);
}

BSTNode* iterative_tree_search( BSTNode* node, int key)
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

BSTNode* non_iterative_tree_search( BSTNode* node, int key )
{
    if(node == nullptr || node->key == key)
        return node;

    if(key < node->key)
        return non_iterative_tree_search(node->left_child, key);
    else
        return non_iterative_tree_search(node->right_child, key);
}

BSTNode* minimum( BSTNode* node)
{
    while(node->left_child != nullptr)
    {
        node = node->left_child;
    }
    return node;
}

BSTNode* maximum( BSTNode* node)
{
    while(node->right_child != nullptr)
    {
        node = node->right_child;
    }
    return node;
}

//todo this
BSTNode* successor( BSTNode* node)
{
    return nullptr;
}

//todo this
BSTNode* predecessor( BSTNode* node)
{
    return nullptr;
}

}