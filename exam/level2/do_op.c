/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:51:00 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/21 18:08:00 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int	ft_utils(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] <= '0' && s1[i] >= '9')
			return (1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (s1[i] <= '0' && s1[i] >= '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	if (ac == 4)
	{
		k = ft_strlen(av[2]);
		if (k != 1)
		{
			write(1, "\n", 1);
			return (0);
		}
		if (ft_utils(av[1], av[3]))
		{
			write(1, "\n", 1);
			return(0);
		}

		i = atoi(av[1]);
		j = atoi(av[3]);
		if (av[2][0] == '/')
			printf("%d", (i / j));
		else if (av[2][0] == '*')
			printf("%d", (i * j));
		else if (av[2][0] == '-')
			printf("%d", (i - j));
		else if (av[2][0] == '+')
			printf("%d", (i + j));
		else if (av[2][0] == '%')
			printf("%d", (i % j));
	}
	printf("\n");
	return (0);
}
