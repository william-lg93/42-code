/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fu_putnbrrv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:03:37 by codephenix2       #+#    #+#             */
/*   Updated: 2025/06/23 15:08:11 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	nb = 0;

	ft_putchar(nb);
}
 int	main(void)
{
	ft_putnbr(25);
	ft_putnbr(56);
	ft_putnbr(10);
}
