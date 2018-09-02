/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/02 13:48:30 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define RULE(str) {rule(&ps->a, &ps->b, str);ft_putendl(str);/*printbothstacks(&ps->a, &ps->b)*/;continue;}
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

void		dtt(t_ps *ps)
{
	while(!(check_sorted(AS) == 1))
	{
		if ((AB) && (BN->value > B->value) && (A->value > AN->value) && (A->value < ABV))
		{
			col_endl_fd(FRED, "first1", 2);
			RULE("ss");
		}
		if ((AB) && (BN->value < B->value) && (A->value < AN->value) && (AN->value > ABV) && (BBV > BN->value))
		{
			col_endl_fd(FRED, "first2", 2);
			RULE("ss");
		}
		if ((AB) && (B->value < BBV) && (A->value > ABV))
		{
			col_endl_fd(FRED, "first3", 2);
			RULE("rr");
		}
		if ((AA) &&(A->value > AN->value) && (A->value < ABV))
		{
			col_endl_fd(FRED, "first4", 2);
			RULE("sa");
		}
		if ((BB) && (BN->value > B->value))
		{
			col_endl_fd(FRED, "first5", 2);
			RULE("sb");
		}
		if ((AA) &&(AN->value > A->value) && (AN->value > ABV))
		{
			col_endl_fd(FRED, "first6", 2);
			RULE("sa");
		}
		if ((BB) && (B->value < BBV))
		{
			col_endl_fd(FRED, "first7", 2);
			RULE("rb");
		}
		if((AA) && (A->value > ABV))
		{
			col_endl_fd(FRED, "first8", 2);
			RULE("ra");
		}
		RULE("pb");
	}
}


int	checkdoublerule(t_ps *ps)
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
		if (!B || ((ABV > HV(&ps->b))\
		&& (ABV < A->value)))
			RULE("rra");
		if (HV(&ps->b) != B->value)
		{
			if (find_pos(&ps->b, HV(&ps->b)) < (lst_size(&ps->a) / 2))
			{
				while (HV(&ps->b) != B->value)
					RULE("rb");
			}
			else
			{
				while (HV(&ps->b) != B->value)
					RULE("rrb");
			}
		}
		RULE("pa");
	}
	rotate_a_end(ps);
}

int	moves(t_stackdata *stack, int value)
{
	int pos;
	pos = find_pos(stack, value);

	return (pos > lst_size(stack) / 2 ? lst_size(stack) - pos : pos);
}

void	secondhighest(t_ps *ps)
{
	int i;
	i = 0;
	while (i < 2)
	{
		while (i == 0 && B->value != NH(BS))
		{
			if(BHP(NH(BS)) > (lst_size(BS) / 2))
			{
				RULE("rrb");
			}
			else
				RULE("rb");
		}
		if(i == 0 && B->value == NH(BS))
		{
			i++;
			RULE("pa");
		}
		while (i == 1 && B->value != HV(BS))
		{
			if(BHP(HV(BS)) > (lst_size(BS) / 2))
			{
				RULE("rrb");
			}
			else 
				RULE("rb");
		}
		if(i == 1 && B->value == HV(BS))
		{
			i++;
			RULE("pa");
		}
	}
	while(i == 2)
	{
		i++;
		RULE("sa");
	}
	return ;
}

void	backtoa(t_ps *ps)
{
	while (B)
	{
		if ((BB) && moves(BS, HV(BS)) < moves(BS, NH(BS)))
		{

			while (B->value != HV(BS))
			{
				if(BHP(HV(BS)) > (lst_size(BS) / 2))
				{
					RULE("rrb");
				}
				else
				{
					/*if(BHP(HV(BS)) == 1 && BHP(NH(BS)) != 2)
					{
						RULE("sb");
					}*/
					RULE("rb");
				}
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

void	frankenstein(t_ps *ps)
{
	int i;

	i = 0;
	while (!(check_sorted(&ps->a) == 1))
	{
		i++;
		if (checkdoublerule(ps))
			continue;
		if ((AA) && (A->value > ABV))
			RULE("ra");
		if ((AA) && (A->value > AN->value) && (A->value < ABV))
			RULE("sa");
		if ((BB) && (B->value < BBV))
			RULE("rb");
		if ((BB) && (BN->value > B->value))
			RULE("sb");
		if ((AA) && (ABV < A->value) && (ABV < AN->value))
			RULE("rra");
		if ((AA) && (AN->value > A->value) && (AN->value > ABV))
			RULE("sa");
		rotate_b(ps, i);
		RULE("pb");
	}
}

int	closest_in_range(t_stackdata *stack, int size, int sect, int parts)
{
	int closest_top;
	int closest_bottom;
	t_stack *top;
	int pos_top;
	int pos_bot;

	if(stack->lst)
		top = stack->lst;
	else
		return (MIN);
	while(top)
	{
		if (top->value < sect*(size/parts))
		{
			closest_top = top->value;
			closest_bottom = top->value;
			break;
		}
		top = top->next;
	}
	while(top)
	{
		if (top->value < sect*(size/parts))
			closest_bottom = top->value;
		top = top->next;
	}
	pos_top = moves(stack, closest_top);
	pos_bot = moves(stack, closest_bottom);
		return (pos_top < pos_bot ? pos_top : -pos_bot);
}
void		partition(t_ps *ps)
{
	int parts;
	int sect;
	int i;

	i = 0;
	sect = 1;
	parts = (lst_size(&ps->a) > 250 ? 10 : 4);
	while (sect <= parts)
	{
		while (i < RANGE())
		{
			if (A->value <= RANGE())
			{
				i++;
				RULE("pb");
			}
			else
			{
				/*if (closest_in_range(BS, (lst_size(AS)+lst_size(BS)), sect, parts) > 0)
				{
					RULE("rra");
				}
				else*/
					RULE("ra");
			}
		}
		sect++;
	}
}

int			main(int ac, char **av)
{
	t_ps		ps;

	if (ac > 1)
	{
		init(&ps, av, ac);
		if (lst_size(&ps.a) < 20)
		{
			frankenstein(&ps);
			backtoa(&ps);
		}
		else if (lst_size(&ps.a) < 50)
		{
			dtt(&ps);
			backtoa(&ps);
		}
		else
		{
			partition(&ps);
			backtoa(&ps);
		}
		freestack(&ps.a);
	}
	exit(0);
}
