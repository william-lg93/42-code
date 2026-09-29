/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:56:08 by wineto-m          #+#    #+#             */
/*   Updated: 2026/06/20 19:00:43 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	(i) = 0;
	while(str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d", ft_strlen(av[1]));
	return (0);
}
