/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:33:17 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/09 14:24:51 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (1 < nb)
		return ((ft_recursive_factorial(nb - 1) * nb));
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_factorial(5));
}*/
