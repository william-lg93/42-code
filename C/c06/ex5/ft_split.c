/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 01:12:19 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/25 02:25:16 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	gt_sep(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	if (!charset || charset[0] == '\0')
	{
		if (str[0])
			return (1);
		return (0);
	}
	i = 0;
	count = 0;
	while (str[i])
	{
		if (gt_sep(charset, str[i]) == 0
			&& (i == 0 || gt_sep(charset, str[i - 1]) == 1))
			count++;
		i++;
	}
	return (count);
}

int	count_lettre(char *str, char *charset, int i)
{
	int	count;

	count = 0;
	while (str[i] && gt_sep(charset, str[i]) == 0)
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char	*str, char *charset)
{
	int		i;
	int		k;
	int		j;
	char	**tab;

	i = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	while (str[i])
	{
		if (gt_sep(charset, str[i]) == 0)
		{
			j = 0;
			tab[k] = malloc(sizeof(char) * (count_lettre(str, charset, i) + 1));
			while (str[i] && (gt_sep(charset, str[i]) == 0))
				tab[k][j++] = str[i++];
			tab[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	tab[k] = 0;
	return (tab);
}
/*
int	main(void)
{	int	i = 0;
	char	**tab;
	tab = ft_split("Slt__++++Cest__MoI__+++++Aimran", "__++++");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/
