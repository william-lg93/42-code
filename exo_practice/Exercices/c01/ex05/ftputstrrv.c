/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftputstrrv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:47:55 by codephenix2       #+#    #+#             */
/*   Updated: 2025/07/11 10:12:12 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	main(void)
{
	ft_putstr("yo mec \n");
	ft_putstr("jjjjjjjjj     iiiiiiiii 989999999 \n");
	ft_putstr("956498vfdvdfhtgsh46    546dezferg5vczejbfzei IUGFUEZF52564OZEOOFIEÉÉÉÉÈÈÈÈÎÎÊ");

}
