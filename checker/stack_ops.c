/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:07:25 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/30 13:43:18 by agabrie          ###   ########.fr       */
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
	int		i = 0;

	head = stack;
	while (head)
	{
		i++;
		if (i % 10 == 0)
			ft_nbrendl_fd(peek(head), 2);
		else
		{
			ft_putnbr_fd(peek(head), 2);
			ft_putchar_fd(' ', 2);
		}
		head = head->next;
	}
	ft_putchar_fd('\n', 2);
}
