/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_carrer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:15:33 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/30 00:34:26 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_racine_carrer(int vallue)
{
	int	result;

	int (tmp) = 0;
	if (tmp == vallue)
		return (-1);
	while (1)
	{
		result = tmp;
		if (result * tmp < vallue)
		{
			tmp++;
			result++;
		}
		else if (result * tmp > vallue)
			tmp--;
		else
			return (tmp);
		if (tmp != result)
			break ;
	}
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d", ft_racine_carrer(atoi(av[1])));
	return (0);
}
