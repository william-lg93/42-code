/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:38:26 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/09 16:44:02 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>

int	main(void)
{
	int	a = 15;
	int	b = 6;
	int	c = 0;
	int	d = 0;

	ft_div_mod(a, b, &c, &d);
	printf("%d est le resulta et %d est le reste", c, d);	
}*/
