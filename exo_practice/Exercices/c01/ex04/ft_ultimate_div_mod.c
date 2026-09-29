/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:37:12 by codephenix2       #+#    #+#             */
/*   Updated: 2025/07/09 11:46:33 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = c / *b;
	*b = c % *b;
}

int	main(void)
{
	int	i;
	int	x;

	i = 19;
	x = 5;
	printf("nous allont diviser %d et %d \n", i, x);
	ft_ultimate_div_mod(&i, &x);
	printf("le quotien est %d et le reste %d \n", i, x);
}
