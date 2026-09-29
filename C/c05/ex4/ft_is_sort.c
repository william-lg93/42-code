/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:08:17 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/17 15:25:38 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

int	ft_comp(int a, int b)
{
	if (a > b)
		return (136);
	else if (a < b)
		return (-13);
	else
		return (0);
}
*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			j++;
		else if (f(tab[i], tab[i + 1]) < 0)
			k++;
		if (j > 0 && k > 0)
			return (0);
		else
			i++;
	}
	return (1);
}
/*
int	main(void)
{
	int	i;
	int	tab[] = {1, 1, 1, 1, 0};
	int	tab2[] = {5, 4, 3, 2, 1};
	int	tab3[] = {1, 2, 3, 4, 8};
	int	tab4[] = {0, 2, 2, 1, 3};

	i = ft_is_sort(tab2, 5, &ft_comp);
	printf("%d", i);
}*/
