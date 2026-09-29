/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:03:08 by kafitous          #+#    #+#             */
/*   Updated: 2026/06/12 06:49:51 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_is_sorted(t_list **stack)
{
	t_list *(tmp) = *stack;
	if (!tmp)
		return (1);
	while (tmp->next != NULL)
	{
		if (tmp->rank > tmp->next->rank)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*find_smallest_int(t_list *stash)
{
	t_list *(tmp) = stash;
	while (stash->next != NULL)
	{
		if (stash->rank < tmp->rank)
			tmp = stash;
		stash = stash->next;
	}
	return (tmp);
}

void	ft_move_to_top(t_list **stack, t_list *target, t_bench *bench)
{
	int	size;

	int (pos) = 0;
	t_list *(tmp) = *stack;
	size = ft_lstsize(*stack);
	while (tmp != target)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while (*stack != target)
			ra(stack, TRUE, bench);
	}
	else
	{
		while (*stack != target)
			rra(stack, TRUE, bench);
	}
}

void	ft_minmax_sort(t_list **a_stack, t_list **b_stack, t_bench *bench)
{
	t_list	*tmp;

	if (ft_is_sorted(a_stack))
		return ;
	while (ft_lstsize(*a_stack) > 1)
	{
		tmp = find_smallest_int(*a_stack);
		ft_move_to_top(a_stack, tmp, bench);
		pb(b_stack, a_stack, TRUE, bench);
	}
	while (*b_stack)
		pa(a_stack, b_stack, TRUE, bench);
}
