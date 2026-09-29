/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:09:51 by codephenix2       #+#    #+#             */
/*   Updated: 2025/09/03 11:51:09 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n <= -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putchar(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_fizzbuzz(int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if (i % 3 == 0 && i % 5 == 0)
			ft_putstr("fizzbuzz\n");
		else if (i % 3 == 0)
			ft_putstr("fizz\n");
		else if (i % 5 == 0)
			ft_putstr("buzz\n");
		else
		{
			ft_putnbr(i);
			write(1, "\n", 2);
		}
		i++;
	}
}

int	main(void)
{
	ft_putstr("salut je m'appelle william\n");
	ft_putnbr(10);
	write(1, "\n", 2);
	ft_fizzbuzz(25);
	return (0);
}
