/*
 * main.c
 *
 *  Created on: Feb 1, 2018
 *      Author: nskim
 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_mgr.h"

#include "ll_test.h"

void test1();
void test2();
void test3();

int main()
{
	test1();
	test2();
	test3();
	return 0;
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


