/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:04:07 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/21 16:53:21 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'm')
				ft_putchar(122 - (av[1][i] - 97));
			else if (av[1][i] >= 'A' && av[1][i] <= 'M')
				ft_putchar(90 - (av[1][i] - 65));
			else if (av[1][i] >= 'n' && av[1][i] <= 'z')
				ft_putchar(110 - (av[1][i] - 109));
			else if (av[1][i] >= 'N' && av[1][i] <= 'Z')
				ft_putchar(78 - (av[1][i] - 77));
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
