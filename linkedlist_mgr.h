/*
 * linkedlist_mgr.h
 *
 *  Created on: Feb 1, 2018
 *      Author: nskim
 */

#ifndef SRC_LINKEDLIST_LINKEDLIST_MGR_H_
#define SRC_LINKEDLIST_LINKEDLIST_MGR_H_

typedef struct _node_
{
	int				value;
	struct _node_ 	*next;
} node_s;

extern void reverse();
extern void add_entry(int value);
extern void delete_entry(int value);
extern node_s *find_entry(int value);
extern void print_list();
extern void print_list_detail();
extern void delete_all();

// from cracking the code
// 2.1 remove dups
extern void remove_dups_wo_extra_buffer();

#endif /* SRC_LINKEDLIST_LINKEDLIST_MGR_H_ */
