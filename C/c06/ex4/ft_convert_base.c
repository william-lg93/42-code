/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:22:44 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/25 02:20:51 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	gt_result_in(char *result, long n, char *base, int base_len);
void	gt_rev_str(char *str, int start);
int		gt_lenbase(char *base);
int		gt_char_b(char c, char *base);
int		gt_validation(char *base);

int	atoi_base(char *nbr, char *base_from)
{
	int	index;

	int (i) = 0;
	int (result) = 0;
	int (sign) = 1;
	if (!gt_validation(base_from))
		return (0);
	while (((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		|| nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i])
	{
		index = gt_char_b(nbr[i], base_from);
		if (index == -1)
			break ;
		result = result * gt_lenbase(base_from) + index;
		i++;
	}
	return (result * sign);
}

char	*itoa_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	long	nb;

	if (!gt_validation(base))
		return (NULL);
	base_len = gt_lenbase(base);
	nb = nbr;
	result = malloc(50);
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
		gt_result_in(result + 1, nb, base, base_len);
		gt_rev_str(result, 1);
	}
	else
	{
		gt_result_in(result, nb, base, base_len);
		gt_rev_str(result, 0);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;

	if (!gt_validation(base_from) || !gt_validation(base_to))
		return (NULL);
	num = atoi_base(nbr, base_from);
	result = itoa_base(num, base_to);
	return (result);
}
/*
int	main(int argc, char **argv)
{
	char	*result;

	(void) argc;
	result = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s\n", result);
}*/
