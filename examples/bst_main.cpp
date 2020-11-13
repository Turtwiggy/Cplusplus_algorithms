
#include "bst.hpp"

int main(int, char**) 
{

    //create everything
    BinarySearchTree::BSTNode node;
    node.key = 6;
    BinarySearchTree::BSTNode node_l_0;
    node_l_0.key = 5;

        BinarySearchTree::BSTNode node_l_1;
        node_l_1.key = 2;

        BinarySearchTree::BSTNode node_r_1;
        node_r_1.key = 5;

    BinarySearchTree::BSTNode node_r_0;
    node_r_0.key = 7;

    //link everything
    node.left_child = &node_l_0;
    node.right_child = &node_r_0;

    node_l_0.left_child = &node_l_1;
    node_l_0.right_child = &node_r_1;

    BinarySearchTree::BSTNode* max = BinarySearchTree::maximum(&node);
    printf("max key: %i \n", max->key);

    BinarySearchTree::print_in_order_tree_walk(&node);

    //print_in_order_tree_walk(&node);

}