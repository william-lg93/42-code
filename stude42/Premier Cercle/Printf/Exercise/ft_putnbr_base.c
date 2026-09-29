/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 05:24:26 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/11 05:43:16 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long unsigned int nbr, const char *base)
{
	int (i) = 0;
	unsigned long (base_len) = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		i += ft_putnbr_base(nbr / base_len, base);
	i += ft_putchar(base[nbr % base_len]);
	return (i);
}

int	ft_putnbr(int nbr)
{
	int (count) = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int (count) = 0;
	if (nbr >= 10)
		count += ft_putnbr_unsigned(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_putchar(int c)
{
	char	ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int (i) = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
