/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:16:42 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 11:15:24 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define RULE(str) {rule(&ps->a, &ps->b, str);ft_putendl(str);continue;}
#define DRULE(str) {rule(&ps->a, &ps->b, str);ft_putendl(str);return(1);}
#define BS (&ps->b)
#define AS (&ps->a)
#define A (ps->a.lst)
#define B (ps->b.lst)
#define AN (ps->a.lst->next)
#define BN (ps->b.lst->next)
#define AA (A && AN)
#define BB (B && BN)
#define AB (AA && BB)
#define ABV (bottom_val(AS))
#define BBV (bottom_val(BS))
#define HV(stack) (highest_val(stack))
#define LV(stack) (lowest_val(stack))
#define RANGE() (sect * ((lst_size(AS) + lst_size(BS)) / parts))
#define BHP(value) (find_pos(BS, value))
#define NH(stack) (highest_under(stack, HV(stack)))

int		checkdoublerule(t_ps *ps)
{
	if ((AB)\
	&& (BN->value > B->value) && (A->value > AN->value) && (A->value < ABV))
	{
		DRULE("ss");
	}
	if ((AB) && (BN->value < B->value) && (A->value < AN->value)\
	&& (AN->value > ABV) && (BBV > BN->value))
	{
		DRULE("ss");
	}
	if ((AB) && (B->value < BBV) && (A->value > ABV))
	{
		DRULE("rr");
	}
	return (0);
}

void	rotate_a_end(t_ps *ps)
{
	while (ABV != HV(&ps->a))
	{
		if (find_pos(&ps->a, highest_val(&ps->a)) < (lst_size(&ps->a) / 2))
		{
			RULE("ra");
		}
		else
		{
			RULE("rra");
		}
	}
}

void	pushbacktoa(t_ps *ps)
{
	while (B)
	{
		if (HV(&ps->a) < HV(&ps->b))
			RULE("rb");
		if (A->value < HV(&ps->b))
			RULE("ra");
		if (check_largest(&ps->b) && B->value > LV(AS))
			RULE("pa");
		if (!B || ((ABV > HV(&ps->b)) && (ABV < A->value)))
			RULE("rra");
		if (HV(&ps->b) != B->value)
		{
			if (find_pos(&ps->b, HV(&ps->b)) < (lst_size(&ps->a) / 2))
			{
				while (HV(&ps->b) != B->value)
					RULE("rb");
			}
			else
				while (HV(&ps->b) != B->value)
					RULE("rrb");
		}
		RULE("pa");
	}
	rotate_a_end(ps);
}

void	backtoa(t_ps *ps)
{
	while (B)
	{
		if ((BB) && moves(BS, HV(BS)) < moves(BS, NH(BS)))
		{
			while (B->value != HV(BS))
			{
				rotateb(ps, BHP(HV(BS)), (lst_size(BS) / 2));
			}
			RULE("pa");
		}
		else
		{
			if (lst_size(BS) > 2)
				secondhighest(ps);
			else if (B->value != HV(BS))
			{
				RULE("sb");
			}
			else
				RULE("pa");
		}
	}
}

void	rotate_b(t_ps *ps, int i)
{
	int	a;

	if ((A && BB) && A->value < HV(&ps->b) && A->value > LV(&ps->b))
	{
		a = highest_under(&ps->b, A->value);
		if (find_pos(&ps->b, a) < lst_size(&ps->b) / 2)
		{
			while (highest_under(&ps->b, A->value) != B->value)
			{
				++i;
				RULE("rb");
			}
		}
		else
		{
			while (highest_under(&ps->b, A->value) != B->value)
			{
				++i;
				RULE("rrb");
			}
		}
	}
}
