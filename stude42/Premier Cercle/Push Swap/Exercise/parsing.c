/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:53:50 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/29 12:48:21 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 ** Vérifie qu'une chaîne est un entier valide (signe optionnel + chiffres).
 */

int	ft_is_valid_int(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/*
 ** Convertit une chaîne en long pour détecter les overflows.
 ** Retourne LLONG_MIN si la valeur dépasse INT_MAX ou INT_MIN.
 */

long	ft_atol(char *s)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (LLONG_MIN);
		i++;
	}
	return (result * sign);
}
/*
 ** Vérifie qu'il n'y a pas de doublon dans la pile.
 */

int	ft_has_duplicate(t_list *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
/*
 ** Crée un nouveau noeud avec la valeur donnée.
 */

t_list	*ft_new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = 0;
	node->next = NULL;
	return (node);
}
/*
 ** Parse un argument, vérifie sa validité et l'ajoute à la pile.
 */

void	ft_parse_arg(char *arg, t_list **stack)
{
	long	val;
	t_list	*node;

	if (!ft_is_valid_int(arg))
		ft_error(stack);
	val = ft_atol(arg);
	if (val == LLONG_MIN || val > INT_MAX || val < INT_MIN)
		ft_error(stack);
	if (ft_has_duplicate(*stack, (int)val))
		ft_error(stack);
	node = ft_new_node((int)val);
	if (!node)
		ft_error(stack);
	ft_lstadd_back(stack, node);
}
