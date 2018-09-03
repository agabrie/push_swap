/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:31:27 by agabrie           #+#    #+#             */
/*   Updated: 2018/09/03 08:27:44 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"
# define MIN -2147483648
# define MAX 2147483647
# define VAR(NAME) #NAME
# define MOVES() (col_str_fd(FYEL, "Moves : ", 2),ft_nbrendl_fd(ps->moves, 2))
# define DEBUGIT(a,b,d,l) if(d){col_endl_fd(FYEL,l,2);printbothstacks(a,b);}
# define FS() (freestack(a),freestack(b))
# define MESSAGE(string, colour) (col_endl_fd(colour, string, 1),FS(),exit(0))
# define ERR() (col_endl_fd(FRED, "Error", 1), exit(0))
# define CAT(A, B) A B
# define ARRLEN(args, ac) ac = 0;while(args[ac])ac++;ac++;
# define CHECKNUM() if(!ft_isnum(args[ac - (i + 1)]))ERR();

typedef struct	s_stack
{
	int				value;
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
	int			size;
	int			debug;
	char		**line;
	int			moves;
}				t_ps;

typedef struct	s_vis
{
	void	*gsci;
	void	*win;
	t_point ws;
	t_point fr;
	t_point bs;
	int		ls;
	int		lv;
	int		gsxt;
	int		gsxa;
	int		gsy;
	int		sbf;
}				t_vis;

typedef struct	s_psv
{
	t_ps	*ps;
	t_vis	*vis;
}				t_psv;

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
void			initialise(t_ps *ps);
void			init(t_ps *ps, char **av, int ac);
void			freestack(t_stackdata *stack);
int				lst_size(t_stackdata *stack);
int				longest_int(t_stack *stack);
void			draw_graph(t_vis *vis, t_ps *ps);
void			check(t_ps *ps);
t_stackdata		normalise(t_stackdata *temp, int size, t_stackdata *a);
void			temp_stack(t_stackdata *temp, int size);
void			visinit(t_ps *ps, char **av, int ac);
int				vcheck(t_psv *psv);
int				key_event(int key_code, t_psv *psv);
void			setup_vis(t_vis *vis, t_ps *ps);
void			draw_rectangle(t_vis *vis, t_point *start, t_point *end);
void			drawsolidrect(t_point *start, t_point *end, t_vis *vis);
void			drawbars(t_point *st, t_point *end, t_stackdata *s, t_vis *vis);
void			draw_frames(t_vis *vis, t_ps *ps);
#endif
