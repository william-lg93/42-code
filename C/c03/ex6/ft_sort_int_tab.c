/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:46:20 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/30 00:47:14 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	pass;

	pass = size - 1;
	while (pass >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		pass--;
	}
}

#include <stdio.h>

int     main(void)
{
        int     tab[6] = {10,97,9,95,8,93};
        int     i = 0;

        while (i < 6)
        {
                printf("%d, ", tab[i]);
                i++;
        }
        i = 0;
        ft_sort_int_tab(tab, 6);
        printf("\n");
        while (i < 6)
        {
                printf("%d, ", tab[i]);
                i++;
        }
        return (0);
}
