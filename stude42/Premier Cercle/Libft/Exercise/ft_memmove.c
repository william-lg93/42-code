/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:21:17 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/04 01:42:06 by gitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (!src || !dest)
		return (NULL);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

    for( int i=0; i<10; i++ ) {
        printf( "%d ", data[i] );
    }
    puts( "" );

    void * source = (void *) data;
    void * destination = (void *) ( data + 1 );
   // size_t size = 10 * sizeof( int );
    ft_memmove( destination, source, 10);

    data[0] = 10;

    for( int i=0; i<10; i++ ) {
        printf( "%d ", data[i] );
    }
    puts( "" );

    return EXIT_SUCCESS;
}
*/
