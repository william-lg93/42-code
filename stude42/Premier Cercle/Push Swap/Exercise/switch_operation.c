/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:39:10 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/29 12:53:21 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 ** echange les deux premiers element d'une pile
 */
static void	ft_swap_stack(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}
/*
 ** echange les deux premier element de A
 */

void	sa(t_list **a_stack, int print, t_bench *data)
{
	ft_swap_stack(a_stack);
	if (data)
		data->sa++;
	if (print)
		write (1, "sa\n", 3);
}
/*
 ** echange les deux premier element de B
 */

void	sb(t_list **b_stack, int print, t_bench *data)
{
	ft_swap_stack(b_stack);
	if (data)
		data->sb++;
	if (print)
		write (1, "sb\n", 3);
}
/*
 **echange simultanement les deux premier element de A et de B
 */

void	ss(t_list **a_stack, t_list **b_stack, int print, t_bench *data)
{
	ft_swap_stack(a_stack);
	ft_swap_stack(b_stack);
	if (data)
		data->ss++;
	if (print)
		write (1, "ss\n", 3);
}
