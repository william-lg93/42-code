/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:43:58 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/29 12:49:33 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 ** Affiche "Error\n" sur stderr, libère la pile et quitte.
 */
void	ft_error(t_list **stack)
{
	t_list	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	write (2, "Error\n", 6);
	exit (1);
}
