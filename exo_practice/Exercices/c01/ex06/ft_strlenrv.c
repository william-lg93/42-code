/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenrv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codephenix2 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:49:39 by codephenix2       #+#    #+#             */
/*   Updated: 2025/07/23 12:00:09 by codephenix2      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	int	i;

	i = 0;
	printf("la valeur de i est de %d \n", i);
	i = ft_strlen("salut sa vas ?");
	printf("et maintenant la valeur de i est de %d \n", i);
}
