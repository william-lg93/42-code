/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 15:33:40 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/30 18:06:52 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_stack_to_arr(t_list *stack, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
}

static int	ft_count_mistakes(int *arr, int size)
{
	int	mistakes;
	int	i;
	int	j;

	mistakes = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

float	ft_compute_disorder(t_list *stack)
{
	int	size;
	int	*arr;
	int	total;
	int	result;

	size = ft_lstsize(stack);
	if (size <= 1)
		return (0.0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0.0);
	ft_stack_to_arr(stack, arr, size);
	total = size * (size - 1) / 2;
	result = ft_count_mistakes(arr, size);
	free(arr);
	return ((float)result / (float)total);
}
