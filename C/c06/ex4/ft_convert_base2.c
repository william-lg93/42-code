/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:41:00 by wineto-m          #+#    #+#             */
/*   Updated: 2026/03/25 02:16:42 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	gt_lenbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	gt_rev_str(char *str, int start)
{
	int		end;
	char	temp;

	end = gt_lenbase(str);
	end--;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

void	gt_result_in(char *result, long n, char *base, int base_len)
{
	int	i;

	i = 0;
	if (n == 0)
		result[i++] = base[0];
	while (n > 0)
	{
		result[i++] = base[n % base_len];
		n /= base_len;
	}
	result[i] = '\0';
}

int	gt_char_b(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	gt_validation(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == 32 || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	while (base[j])
	{
		i = j + 1;
		while (base[i])
		{
			if (base[j] == base[i])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
