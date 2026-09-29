/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:25:58 by kafitous          #+#    #+#             */
/*   Updated: 2026/06/12 06:56:29 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_list **a_stack, t_list **b_stack, int print, t_bench *data)
{
	t_list	*tmp;

	if (!*b_stack)
		return ;
	tmp = *b_stack;
	*b_stack = (*b_stack)->next;
	tmp->next = NULL;
	ft_lstadd_front(a_stack, tmp);
	if (data)
		data->pa++;
	if (print)
		write (1, "pa\n", 3);
}

void	pb(t_list **a_stack, t_list **b_stack, int print, t_bench *data)
{
	t_list	*tmp;

	if (!*a_stack)
		return ;
	tmp = *a_stack;
	*a_stack = (*a_stack)->next;
	tmp->next = NULL;
	ft_lstadd_front(b_stack, tmp);
	if (data)
		data->pb++;
	if (print)
		write (1, "pb\n", 3);
}
