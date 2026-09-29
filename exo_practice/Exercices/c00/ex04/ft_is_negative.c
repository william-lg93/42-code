/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:44:51 by codephenix2       #+#    #+#             */
/*   Updated: 2025/05/13 09:44:49 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar('P');
	if (n < 0)
		ft_putchar('N');
}

int	main(void)
{
	ft_is_negative(-9);
	ft_is_negative(15);
	ft_is_negative(0);
	ft_is_negative(-5);
	ft_is_negative(80);
	return (0);
}
