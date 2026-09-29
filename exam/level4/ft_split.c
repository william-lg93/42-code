/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:05:46 by wineto-m          #+#    #+#             */
/*   Updated: 2026/07/02 15:31:10 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split(char *str)
{
	int	index = 0;
	int	i = 0;
	int	j = 0;
	char	**tab;

	tab = malloc(sizeof(char *) * 1000);
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index])
	{
		if (str[index] > 32)
		{
			tab[i] = malloc(sizeof(char) * 1000);
			while (str[index] & str[index] > 32)
			{
				tab[i][j] = str[index];
				index++;
				j++;
			}
			tab[i][j] = '\0';
			j = 0;
			i++;
		}
		else
			index++;
	}
	tab[i] = NULL;
	return (tab);
}
