/*
 * tree_mgr.c
 *
 *  Created on: Feb 6, 2018
 *      Author: nskim
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree_mgr.h"

tree_node_s *tree_head = NULL;
static int size;
static int *heap = NULL;

static void destroy_tree_postorder(tree_node_s *node)
{
	if (node == NULL)
		return;

	destroy_tree_postorder(node->left);
	destroy_tree_postorder(node->right);
	printf("del(%d)\n", node->value);
	free(node);
	node = NULL;
}
void destroy_tree()
{
	// delete the tree using postorder
	destroy_tree_postorder(tree_head);
	if (heap)
	{
		free(heap);
		heap = NULL;
	}
	size = 0;
}


static void tree_to_heap_preorder(tree_node_s *node, int k)
{
	if (node == NULL)
		return;

	heap[k] = node->value;
	tree_to_heap_preorder(node->left, 2*k+1);
	tree_to_heap_preorder(node->right, 2*k+2);
}

static void convert_to_heap()
{
	if (heap)
		free(heap);

	heap = (int*)calloc(1, size * sizeof(int));
	tree_to_heap_preorder(tree_head, 0);
}

void tree_print_breath_first_left_to_right()
{
	// put tree nodes into heap array and then print
	convert_to_heap();

	printf("print breath first\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", heap[i]);
	}
	printf("\n");
	printf("print breath first\n");
}

static void add_node(tree_node_s *node, tree_node_s *target)
{
	if (node == NULL)
		return;

	if (node->value > target->value)
	{
		// go left to add
		if (node->left)
			add_node(node->left, target);
		else
			node->left = target;
	}
	else
	{
		// go right to add
		if (node->right)
			add_node(node->right, target);
		else
			node->right = target;
	}
}

void tree_insert(int value)
{
	tree_node_s *node;
	node = (tree_node_s*) calloc(1, sizeof(*node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	size++;

	if (tree_head == NULL)
	{
		// this was first time adding, we are done
		tree_head = node;
		return;
	}

	add_node(tree_head, node);
}

static void in_order_print(tree_node_s *node)
{
	if (node == NULL)
		return;

	in_order_print(node->left);
	printf("%d ", node->value);
	in_order_print(node->right);
}

void tree_print_ascending()
{
	// do in-order traverse and print
	printf("print ascending\n");
	in_order_print(tree_head);
	printf("\ndone print ascending\n");
}
