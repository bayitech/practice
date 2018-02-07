/*
 * tree_mgr.h
 *
 *  Created on: Feb 6, 2018
 *      Author: nskim
 */

#ifndef TREE_MGR_H_
#define TREE_MGR_H_

typedef struct _tree_node_
{
	int value;
	struct _tree_node_ *left;
	struct _tree_node_ *right;
} tree_node_s;

extern void destroy_tree();
extern tree_node_s *tree_find_node(int value);
extern void tree_insert(int value);
extern void tree_print_ascending();
extern void tree_print_breath_first_left_to_right();
extern void tree_print_breath_first_right_to_left();

extern tree_node_s *tree_head;

#endif /* TREE_MGR_H_ */
