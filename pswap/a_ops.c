/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:06:58 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 10:05:22 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_stackdata *a)
{
	t_stack *temp;

	if (a->lst && a->lst->next)
	{
		temp = a->lst;
		a->lst = a->lst->next;
		temp->next = a->lst->next;
		a->lst->next = temp;
	}
	return ;
}

void		pa(t_stackdata *a, t_stackdata *b)
{
	t_stack *temp;

	temp = b->lst;
	if (b->lst)
		b->lst = b->lst->next;
	else
		return ;
	temp->next = a->lst;
	a->lst = temp;
}

void		ra(t_stackdata *a)
{
	t_stack *temp;
	t_stack *head;

	head = a->lst;
	temp = a->lst;
	if (a->lst && a->lst->next)
		a->lst = a->lst->next;
	else
		return ;
	if (temp->value > MIN)
	{
		while (head->next)
			head = head->next;
		head->next = temp;
		temp->next = NULL;
	}
}

void		rra(t_stackdata *a)
{
	t_stack *head;
	t_stack *temp;

	if (a->lst && a->lst->next)
	{
		head = a->lst;
		temp = a->lst;
	}
	else
		return ;
	if (temp->value > MIN)
	{
		while (head->next->next)
			head = head->next;
		a->lst = head->next;
		a->lst->next = temp;
		head->next = NULL;
	}
}
