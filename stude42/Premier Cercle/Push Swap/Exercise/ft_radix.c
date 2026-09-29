/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 04:30:19 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/12 06:51:56 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(int max)
{
	int	mult;
	int	i;

	i = 0;
	mult = 1;
	while (mult <= max)
	{
		mult *= 2;
		i++;
	}
	return (i);
}

int	ft_get_max_rank(t_list *stack)
{
	int	tmp;

	if (!stack)
		return (0);
	tmp = stack->rank;
	while (stack != NULL)
	{
		if (tmp < stack->rank)
			tmp = stack->rank;
		stack = stack->next;
	}
	return (tmp);
}

void	ft_radix_pass(t_list **a, t_list **b, int bit, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*a);
	while (size != 0)
	{
		if ((((*a)->rank >> bit) & 1) == 0)
			pb(a, b, 1, bench);
		else
			ra(a, 1, bench);
		size--;
	}
	while (*b != NULL)
		pa(a, b, 1, bench);
}

void	ft_radix_sort(t_list **a, t_list **b, t_bench *bench)
{
	int	max;
	int	i;

	i = 0;
	ft_assign_ranks(*a);
	max = ft_get_max_bits(ft_get_max_rank(*a));
	while (i != max)
	{
		ft_radix_pass(a, b, i, bench);
		i++;
	}
}
