/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:37:22 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/24 18:46:28 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i - 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	if (argc < 2)
		return (0);
	k = len(argv);
	while (i <= k)
	{
		j = 0;
		while (argv[k][j])
		{
			write(1, &argv[k][j], 1);
			j++;
		}
		write(1, "\n", 1);
		k--;
	}
	return (0);
}
