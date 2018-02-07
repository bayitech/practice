/*
 * linkedlist_mgr.c
 *
 *  Created on: Feb 1, 2018
 *      Author: nskim
 */
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist_mgr.h"
#include "ll_test.h"

static node_s *head = NULL;

static int is_entry_has_value(node_s *list, int value)
{
	node_s *iter = list;

	if (iter == NULL)
		return 0;

	while(iter)
	{
		if (iter->value == value)
			return 1;
		iter = iter->next;
	}
	return 0;
}

void remove_dups_wo_extra_buffer()
{
	node_s *target, *prev = head;
	node_s *curr = prev->next;

	if (head->next == NULL)
		return;

	target = head;
	while(target)
	{
		while(curr)
		{
			if (curr->value == target->value)
			{
				// delete current
				prev->next = curr->next;
				free(curr);
				curr = prev->next;
			}
			prev = curr;
			curr = curr->next;
		}

		target = target->next;
		prev = target;
		if (target)
			curr = target->next;
	}
}

void delete_all()
{
	node_s *iter = head;
	node_s *curr = iter;

	if (head == NULL)
		return;

	while(curr)
	{
		iter = iter->next;
		free(curr);
		curr = iter;
	}
	head = NULL;
}

void reverse()
{
	node_s *curr, *prev, *next;

	prev = NULL;
	curr = head;
	next = curr->next;

	while(curr)
	{
		curr->next = prev;
		prev = curr;
		curr = next;
		if (curr)
			next = next->next;
	}
	head = prev;
}

void insert_entry(int value)
{
	node_s *new = malloc(sizeof(*head));
	node_s *iter = head;

	new->value = value;
	new->next = NULL;

	if (head == NULL)
	{
		head = new;
		return;
	}

	// go to the end of list
	while(iter->next)
	{
		iter = iter->next;
	}

	// add it to the end
	iter->next = new;

	return;
}

void delete_entry(int value)
{
	return;
}

void print_list()
{
	node_s *iter = head;

	if (iter == NULL)
	{
		// nothing to print
		return;
	}

	while(iter)
	{
		printf("%d ", iter->value);
		iter = iter->next;
	}

	printf("\n");
}

void print_list_detail()
{
	node_s *iter = head;

	if (iter == NULL)
	{
		// nothing to print
		return;
	}

	while(iter)
	{
		printf("[ptr(%p):v(%d):nxt(%p)]", iter, iter->value, iter->next);
		iter = iter->next;
		if (iter)
			printf(" => ");
	}

	printf("\n");
}
