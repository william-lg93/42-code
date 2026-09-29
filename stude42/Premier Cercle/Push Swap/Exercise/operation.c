/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:35:34 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/29 12:40:04 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 ** Déplace le premier élément d'une pile vers la fin.
 ** Avant : [1] -> [2] -> [3]
 ** Après : [2] -> [3] -> [1]
 */
static void	ft_rotate_stack(t_list **stack)
{
	t_list	*first;

	if (!stack || !*stack)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}
/*
 ** Incrémente le compteur correspondant à l'opération dans data.
 */

static void	update_counter(t_bench *data, char op)
{
	if (!data)
		return ;
	if (op == 'a')
		data->ra++;
	else if (op == 'b')
		data->rb++;
	else if (op == 'r')
		data->rr++;
}
/*
 ** ra : rotation de la pile A.
 */

void	ra(t_list **a_stack, int print, t_bench *data)
{
	ft_rotate_stack(a_stack);
	update_counter(data, 'a');
	if (print)
		write (1, "ra\n", 3);
}
/*
 ** rb : rotation de la pile B.
 */

void	rb(t_list **b_stack, int print, t_bench *data)
{
	ft_rotate_stack(b_stack);
	update_counter(data, 'b');
	if (print)
		write (1, "rb\n", 3);
}
/*
 ** rr : rotation simultanée des deux piles.
 */

void	rr(t_list **a_stack, t_list **b_stack, int print, t_bench *data)
{
	ft_rotate_stack(a_stack);
	ft_rotate_stack(b_stack);
	update_counter(data, 'r');
	if (print)
		write (1, "rr\n", 3);
}
