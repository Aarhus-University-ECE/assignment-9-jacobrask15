#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */

extern "C"
{
// Add the header files required to run your main
#include "dfs.h"
}

// File for sandboxing and trying out code

node *make_node(int num, node *left, node *right)
    {
        node *new_node = (node *)malloc(sizeof(node)); /*allocates space in memory*/

        new_node->num = num;
        new_node->lchild = left;
        new_node->rchild = right;
        new_node->visited = false;

        return new_node;
    }


int main(int argc, char **argv)
{
    node *root = make_node (4,
			  make_node (7,
				     make_node (28,
						make_node (77,
							   NULL,
							   NULL),
						make_node (23,
							   NULL,
							   NULL)),
				     make_node (86,
						make_node (3,
							   NULL,
							   NULL),
						make_node (9,
							   NULL,
							   NULL))),
			  make_node (98,
				     NULL,
				     NULL));

    printf("%d", root->lchild->rchild->num);

    return 0;
}