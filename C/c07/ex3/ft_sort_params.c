/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:29:55 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/24 21:00:07 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	gt_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	gt_comp(char *str, char *dest)
{
	int	i;

	i = 0;
	while ((str[i] && dest[i]) && str[i] == dest[i])
		i++;
	return (str[i] - dest[i]);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc - 1)
	{
		j = 0;
		while (++j < argc - 1)
		{
			if (gt_comp(argv[j], argv[j + 1]) > 0)
				gt_swap(&argv[j], &argv[j + 1]);
		}
	}
	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i])
			write(1, &argv[j][i++],1);
		write(1, "\n", 1);
	}
	return (0);
}
