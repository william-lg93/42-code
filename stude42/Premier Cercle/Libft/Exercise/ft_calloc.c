/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:12:14 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/03 01:34:05 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	unsigned char	*p;

	size_t (i) = 0;
	if (elementsize == 0 || elementcount == 0)
		return (malloc(0));
	if (elementcount > SIZE_MAX / elementsize)
		return (NULL);
	p = malloc((elementcount * elementsize));
	if (!p)
		return (NULL);
	while (i < elementsize * elementcount)
		p[i++] = 0;
	return (p);
}
