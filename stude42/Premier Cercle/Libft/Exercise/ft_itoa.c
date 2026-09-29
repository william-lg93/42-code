/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:19:23 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/04 00:24:42 by gitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long n)
{
	int (len) = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*tab;
	long	nbrs;

	nbrs = nbr;
	int (i) = len(nbrs);
	tab = malloc(sizeof(char) * len(nbrs) + 1);
	tab[i] = '\0';
	if (!tab)
		return (NULL);
	i--;
	if (nbrs < 0)
	{
		tab[0] = '-';
		nbrs *= -1;
	}
	if (nbrs == 0)
		tab[0] = '0';
	while (nbrs > 0)
	{
		tab[i] = (nbrs % 10) + '0';
		nbrs /= 10;
		i--;
	}
	return (tab);
}
