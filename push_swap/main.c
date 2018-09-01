/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/01 18:19:50 by agabrie          ###   ########.fr       */
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

/*int		dtt(t_stackdata a, t_stackdata b)
{
	while(!(check_sorted(&a) == 1))
	{
		if ((b.lst && b.lst->next && a.lst && a.lst->next) && (b.lst->next->value > b.lst->value) && (a.lst->value > a.lst->next->value) && (a.lst->value < bottom_val(&a)))
		{
			col_endl_fd(FRED, "first1", 2);
			RULE("ss");
		}
		if ((b.lst && b.lst->next && a.lst && a.lst->next) && (b.lst->next->value < b.lst->value) && (a.lst->value < a.lst->next->value) && (a.lst->next->value > bottom_val(&a)) && (bottom_val(&b) > b.lst->next->value))
		{
			col_endl_fd(FRED, "first2", 2);
			RULE("ss");
		}
		if ((b.lst && b.lst->next && a.lst && a.lst->next) && (b.lst->value < bottom_val(&b)) && (a.lst->value > bottom_val(&a)))
		{
			col_endl_fd(FRED, "first3", 2);
			RULE("rr");
		}
		if ((a.lst && a.lst->next) &&(a.lst->value > a.lst->next->value) && (a.lst->value < bottom_val(&a)))
		{
			col_endl_fd(FRED, "first4", 2);
			RULE("sa");
		}
		if ((b.lst && b.lst->next) && (b.lst->next->value > b.lst->value))
		{
			col_endl_fd(FRED, "first5", 2);
			RULE("sb");
		}
		if ((a.lst && a.lst->next) &&(a.lst->next->value > a.lst->value) && (a.lst->next->value > bottom_val(&a)))
		{
			col_endl_fd(FRED, "first6", 2);
			RULE("sa");
		}
		if ((b.lst && b.lst->next) && (b.lst->value < bottom_val(&b)))
		{
			col_endl_fd(FRED, "first7", 2);
			RULE("rb");
		}
		if((a.lst && a.lst->next) && (a.lst->value > bottom_val(&a)))
		{
			col_endl_fd(FRED, "first8", 2);
			RULE("ra");
		}
		RULE("pb");
	}
	if(b.lst)
	{
		if (a->lst->value < highestB)
			RULE("ra");
		if(!b||(bottomval(a) > highestB) && (bottomval(a) < a->lst->value))
			RULE("rra");
		if (highestB != b->lst->value)
		{
			if(HighestPosB < stack_b_size/2)
				RULE("rb");
			else
				RULE("rrb");
		}
		RULE("pa");
	}
	
	return(!(check_sorted(&a) && !b.lst));
}
*/

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
	/*while(!(check_sorted(&ps->a) == 1))
	{
			RULE("pb");
	}
	backtoa(ps);
	*/
}

void	pushbacktoa(t_ps *ps)
{
	col_endl_fd(FGRN, "pushing back", 2);
	while (B)
	{
		if (check_largest(&ps->b))
			RULE("pa");
		if (HV(&ps->a) < HV(&ps->b))
			RULE("rb");
		
		if (A->value < HV(&ps->b))
			RULE("ra");
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
				/*col_str_fd(FRED, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FRED, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FRED, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FRED, " Position of second highest value : ", 2);
				
				ft_nbrendl_fd(BHP(NH(BS)), 2);*/
				if(BHP(NH(BS)) > (lst_size(BS) / 2))
				{RULE("rrb");}
				else {RULE("rb");}
			}
			/*	col_str_fd(FMAG, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FMAG, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FMAG, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FMAG, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);
			*/
			if(i == 0 && B->value == NH(BS))
			{
				i++;
				RULE("pa");
			}
			while (i == 1 && B->value != HV(BS))
			{
				/*col_str_fd(FYEL, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FYEL, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FYEL, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FYEL, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);
				*/
			if(BHP(HV(BS)) > (lst_size(BS) / 2)){RULE("rrb");}
				else {RULE("rb");}
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
				/*col_str_fd(FGRN, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FGRN, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FGRN, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FGRN, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);*/
				if(BHP(HV(BS)) > (lst_size(BS) / 2)){RULE("rrb");}
				else {RULE("rb");}
			}
			/*col_str_fd(FGRN, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FGRN, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FGRN, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FGRN, " Position of second highest value : ", 2);
			ft_nbrendl_fd(BHP(NH(BS)), 2);*/
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
			/*i = 1;
			while (B->value != NH(BS))
			{
				col_str_fd(FRED, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FRED, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FRED, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FRED, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);
				RULE(BHP(NH(BS)) > (lst_size(BS) / 2) ? "rrb" : "rb");
			}
			col_str_fd(FRED, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FRED, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FRED, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FRED, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);
			RULE("pa");
			*/
			/*while (B->value != HV(BS))
			{
				col_str_fd(FYEL, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FYEL, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FYEL, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FYEL, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);
				RULE(BHP(HV(BS)) > (lst_size(BS) / 2) ? "rrb" : "rb");
			}
			col_str_fd(FYEL, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FYEL, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FYEL, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FYEL, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);
			while (i++ == 0) //issue
				RULE("pa");
			col_str_fd(FCYN, "Highest value : ", 2);
				ft_putnbr_fd(HV(BS), 2);
				col_str_fd(FCYN, " Position of highest value : ", 2);
				ft_nbrendl_fd(BHP(HV(BS)), 2);
				col_str_fd(FCYN, "Second Highest value : ", 2);
				ft_putnbr_fd(NH(BS), 2);
				col_str_fd(FCYN, " Position of second highest value : ", 2);
				ft_nbrendl_fd(BHP(NH(BS)), 2);
			RULE("sa");*/
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

void		partition(t_ps *ps)
{
	int parts = 5;
	int sect = 1;
	int i = 0;
	if(lst_size(&ps->a) > 250)
		parts = 10;
	while (!(check_sorted(&ps->a) == 1))
	{
		while(i < RANGE())
		{
			/*if(lst_size(&ps->a) == 1)
			{
				//exit(1);
				//rotate_b(ps, 0);
				backtoa(ps);
			}*/
			if(A->value <= RANGE())
			{
				i++;
				RULE("pb");
			}
			else
			{
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
			pushbacktoa(&ps);
		}
		else
		{
			partition(&ps);
			backtoa(&ps);
		}
		freestack(&ps.a);
		/*else
			partition(&ps);
		*/
		/*int highest = highest_val(&ps.a);
		int lowest = lowest_val(&ps.a);
		while(!(check_sorted(&ps.a) == 1))
		{
			//ft_nbrendl_fd((highest_val(&ps.a)+lowest_val(&ps.a))/3 * 2, 2);
			if(lst_size(&ps.a) > ((highest+lowest)/3))
			{
				if((ps.a.lst && ps.a.lst->next) && ps.a.lst->value > ((highest+lowest)/3 * 2))
				{
					col_endl_fd(FRED, "TOP 50\%", 2);
					RULE("ra");
				}
			}
			if ((ps.b.lst && ps.b.lst->next && ps.a.lst && ps.a.lst->next) && (ps.b.lst->next->value > ps.b.lst->value) && (ps.a.lst->value > ps.a.lst->next->value) && (ps.a.lst->value < bottom_val(&ps.a)))
			{
				col_endl_fd(FRED, "ss1", 2);
				RULE("ss");
			}
				if ((ps.b.lst && ps.b.lst->next && ps.a.lst && ps.a.lst->next) && (ps.b.lst->next->value < ps.b.lst->value) && (ps.a.lst->value < ps.a.lst->next->value) && (ps.a.lst->next->value > bottom_val(&ps.a)) && (bottom_val(&ps.b) > ps.b.lst->next->value))
			{
				col_endl_fd(FRED, "ss2", 2);
				RULE("ss");
			}
			if ((ps.b.lst && ps.b.lst->next && ps.a.lst && ps.a.lst->next) && (ps.b.lst->value < bottom_val(&ps.b)) && (ps.a.lst->value > bottom_val(&ps.a)))
			{
				col_endl_fd(FRED, "rr1", 2);
				RULE("rr");
			}
			if((ps.a.lst && ps.a.lst->next) && (ps.a.lst->value > bottom_val(&ps.a)))
			{
				col_endl_fd(FRED, "ra1", 2);
				RULE("ra");
			}
			
			if ((ps.a.lst && ps.a.lst->next) &&(ps.a.lst->value > ps.a.lst->next->value) && (ps.a.lst->value < bottom_val(&ps.a)))
			{
				col_endl_fd(FRED, "sa1", 2);
				RULE("sa");
			}
			if ((ps.b.lst && ps.b.lst->next) && (ps.b.lst->value < bottom_val(&ps.b)))
			{
				col_endl_fd(FRED, "rb1", 2);
				RULE("rb");
			}
			if ((ps.b.lst && ps.b.lst->next) && (ps.b.lst->next->value > ps.b.lst->value))
			{
				col_endl_fd(FRED, "sb1", 2);
				RULE("sb");
			}
			if((ps.a.lst && ps.a.lst->next) && (bottom_val(&ps.a)<ps.a.lst->value) && (bottom_val(&ps.a) < ps.a.lst->next->value))
			{
				col_endl_fd(FRED, "rra1", 2);
				RULE("rra");
			}
			if ((ps.a.lst && ps.a.lst->next) && (ps.a.lst->next->value > ps.a.lst->value) && (ps.a.lst->next->value > bottom_val(&ps.a)))
			{
				col_endl_fd(FRED, "sa2", 2);
				RULE("sa");
			}
			*/
			/*if ((ps.b.lst && ps.b.lst->next) && (ps.b.lst->value < bottom_val(&ps.b)))
			{
				col_endl_fd(FRED, "rb1", 2);
				RULE("rb");
			}*/
			/*
			if((ps.a.lst && ps.b.lst && ps.b.lst->next) && ps.a.lst->value < highest_val(&ps.b) && ps.a.lst->value > lowest_val(&ps.b))
			{
				//col_endl_fd(FRED, "rotate b1", 2);
				int a;
				a = highest_under(&ps.b, ps.a.lst->value);
				ft_nbrendl_fd(a, 2);
				ft_nbrendl_fd(find_pos(&ps.b, a), 2);
				if(find_pos(&ps.b, a) < lst_size(&ps.b)/2)
				{
					col_endl_fd(FRED, "rotate b2", 2);
					while(highest_under(&ps.b, ps.a.lst->value) != ps.b.lst->value)
					{
						RULE("rb");
					}
				}
				else
				{
					col_endl_fd(FRED, "rotate b3", 2);
					while(highest_under(&ps.b, ps.a.lst->value) != ps.b.lst->value)
					{
						RULE("rrb");
					}
				}
			}
			col_endl_fd(FRED, "pb10", 2);
			RULE("pb");
		}
		col_endl_fd(FGRN, "SORTED A", 2);
		//printbothstacks(&ps.a, &ps.b);
		exit(1);
		while (ps.b.lst)
		{
			if (ps.a.lst->value < highest_val(&ps.b))
			{
				col_endl_fd(FRED, "second1", 2);
				RULE("ra");
			}
			if (!ps.b.lst || ((bottom_val(&ps.a) > highest_val(&ps.b))\
			&& (bottom_val(&ps.a) < ps.a.lst->value)))
			{
				col_endl_fd(FRED, "second2", 2);
				RULE("rra");
			}
			if (highest_val(&ps.b) != ps.b.lst->value)
			{

				if (find_pos(&ps.b, highest_val(&ps.b)) < (lst_size(&ps.a) / 2))
				{
					while(highest_val(&ps.b) != ps.b.lst->value)
					{
						col_endl_fd(FRED, "second3", 2);
						RULE("rb");
					}
				}
				else
				{
					while(highest_val(&ps.b) != ps.b.lst->value)
					{
						col_endl_fd(FRED, "second4", 2);
						RULE("rrb");
					}
				}
			}
			col_endl_fd(FRED, "second5", 2);
			RULE("pa");
		}
		col_endl_fd(FGRN, "PUSHED TO A", 2);
		while(!(check_sorted(&ps.a) == 1))
		{
			if (find_pos(&ps.a, highest_val(&ps.a)) < (lst_size(&ps.a) / 2))
			{
				col_endl_fd(FRED, "third1", 2);
				RULE("ra");
			}
			else
			{
				col_endl_fd(FRED, "third2", 2);
				RULE("rra");
			}
		}*/
	}
	exit(0);
}
