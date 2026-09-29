/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:35:50 by kafitous          #+#    #+#             */
/*   Updated: 2026/06/12 07:10:15 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>

# define TRUE 1
# define FALSE 0
# define NOT_FOUND -1

typedef struct s_list
{
	int				value;
	int				rank;
	struct s_list	*next;
}	t_list;

typedef struct s_const
{
	int		successor_index;
	int		target_index;
	int		a_size;
	int		b_size;
}	t_const;

typedef struct s_move
{
	t_list		*cheapest;
	t_list		*target;
}	t_move;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		is_bench;
	int		start;
	float	disorder;
}	t_bench;

typedef struct s_chunk
{
	int		chunk_int;
	int		chunk_max;
}	t_chunk;
/*==========OPERATION==========*/
void	sa(t_list **a_stack, int print, t_bench *data);
void	sb(t_list **b_stack, int print, t_bench *data);
void	ss(t_list **a_stack, t_list **b_stack, int print, t_bench *data);
void	pa(t_list **a_stack, t_list **b_stack, int print, t_bench *data);
void	pb(t_list **a_stack, t_list **b_stack, int print, t_bench *data);
void	ra(t_list **a_stack, int print, t_bench *data);
void	rb(t_list **b_stack, int print, t_bench *data);
void	rr(t_list **a_stack, t_list **b_stack, int print, t_bench *data);
void	rra(t_list **a_stack, int print, t_bench *data);
void	rrb(t_list **b_stack, int print, t_bench *data);
void	rrr(t_list **a_stack, t_list **b_stack, int print, t_bench *data);
/*==========PARCINGS===========*/
void	ft_error(t_list **stack);
t_list	*ft_parse(int argc, char **argv, t_bench *data);
int		ft_strcmp(char *s1, char *s2);
int		ft_is_valid_int(char *s);
long	ft_atol(char *s);
int		ft_has_duplicate(t_list *stack, int value);
t_list	*ft_new_node(int value);
void	ft_parse_arg(char *arg, t_list **stack);
/*==========ALGO_S============*/
void	ft_minmax_sort(t_list **a_stack, t_list **b_stack, t_bench *bench);
int		ft_is_sorted(t_list **stack);
t_list	*find_smallest_int(t_list *stack);
void	ft_move_to_top(t_list **stack, t_list *target, t_bench *bench);
/*==========CHUNK=============*/
t_list	*ft_find_max_in_b(t_list *b);
void	ft_rotate_to_chunk(t_list **a, t_chunk *chunk, t_bench *bench);
void	ft_chunk_push_to_b(t_list **a, t_list **b, t_chunk *c, t_bench *be);
void	ft_push_b_to_a(t_list **a, t_list **b, t_bench *bench);
void	ft_chunk_sort(t_list **a, t_list **b, t_bench *bench);
/*==========RADIX=============*/
int		ft_get_max_bits(int max);
int		ft_get_max_rank(t_list *stack);
void	ft_radix_pass(t_list **a, t_list **b, int bit, t_bench *bench);
void	ft_radix_sort(t_list **a, t_list **b, t_bench *bench);
/*==========ADAPTIF===========*/
int		ft_adaptatif_algo(t_list *stack);
void	ft_adaptatif_sort(t_list **a, t_list **b, t_bench *bench);
/*==========RANCK=============*/
void	ft_assign_ranks(t_list *stack);
/*==========DISORDER==========*/
float	ft_compute_disorder(t_list *stack);
/*==========LST_UTILS=========*/
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
/*========BENCH=============*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_put_float(float n);
void	ft_print_bench(t_bench *data);
#endif
