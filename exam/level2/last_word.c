/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:49:01 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/23 15:14:24 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	j;

	if (ac == 2)
	{
		j = ft_strlen(av[1]) - 1;
		while ((j > 0) && !(av[1][j] == ' ' || (av[1][j] >= 9 && av[1][j] <= 13)))
			j--;
		if (j > 0)
			j++;
		while (av[1][j])
		{
			write(1, &av[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
