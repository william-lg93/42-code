/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:17:32 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/03 08:15:38 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countsep(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

int	strlensep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	freetab(char **tab, int k)
{
	int (i) = 0;
	while (i < k)
		free(tab[i++]);
	free(tab);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char **(split);
	int (j) = 0;
	int (i) = 0;
	int (k) = 0;
	split = malloc (sizeof(char *) * (countsep(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			split[k] = malloc (sizeof(char) * (strlensep(s + i, c) + 1));
			if (!split[k])
				return (freetab(split, k), NULL);
			while (s[i] && s[i] != c)
				split[k][j++] = s[i++];
			split[k][j] = '\0';
			j = 0;
			k++;
		}
		else
			i++;
	}
	split[k] = NULL;
	return (split);
}
