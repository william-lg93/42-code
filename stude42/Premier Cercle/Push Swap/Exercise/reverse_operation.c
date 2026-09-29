/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:35:41 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/29 12:54:23 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 ** Déplace le dernier élément d'une pile vers l4e debut.
 ** Avant : [3] -> [2] -> [1]
 ** Après : [1] -> [2] -> [3]
 */
static void	ft_reverse_rotate_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*new_last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = ft_lstlast(*stack);
	new_last = *stack;
	while (new_last->next != tmp)
		new_last = new_last->next;
	new_last->next = NULL;
	ft_lstadd_front(stack, tmp);
}
/*
 ** Incrémente le compteur correspondant à l'opération dans data.
 */

static void	update_counter(t_bench *data, char op)
{
	if (!data)
		return ;
	if (op == 'a')
		data->rra++;
	else if (op == 'b')
		data->rrb++;
	else if (op == 'r')
		data->rrr++;
}
/*
 ** rra : rotation inverse de la pile A.
 */

void	rra(t_list **a_stack, int print, t_bench *data)
{
	ft_reverse_rotate_stack(a_stack);
	update_counter(data, 'a');
	if (print)
		write (1, "rra\n", 4);
}
/*
 ** rrb : rotation inverse de la pile B
 */

void	rrb(t_list **b_stack, int print, t_bench *data)
{
	ft_reverse_rotate_stack(b_stack);
	update_counter(data, 'b');
	if (print)
		write (1, "rrb\n", 4);
}
/*
 ** rrr : rotation simultanée des deux piles.
 */

void	rrr(t_list **a_stack, t_list **b_stack, int print, t_bench *data)
{
	ft_reverse_rotate_stack(a_stack);
	ft_reverse_rotate_stack(b_stack);
	update_counter(data, 'r');
	if (print)
		write (1, "rrr\n", 4);
}
