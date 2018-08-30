/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:31:27 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/30 08:42:43 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define MIN -2147483648
# define MAX 2147483647
# define VAR(NAME) #NAME
# define FS() (freestack(a),freestack(b))
# define MESSAGE(string, colour) (col_endl_fd(colour, string, 1),FS(),exit(1))
# define ERR() (col_endl_fd(FRED, "Errors", 1), exit(1))
# define CAT(A, B) A B
# define ARRLEN(args, ac) ac = 0;while(args[ac])ac++;ac++;

typedef struct	s_stack
{
	int				value;
	int				size;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_stackdata
{
	t_stack		*lst;
	int			size;
}				t_stackdata;

typedef struct	s_ps
{
	t_stackdata	a;
	t_stackdata	b;
	int			debug;
}				t_ps;

t_stack			*new_node(int value);
int				pop(t_stackdata *list);
void			push(t_stackdata *list, int val);
int				peek(t_stack *top);
void			printstack(t_stack *stack);
void			rule(t_stackdata *a, t_stackdata *b, char *line);
void			printbothstacks(t_stackdata *a, t_stackdata *b);
int				check_sorted(t_stackdata *a);
int				check_largest(t_stackdata *stack);
int				check_inverted(t_stackdata *a);
void			windows_tests(t_stackdata *a, t_stackdata *b);
void			sa(t_stackdata *a);
void			pa(t_stackdata *a, t_stackdata *b);
void			ra(t_stackdata *a);
void			rra(t_stackdata *a);
void			ss(t_stackdata *a, t_stackdata *b);
void			rr(t_stackdata *a, t_stackdata *b);
void			rrr(t_stackdata *a, t_stackdata *b);
void			sb(t_stackdata *b);
void			pb(t_stackdata *a, t_stackdata *b);
void			rb(t_stackdata *b);
void			rrb(t_stackdata *b);
void			check_dups(char **av);
void			temp_stack(t_stackdata *temp, int size);
t_stackdata		normalise(t_stackdata *temp, int size, t_stackdata *a);
void			freestack(t_stackdata *stack);
void			init(t_ps *ps, char **av, int ac);
int				bottom_val(t_stackdata *stack);
int				lst_size(t_stackdata *stack);
int				lowest_val(t_stackdata *stack);
int				highest_val(t_stackdata *stack);
int				highest_under(t_stackdata *stack,int val);
int				find_pos(t_stackdata *stack, int value);
#endif
