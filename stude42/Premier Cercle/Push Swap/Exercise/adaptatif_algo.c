/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptatif_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 03:02:11 by kafitous          #+#    #+#             */
/*   Updated: 2026/06/12 06:47:01 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_adaptatif_algo(t_list *stack)
{
	if (stack == NULL)
		return (TRUE);
	while (stack->next != NULL)
	{
		if (stack->rank > stack->next->rank)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

void	ft_adaptatif_sort(t_list **a, t_list **b, t_bench *bench)
{
	int	size;

	if (ft_adaptatif_algo(*a))
		return ;
	size = ft_lstsize(*a);
	if (size <= 5)
	{
		ft_minmax_sort(a, b, bench);
		return ;
	}
	if (bench->disorder < 0.10f || size <= 10)
		ft_minmax_sort(a, b, bench);
	else if (bench->disorder < 0.60f || size <= 100)
		ft_chunk_sort(a, b, bench);
	else
		ft_radix_sort(a, b, bench);
}
