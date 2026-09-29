/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:39:43 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/17 18:12:44 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
/*
int	ft_double(int a)
{
	a *= 2;
	return (a);
}
*/
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*jj;

	i = 0;
	jj = malloc (sizeof(int) * length);
	if (jj == NULL)
		return (NULL);
	while (i < length)
	{
		jj[i] = f(tab[i]);
		i++;
	}
	return (jj);
}
/*
#include <stdio.h>

int	main(void)
{
	int	tab[] = {5,9,8,6};
	int	i = 0;
	int	*c;

	c = ft_map(tab, 4, &ft_double);
	while (tab[i])
	{
		printf("%d", c[i]);
		i++;
	}
	return (0);
}*/
