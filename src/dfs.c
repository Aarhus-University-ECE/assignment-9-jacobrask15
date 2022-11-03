/*
 * Search an expression using DFS.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */
#include "dfs.h"

void DFT(node *root)
{
  // Implement DFS
  // Hint: You can use print_node, print_tree and/or print_stack.
  stack *min_topp = (stack *)malloc(sizeof(stack)); /*creates stack element that points to top element in actual stack*/
  min_topp->next = NULL;                            /*with no element in stack it should point to NULL*/
  push(min_topp, root);                             /*pushes root onto stack*/

  /*pop stack and print, then push rchild and lchild when they are not NULL. Continue until stack is empty again*/
  while (!(isEmpty(min_topp)))
  {
    stack *temp = pop(min_topp);
    print_node(temp->node);
    if (temp->node->lchild != NULL)
    {
      push(min_topp, temp->node->rchild);
    }
    if (temp->node->rchild)
    {
      push(min_topp, temp->node->lchild);
    }
  }
}

node *make_node(int num, node *left, node *right)
{
  node *new_node = (node *)malloc(sizeof(node)); /*allocates space in memory*/

  /*Places the function inputs in the new node*/
  new_node->num = num;
  new_node->lchild = left;
  new_node->rchild = right;
  new_node->visited = false;

  return new_node;
}

void free_node(node *p)
{
  free(p);
}

void print_node(node *p)
{

  if (p == NULL)
    printf(", NULL\n");
  else
    printf("%d, ", p->num);
}

void print_tree(node *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node)
{
  /*pushes roots children onto stack*/
  stack *new_stack_element = (stack *)malloc(sizeof(stack)); /*Allocates memory to new stack*/

  new_stack_element->node = node;
  new_stack_element->next = topp->next;
  topp->next = new_stack_element;

  /*returns pointer to stack pushed, but is unused by me*/
  return new_stack_element;
}

bool isEmpty(stack *topp)
{
  /*stack is empty when stack elements that points top top elements next points to NULL*/
  if (topp->next == NULL)
    return true;
  else
    return false;
}

node *top(stack *topp)
{
  /*returns the top node*/
  return topp->node;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp)
{
  stack *temp = topp->next;      /*stores element to be popped in a temp pointer*/
  topp->next = topp->next->next; /*topp is now next element in stack*/

  return temp; /*returns element popped*/
}

void print_stack(stack *topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}
