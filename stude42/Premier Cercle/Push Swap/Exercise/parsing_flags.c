/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:53:57 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/29 12:55:07 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 ** Compare deux chaînes. Retourne 0 si égales.
 */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
 ** Détecte et applique un flag dans data.
 ** data->start :
 **   0 = adaptatif (défaut)
 **   1 = --simple
 **   2 = --medium
 **   3 = --complex
 **   4 = --adaptive
 ** Retourne 1 si c'était un flag, 0 sinon.
 */

static int	ft_handle_flag(char *arg, t_bench *data)
{
	if (ft_strcmp(arg, "--bench") == 0)
		data->is_bench = 1;
	else if (ft_strcmp(arg, "--simple") == 0)
		data->start = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		data->start = 2;
	else if (ft_strcmp(arg, "--complex") == 0)
		data->start = 3;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		data->start = 4;
	else
		return (0);
	return (1);
}
/*
 ** Fonction principale de parsing.
 ** Parcourt argv, détecte les flags et construit la pile A.
 ** Retourne la pile, ou NULL si aucun entier fourni.
 */

t_list	*ft_parse(int argc, char **argv, t_bench *data)
{
	t_list	*stack;
	int		i;

	stack = NULL;
	data->is_bench = 0;
	data->start = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_handle_flag(argv[i], data))
			ft_parse_arg(argv[i], &stack);
		i++;
	}
	return (stack);
}
