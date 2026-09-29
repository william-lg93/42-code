/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 01:16:33 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/03 01:32:02 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lenght;

	i = 0;
	lenght = ft_strlen(src);
	if (size == 0)
		return (lenght);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lenght);
}
/*
#include <stdio.h>
#include <string.h>
int     main()
{
        char str[] = "253";
        char str1[] = "vvwdbovfwbofpwbjd";
	printf("%ld\n", strlcpy(str, str1, 2));
        printf("%ld\n", ft_strlcpy(str, str1, 2));
}*/
