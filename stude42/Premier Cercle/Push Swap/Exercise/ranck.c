/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranck.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 15:20:31 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/30 21:12:35 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 ** Trouve le noeud avec la valeur minimale parmi ceux dont rank == 0.
 */
static t_list	*ft_find_min_unranked(t_list *stack)
{
	t_list	*min;
	t_list	*cur;

	min = NULL;
	cur = stack;
	while (cur)
	{
		if (cur->rank == 0)
			if (!min || cur->value < min->value)
				min = cur;
		cur = cur->next;
	}
	return (min);
}
/*
 ** Assigne un rang croissant (1, 2, 3...) a chaque noeud
 ** selon l'ordre croissant des valeurs.
 ** Apres ca, rank remplace value pour les algos.
 */

void	ft_assign_ranks(t_list *stack)
{
	t_list	*min;
	int		rank;

	rank = 1;
	while (1)
	{
		min = ft_find_min_unranked(stack);
		if (!min)
			break ;
		min->rank = rank;
		rank++;
	}
}
