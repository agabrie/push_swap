/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:13:18 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/27 17:35:57 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bottom_val(t_stackdata *stack)
{
	t_stack *head;

	head = stack->lst;
	while (head->next)
		head = head->next;
	return (head->value);
}

int	lst_size(t_stackdata *stack)
{
	t_stack *head;
	int		i;

	head = stack->lst;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	lowest_val(t_stackdata *stack)
{
	t_stack	*head;
	int		smallest;

	head = stack->lst;
	smallest = head->value;
	while (head)
	{
		if (head->value < smallest)
			smallest = head->value;
		head = head->next;
	}
	return (smallest);
}

int	highest_val(t_stackdata *stack)
{
	t_stack	*head;
	int		biggest;

	head = stack->lst;
	biggest = head->value;
	while (head)
	{
		if (head->value > biggest)
			biggest = head->value;
		head = head->next;
	}
	return (biggest);
}

int	highest_under(t_stackdata *stack, int val)
{
	t_stack *head;
	int		biggest;

	head = stack->lst;
	biggest = 0;
	while (head)
	{
		if (head->value > biggest)
			if (head->value < val)
				biggest = head->value;
		head = head->next;
	}
	return (biggest);
}

int	find_pos(t_stackdata *stack, int value)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = stack->lst;
	while (head->value != value)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	freestack(t_stackdata *stack)
{
	while (stack->lst)
	{
		free(stack->lst);
		stack->lst = stack->lst->next;
	}
	free(stack->lst);
}

t_stackdata	normalise(t_stackdata *temp, int size, t_stackdata *a)
{
	t_stack	*head;
	t_stack	*node;
	int		i;
	int		j;
	t_stack	*temphold;

	i = 0;
	temphold = temp->lst;
	while (i++ < size)
	{
		j = 1;
		head = a->lst;
		node = a->lst;
		while (j++ < i)
			node = node->next;
		while (head)
		{
			if (head->value > node->value)
				temphold->value--;
			head = head->next;
		}
		temphold = temphold->next;
	}
	freestack(a);
	return (*temp);
}

void	temp_stack(t_stackdata *temp, int size)
{
	int i;

	i = 0;
	temp->lst = NULL;
	while (i++ < size)
		push(temp, size);
	temp->size = lst_size(temp);
}
