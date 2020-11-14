
//other lib headers
#include <assert.h>
#include <memory>

//your lib headers
#include "bst.hpp"
using namespace BinarySearchTree;

// some helper functions to construct the graph

void link_left_node_to_parent(BSTNode& child, BSTNode& parent)
{
    child.parent = &parent;
    parent.left_child = &child;
}

void link_right_node_to_parent(BSTNode& child, BSTNode& parent)
{
    child.parent = &parent;
    parent.right_child = &child;
}


int main(int, char**) 
{

    // create a bst graph

    BSTNode root_node { 15 };

    BSTNode left_node { 6 };
    link_left_node_to_parent(left_node, root_node);

        BSTNode left_node_1 { 3 };
        link_left_node_to_parent(left_node_1, left_node);

            BSTNode left_node_1_1 { 2 };
            link_left_node_to_parent(left_node_1_1, left_node_1);

            BSTNode right_node_1_1 { 4 };
            link_right_node_to_parent(right_node_1_1, left_node_1);

        BSTNode right_node_2 { 7 };
        link_right_node_to_parent(right_node_2, left_node);

            BSTNode right_node_2_1 { 13 };
            link_right_node_to_parent(right_node_2_1, right_node_2);

                BSTNode left_node_2_1 { 9 };
                link_left_node_to_parent(left_node_2_1, right_node_2_1);

    BSTNode right_node { 18 };
    link_right_node_to_parent(right_node, root_node);

        BSTNode left_node_3 { 17 };
        link_left_node_to_parent(left_node_3, right_node);

        BSTNode right_node_3 { 20 };
        link_right_node_to_parent(right_node_3, right_node);


    //  ---- do some fun things

    BSTNode* max = maximum(&root_node);
    printf("max key: %i \n", max->key);

    BSTNode* min = minimum(&root_node);
    printf("min key: %i \n", min->key);

    printf("---- tree ---- \n");
    print_in_order_tree_walk(&root_node);
    printf("\n---- end tree ---- \n");

    {
        BSTNode* s = successor(&root_node);
        printf("root_node: %i successor: %i \n", root_node.key, s->key);
    }

    {
        BSTNode* p = predecessor(&left_node_3);
        printf("root_node: %i predecessor: %i \n", left_node_3.key, p->key);
    }

    printf("inserting nodes in to tree");
    BSTNode new_node { 14 };
    insert(&root_node, &new_node);

    BSTNode new_node_1 { 1 };
    insert(&root_node, &new_node_1);

    BSTNode new_node_2 { 200 };
    insert(&root_node, &new_node_2);
    
    BSTNode new_node_3 { 50 };
    insert(&root_node, &new_node_3);

    BSTNode new_node_4 { 74 };
    insert(&root_node, &new_node_4);

    printf("---- tree ---- \n");
    print_in_order_tree_walk(&root_node);
    printf("\n---- end tree ---- \n");
    


}