/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:46:08 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/09 22:04:25 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - i)
	{
		j = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = j;
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	int	tab[6] = {5,8,9,2,3,1};
	int	i = 0;

	while (i < 6)
        {
                printf("%d", tab[i]);
		i++;
        }
	i = 0;
	ft_rev_int_tab(tab, 6);
	printf("\n");
	while (i < 6)
	{
		printf("%d", tab[i]);
		i++;
	}
	return (0);
}*/
