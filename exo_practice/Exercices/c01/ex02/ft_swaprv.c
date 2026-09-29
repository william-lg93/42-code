/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaprv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:19:02 by codephenix2       #+#    #+#             */
/*   Updated: 2025/07/04 10:42:01 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

int	main(void)
{
	int	d;
	int	e;

	d = 5;
	e = 15;
	printf("a vaut %d \n", d);
	printf("b vaut %d \n", e);
	ft_swap(&d, &e);
	printf("a vaut %d \n", d);
	printf("b vaut %d \n", e);
}
