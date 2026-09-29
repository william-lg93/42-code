/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:38:08 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/20 19:45:19 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				j = av[1][i] - 65;
				while (j >= 0)
				{
					write(1, &av[1][i], 1);
					j--;
				}
			}
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				j = av[1][i] - 97;
				while (j >= 0)
				{
					write(1, &av[1][i], 1);
					j--;
				}
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
