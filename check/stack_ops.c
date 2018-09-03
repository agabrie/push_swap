/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:07:25 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/31 12:10:45 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*new_node(int value)
{
	t_stack *node;

	node = (t_stack*)malloc(sizeof(t_stack));
	node->value = value;
	node->next = NULL;
	return (node);
}

int			pop(t_stackdata *list)
{
	int		val;
	t_stack	*temp;

	if (!list->lst)
		return (MIN);
	temp = list->lst;
	list->lst = list->lst->next;
	val = temp->value;
	free(temp);
	list->size = lst_size(list);
	return (val);
}

void		push(t_stackdata *stack, int val)
{
	t_stack *top;

	top = new_node(val);
	top->next = stack->lst;
	stack->lst = top;
	stack->size = lst_size(stack);
}

int			peek(t_stack *top)
{
	if (top)
		return (top->value);
	return (MIN);
}

void		printstack(t_stack *stack)
{
	t_stack *head;
	int		i;
	int		value;
	int		iter;

	head = stack;
	i = 0;
	while (head)
	{
		i++;
		value = peek(head);
		iter = longest_int(stack) - ft_intlen(value);
		if (i % 10 == 0)
			ft_nbrendl_fd(value, 2);
		else
		{
			ft_putnbr_fd(value, 2);
			while (iter-- + 1)
				ft_putchar_fd(' ', 2);
		}
		head = head->next;
	}
	if (i % 10 != 0)
		ft_putchar_fd('\n', 2);
}
