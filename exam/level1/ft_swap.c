/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:01:13 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/20 19:10:15 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	main ()
{
	int	a;
	int	b;

	a = 15;
	b = 26;
	printf("la valleur de a est de %d, et la valleur de b est de %d\n", a, b);
	ft_swap(&a, &b);
	printf("maintenant la valleur de a est de %d, et la valleur de b est de %d", a, b);
	return (0);
}
