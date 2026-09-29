/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:30:22 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/24 18:32:59 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if(argc != 1)
		return (0);
	while(argv[0][i])
	{
		write(1, &argv[0][i], 1);
		i++;
	}
	return (0);

}
