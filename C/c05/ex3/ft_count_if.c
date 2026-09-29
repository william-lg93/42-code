/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:58:31 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/16 16:25:55 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;
	int	k;

	i = 0;
	count = 0;
	while (i < length)
	{
		k = f(tab[i]);
		if (k != 0)
			count++;
		i++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	char    *tab[]= {"hoewcw","hwoehfc",""};
	int	i;

	i = ft_count_if(tab, 2, &ft_strlen);
	printf("%d", i);
}*/
