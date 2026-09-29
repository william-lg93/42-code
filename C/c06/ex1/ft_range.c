/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:42:49 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/22 18:57:42 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	a;

	i = 0;
	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	a = min;
	tab = malloc (sizeof(int) * (max - min));
	while (i < (max - min))
	{
		tab[i] = a;
		a++;
		i++;
	}
	return (tab);
}
/*
int	main (void)
{
	int	*tab;
	int	i = 0;

	tab = ft_range(15, 20);
	while (tab[i])
	{
		printf("%d\n", tab[i]);
		i++;
	}

}*/
