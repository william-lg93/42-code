/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:47:13 by codephenix2       #+#    #+#             */
/*   Updated: 2025/05/06 10:10:58 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	displayer(char m, char c, char d, char u)
{
	ft_putchar(m);
	ft_putchar(c);
	ft_putchar(' ');
	ft_putchar(d);
	ft_putchar(u);
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	char	m;
	char	c;
	char	d;
	char	u;

	while (m <= '9' && c <= '8')
	{
		if (c != '8')
		{
			while (d <= '9' && u <= '9')
			{
				if (d != 9)
				{
					displayer(m, c, d, u);
					u++;
				}
				else
				{
					d++;
					u = '0';
				}
			}
			else
			{
				m++;
				c = '0';
			}
		}
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
