/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 03:00:59 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/11 19:32:51 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	adress;

	int (count) = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	adress = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_putnbr_base(adress, "0123456789abcdef");
	return (count);
}

int	sign(va_list f, char c)
{
	int (count) = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(f, int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(f, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(f, unsigned int));
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(f, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(f, unsigned int), "0123456789ABCDEF");
	else if (c == 's')
		count += ft_putstr(va_arg(f, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(f, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	int (i) = 0;
	int (count) = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += sign(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

"bonjour je suis la a %d h %d ce %s de la semaine"
48
"bonjour je suis la a 18 h 30 ce vendredi de la semaine"
54