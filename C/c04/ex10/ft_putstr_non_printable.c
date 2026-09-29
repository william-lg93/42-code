/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:32:12 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/12 16:21:24 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*l;
	int		i;

	l = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			ft_putchar(l[str[i] / 16]);
			ft_putchar(l[str[i] % 16]);
		}
		i++;
	}
}
/*
int	main(void)
{
	char	c[] = "suuui\nhcphpe";

	ft_putstr_non_printable(c);
}*/
