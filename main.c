/*
 *      Author: Namsoo Kim
 *      File: main.c
 */
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist_mgr.h"
#include "tree_mgr.h"
#include "ll_test.h"

void test1();
void test2();
void test3();

void tree_in_order_print();

int main()
{
	test1();
	test2();
	test3();
	tree_in_order_print();
	return 0;
}

void tree_in_order_print()
{
	int a[] = { 5, 3, 6, 1, 4, 7 };
	int size = sizeof(a) / sizeof(int);

	for(int i = 0; i < size; i++)
	{
		tree_insert(a[i]);
	}

	// print in-order
	tree_print_ascending();

	// print breath-first
	tree_print_breath_first_left_to_right();

	destroy_tree();
}

void test1()
{
	int a[] = { 1, 3, 4, 2, 5 };
	create_list(a, 5);

	print_list();

	// reverse the list
	reverse();

	print_list();

	delete_all();
}

void test2()
{
	int a[] = { 1 };
	create_list(a, 1);

	print_list();

	// reverse the list
	reverse();

	print_list();
	delete_all();
}

void test3()
{
	int a[] = { 1, 1, 2, 3, 3, 4, 5, 2, 1, 9 };
	// delete any dups
	create_list(a, sizeof(a)/sizeof(int));
	print_list();

	remove_dups_wo_extra_buffer();

	print_list();
}


