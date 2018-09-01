/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zee <zee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:31:27 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/01 07:13:45 by zee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define MIN -2147483648
# define MAX 2147483647
# define VAR(NAME) #NAME
# define MOVES() (col_str_fd(FYEL, "Moves : ", 2),ft_nbrendl_fd(moves, 2))
# define DEBUGIT(a,b,d,l) if(d){col_endl_fd(FYEL,l,2);printbothstacks(a,b);}
# define FS() (freestack(a),freestack(b))
# define MESSAGE(string, colour) (col_endl_fd(colour, string, 1),FS(),exit(0))
# define ERR() (col_endl_fd(FRED, "Error", 1), exit(0))
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
void			rule(t_stackdata *a, t_stackdata *b, char *line, int debug);
void			printbothstacks(t_stackdata *a, t_stackdata *b);
void			check_sorted(t_stackdata *a, t_stackdata *b);
void			windows_tests(t_stackdata *a, t_stackdata *b, int db);
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
void			init(t_ps *ps, char **av, int ac);
void			freestack(t_stackdata *stack);
int				lst_size(t_stackdata *stack);
int				longest_int(t_stack *stack);
#endif
