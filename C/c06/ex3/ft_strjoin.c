/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:52:16 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/22 19:05:51 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	calculator(char **strs, char *str2, int a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= a)
	{
		i += ft_strlen(strs[j]);
		j++;
	}
	i += ft_strlen(str2) * a;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	j = calculator(strs, sep, size - 1);
	string = malloc (sizeof(char) * j - 1);
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			string[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			string[k++] = sep[j++];
	}
	string[k] = '\0';
	return (string);
}
/*
int	main(void)
{
	char	*join;
	char	*strs[] = {"hello", "test", "mot"};
	join = ft_strjoin(3, strs, " ");
	printf("%s\n", join);
	return(0);
}*/
