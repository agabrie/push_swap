/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:08:50 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/16 13:28:08 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ss(t_stackdata *a, t_stackdata *b)
{
	sa(a);
	sb(b);
}

void		rr(t_stackdata *a, t_stackdata *b)
{
	ra(a);
	rb(b);
}

void		rrr(t_stackdata *a, t_stackdata *b)
{
	rra(a);
	rrb(b);
}
