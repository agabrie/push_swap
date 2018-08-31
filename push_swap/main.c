/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 08:14:12 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/31 10:42:24 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# define RULE(string) rule(&ps->a, &ps->b, string);ft_putendl(string);continue ;
# define DRULE(string) rule(&ps->a, &ps->b, string);ft_putendl(string);return(1);
# define A (ps->a.lst)
# define B (ps->b.lst)
# define AN (ps->a.lst->next)
# define BN (ps->b.lst->next)
# define AA (A && AN)
# define BB (B && BN)
# define AB (AA && BB)
# define ABV (bottom_val(&ps->a))
# define BBV (bottom_val(&ps->b))

/*void nrma(t_ps *ps)
{
	t_stack *temp;
	
}
*/

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

/*int rank(t_stackdata *a, t_stackdata *stack, int size)
{
	t_stack *head;
	//t_stack *next;
	head = a->lst;
	//next = head;
	col_endl_fd(FRED, "TRY to Normalise", 2);
	while(head)
	{
		
		if(head)
		{
			col_str_fd(FYEL, "Start : ", 2);
			ft_putnbr_fd(stack->lst->value, 2);
			col_str_fd(FYEL, " vs node:", 2);
			ft_nbrendl_fd(head->value, 2);
		}
		if(head->next && stack->lst->value < head->value)
		{
			col_endl_fd(FGRN, "RANK decrease", 2);
			size--;
		}
		head = head->next;
	}
	return(size);
}
*/
/*void normalise(t_stackdata *a)
{
	int size = lst_size(a);
	t_stackdata *head;
	// = a->lst;
	head = malloc(sizeof(t_stack));
	while(lst_size(head) < lst_size(a))
		push(head, size);
	t_stackdata *temp;
	temp = a;
	while(head)
	{
		head->lst->value = rank(a,temp, size);
		temp->lst = temp->lst->next;
		head->lst = head->lst->next;
	}
}
*/

int	checkdoublerule(t_ps *ps)
{
	if ((AB)\
	&& (BN->value > B->value) && (A->value > AN->value) && (A->value < ABV))
	{
		//col_endl_fd(FRED, "ss1", 2);
		DRULE("ss");
	}
	if ((AB) && (BN->value < B->value) && (A->value < AN->value)\
	&& (AN->value > ABV) && (BBV > BN->value))
	{
		//col_endl_fd(FRED, "ss2", 2);
		DRULE("ss");
	}
	if ((AB) && (B->value < BBV) && (A->value > ABV))
	{
		//col_endl_fd(FRED, "rr1", 2);
		DRULE("rr");
	}
	return (0);
}

void	frankenstein(t_ps *ps)
{
	int i = 0;
	printbothstacks(&ps->a, &ps->b);
	while(!(check_sorted(&ps->a)==1))
	{
		i++;
		if (checkdoublerule(ps))
			continue;
		if ((AA) && (A->value > ABV))
		{
			//col_endl_fd(FRED, "ra1", 2);
			RULE("ra");
		}
		if ((AA) && (A->value > AN->value) && (A->value < ABV))
		{
			//col_endl_fd(FRED, "sa1", 2);
			RULE("sa");
		}
		if ((BB) && (B->value < BBV))
		{
			//col_endl_fd(FRED, "rb1", 2);
			RULE("rb");
		}
		if ((BB) && (BN->value > B->value))
		{
			//col_endl_fd(FRED, "sb1", 2);
			RULE("sb");
		}
		if ((AA) && (ABV < A->value) && (ABV < AN->value))
		{
			//col_endl_fd(FRED, "rra1", 2);
			RULE("rra");
		}
		if ((AA) && (AN->value > A->value) && (AN->value > ABV))
		{
			//col_endl_fd(FRED, "sa2", 2);
			RULE("sa");
		}
			/*
			if ((ps->b.lst && ps->b.lst->next) && (ps->b.lst->value < bottom_val(&ps->b)))
			{
				col_endl_fd(FRED, "rb1", 2);
				RULE("rb");
			}*/
			
			if((ps->a.lst && ps->b.lst && ps->b.lst->next) && ps->a.lst->value < highest_val(&ps->b) && ps->a.lst->value > lowest_val(&ps->b))
			{
				//col_endl_fd(FRED, "rotate b1", 2);
				int a;
				a = highest_under(&ps->b, ps->a.lst->value);
				ft_nbrendl_fd(a, 2);
				ft_nbrendl_fd(find_pos(&ps->b, a), 2);
				if(find_pos(&ps->b, a) < lst_size(&ps->b)/2)
				{
					//col_endl_fd(FRED, "rotate b2", 2);
					while(highest_under(&ps->b, ps->a.lst->value) != ps->b.lst->value)
					{
						++i;
						RULE("rb");
					}
				}
				else
				{
					//col_endl_fd(FRED, "rotate b3", 2);
					while(highest_under(&ps->b, ps->a.lst->value) != ps->b.lst->value)
					{
						++i;
						RULE("rrb");
					}
				}
			}
			//col_endl_fd(FRED, "pb10", 2);
			RULE("pb");
		}
		col_endl_fd(FGRN, "SORTED A", 2);
		col_str_fd(FYEL, "NUMBER OF MOVES : ", 2);
		ft_nbrendl_fd(i, 2);
		printbothstacks(&ps->a, &ps->b);
		exit(0);
}



int			main(int ac, char **av)
{
	t_ps		ps;

	if (ac > 1)
	{
		init(&ps, av, ac);
		//printbothstacks(&ps.a, &ps.b);
		//if(lst_size(&ps.a) <= 20)
			frankenstein(&ps);
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
	return (0);
}
