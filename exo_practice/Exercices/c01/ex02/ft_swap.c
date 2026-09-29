/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:19:36 by codephenix2       #+#    #+#             */
/*   Updated: 2025/05/20 10:28:14 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = 0;
	c = *a;
	*a = *b;
	*b = c;
}

/* #include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	b = 2;
	a = 5;
	printf(" %d ", a);
	printf(" %d ", b);
	ft_swap(&a, &b);
	printf("\n");
	printf(" %d ", a);
	printf(" %d ", b);
	printf("\n");
}*/
