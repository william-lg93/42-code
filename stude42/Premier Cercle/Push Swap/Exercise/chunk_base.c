/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 07:24:20 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/12 07:11:19 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_max_in_b(t_list *b)
{
	t_list	*tmp;

	tmp = b;
	while (b != NULL)
	{
		if (tmp->rank < b->rank)
			tmp = b;
		b = b->next;
	}
	return (tmp);
}

void	ft_rotate_to_chunk(t_list **a, t_chunk *chunk, t_bench *bench)
{
	t_list	*tmp;
	int		size;

	int (i) = 0;
	tmp = *a;
	size = ft_lstsize(*a);
	while (tmp != NULL)
	{
		if (tmp->rank >= chunk->chunk_int && tmp->rank <= chunk->chunk_max)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i <= size / 2)
	{
		while (*a != tmp)
			ra(a, 1, bench);
	}
	else
	{
		while (*a != tmp)
			rra(a, 1, bench);
	}
}

void	ft_chunk_push_to_b(t_list **a, t_list **b, t_chunk *c, t_bench *be)
{
	t_list	*tmp;

	while (1)
	{
		tmp = *a;
		while (tmp != NULL)
		{
			if (tmp->rank >= c->chunk_int && tmp->rank <= c->chunk_max)
				break ;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			break ;
		ft_rotate_to_chunk(a, c, be);
		pb(a, b, 1, be);
	}
}

void	ft_push_b_to_a(t_list **a, t_list **b, t_bench *bench)
{
	t_list	*tmp;
	t_list	*cur;
	int		size;
	int		i;

	while (*b != NULL)
	{
		cur = *b;
		i = 0;
		tmp = ft_find_max_in_b(*b);
		size = ft_lstsize(*b);
		while (cur != tmp)
		{
			i++;
			cur = cur->next;
		}
		if (i <= size / 2)
			while (*b != tmp)
				rb(b, 1, bench);
		else
			while (*b != tmp)
				rrb(b, 1, bench);
		pa(a, b, 1, bench);
	}
}

void	ft_chunk_sort(t_list **a, t_list **b, t_bench *bench)
{
	t_chunk	chunk;
	int		size;
	int		chunk_size;
	int		nb_chunks;

	int (i) = 0;
	size = ft_lstsize(*a);
	if (size <= 100)
		nb_chunks = 5;
	else if (size <= 500)
		nb_chunks = 8;
	else
		nb_chunks = 11;
	chunk_size = size / nb_chunks;
	while (i < nb_chunks)
	{
		chunk.chunk_int = i * chunk_size + 1;
		chunk.chunk_max = (i + 1) * chunk_size;
		if (i == nb_chunks - 1)
			chunk.chunk_max = size;
		ft_chunk_push_to_b(a, b, &chunk, bench);
		i++;
	}
	ft_push_b_to_a(a, b, bench);
}
