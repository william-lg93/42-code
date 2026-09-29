/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:44:24 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/08 22:19:12 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;
	int	d;

	c = *a;
	d = *b;
	*a = c / d;
	*b = c % d;
}

#include <stdio.h>

int	main(void)
{
	int	a = 127;
	int	b = 16;
	ft_ultimate_div_mod(&a, &b);
	printf("resulta :%d\nreste :%d", a, b);
}
