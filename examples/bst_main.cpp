
//other lib headers
#include <assert.h>
#include <memory>

//your lib headers
#include "bst.hpp"

// some helper functions to construct the graph

void link_left_node_to_parent(BinarySearchTree::BSTNode& child, BinarySearchTree::BSTNode& parent)
{
    child.parent = &parent;
    parent.left_child = &child;
}

void link_right_node_to_parent(BinarySearchTree::BSTNode& child, BinarySearchTree::BSTNode& parent)
{
    child.parent = &parent;
    parent.right_child = &child;
}


int main(int, char**) 
{

    // create a bst graph

    BinarySearchTree::BSTNode node { 15 };

    BinarySearchTree::BSTNode left_node { 6 };
    link_left_node_to_parent(left_node, node);

        BinarySearchTree::BSTNode left_node_1 { 3 };
        link_left_node_to_parent(left_node_1, left_node);

            BinarySearchTree::BSTNode left_node_1_1 { 2 };
            link_left_node_to_parent(left_node_1_1, left_node_1);

            BinarySearchTree::BSTNode right_node_1_1 { 4 };
            link_right_node_to_parent(right_node_1_1, left_node_1);

        BinarySearchTree::BSTNode right_node_2 { 7 };
        link_right_node_to_parent(right_node_2, left_node);

            BinarySearchTree::BSTNode right_node_2_1 { 13 };
            link_right_node_to_parent(right_node_2_1, right_node_2);

                BinarySearchTree::BSTNode left_node_2_1 { 9 };
                link_left_node_to_parent(left_node_2_1, right_node_2_1);

    BinarySearchTree::BSTNode right_node { 18 };
    link_right_node_to_parent(right_node, node);

        BinarySearchTree::BSTNode left_node_3 { 17 };
        link_left_node_to_parent(left_node_3, right_node);

        BinarySearchTree::BSTNode right_node_3 { 20 };
        link_right_node_to_parent(right_node_3, right_node);


    //  ---- do some fun things

    BinarySearchTree::BSTNode* max = BinarySearchTree::maximum(&node);
    printf("max key: %i \n", max->key);

    BinarySearchTree::BSTNode* min = BinarySearchTree::minimum(&node);
    printf("min key: %i \n", min->key);

    printf("---- tree ---- \n");
    BinarySearchTree::print_in_order_tree_walk(&node);
    printf("\n---- end tree ---- \n");

    BinarySearchTree::BSTNode* successor = BinarySearchTree::successor(&right_node_2_1);
    printf("node: %i successor: %i \n", right_node_2_1.key, successor->key);

}