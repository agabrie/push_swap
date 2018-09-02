/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:20:44 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/02 09:44:43 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_dups(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strequ(av[i], av[j]))
			{
				ERR();
			}
			j++;
		}
		i++;
	}
}

int check_largest(t_stackdata *stack)
{
    t_stack *head;
	t_stack *head2;

    head = stack->lst;
	head2 = stack->lst->next;
    while (head2)
    {
        if (head->value < head2->value)
            return (0);
        else
            head2 = head2->next;
   }
   return (1);
}

int		check_inverted(t_stackdata *a)
{
	t_stack *head;

	head = a->lst;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			head = head->next;
		else
			return(0);
	}
	return(1);
}

void		printbothstacks(t_stackdata *a, t_stackdata *b)
{
	col_str_fd(FCYN, CAT("Stack ", CAT(VAR(a), " : ")), 2);
	ft_nbrendl_fd(lst_size(a), 2);
	printstack(a->lst);
	ft_putendl_fd("", 2);
	col_str_fd(FMAG, CAT("Stack ", CAT(VAR(b), " : ")), 2);
	ft_nbrendl_fd(lst_size(b), 2);
	printstack(b->lst);
	ft_putendl_fd("", 2);
}

int		check_sorted(t_stackdata *a)
{
	t_stack *head;

	head = a->lst;
	while (head && head->next)
	{
		if (head->value < head->next->value && (head->next->value - head->value == 1))
			head = head->next;
		else
            if (check_inverted(a))
			    return (2);
            else
                return (0);
	}
	return (1);
}
