/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:56:47 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/21 17:13:46 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
		if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			write(1, &av[1][i], 1);
			i++;
		}
		while (av[1][i])
		{
			if ((av[1][i] >= 'A' && av[1][i] <= 'Z'))
			{
				write(1, "_", 1);
				ft_putchar(av[1][i] + 32);
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
