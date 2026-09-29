/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:12:53 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/09 12:27:13 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	affiche(int *tab, int a)
{
	int	b;

	b = 0;
	while (b < a)
	{
		ft_putchar(tab[b] + '0');
		b++;
	}
}

void	avancer(int *tab, int n)
{
	int	c;
	int	d;

	while (1)
	{
		d = n;
		affiche(tab, n);
		if (tab[0] == 9 - (n - 1))
			break ;
		write(1, ", ", 2);
		d--;
		while (d >= 0 && tab[d] == 9 - (n - 1 - d))
			d--;
		if (d >= 0)
			tab[d]++;
		c = d + 1;
		while (c < n)
		{
			tab[c] = tab[c - 1] + 1;
			c++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[10];

	i = 0;
	if (n < 1 || n > 9)
		return ;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	avancer(tab, n);
}
int	main(void)
{
	ft_print_combn(8);
}
