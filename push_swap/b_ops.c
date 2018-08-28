/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:07:09 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/27 17:30:38 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sb(t_stackdata *b)
{
	t_stack *temp;

	if (b->lst && b->lst->next)
	{
		temp = b->lst;
		b->lst = b->lst->next;
		temp->next = b->lst->next;
		b->lst->next = temp;
		ft_putendl_fd("sb", 1);
	}
	return ;
	
}

void		pb(t_stackdata *a, t_stackdata *b)
{
	t_stack *temp;

	temp = a->lst;
	if (a->lst)
		a->lst = a->lst->next;
	else
		return ;
	temp->next = b->lst;
	b->lst = temp;
}

void		rb(t_stackdata *b)
{
	t_stack *temp;
	t_stack *head;

	head = b->lst;
	temp = b->lst;
	if(b->lst && b->lst->next)
		b->lst = b->lst->next;
	else
		return ;
	if(temp->value > MIN)
	{
		while(head->next)
			head = head->next;
		head->next = temp;
		temp->next = NULL;
	}
	ft_putendl_fd("rb", 1);
}

void		rrb(t_stackdata *b)
{
	t_stack *head;
	t_stack *temp;
	if (b->lst && b->lst->next)
	{
		head = b->lst;
		temp = b->lst;
	}
	else
		return ;
	if (temp->value > MIN)
	{
		while (head->next->next)
			head = head->next;
		b->lst = head->next;
		b->lst->next = temp;
		head->next = NULL;
	}
	ft_putendl_fd("rrb", 1);
}
