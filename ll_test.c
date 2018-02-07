/*
 * ll_test.c
 *
 *  Created on: Feb 1, 2018
 *      Author: nskim
 */
#include "linkedlist_mgr.h"
#include "ll_test.h"

void create_list(int *nums, int size)
{
	for(int i = 0; i < size; i++)
	{
		insert_entry(nums[i]);
	}
}
