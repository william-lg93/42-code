/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphabet+1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:52:32 by codephenix2       #+#    #+#             */
/*   Updated: 2025/09/03 12:18:11 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_alphabetsp(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 121)
			ft_putchar(str[i] + 1);
		else if (str[i] >= 65 && str[i] <= 89)
			ft_putchar(str[i] + 1);
		else if (str[i] == 122)
			ft_putchar(97);
		else if (str[i] == 90)
			ft_putchar(65);
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(void)
{
	ft_alphabetsp("abc !ABC z ^Z");
}
