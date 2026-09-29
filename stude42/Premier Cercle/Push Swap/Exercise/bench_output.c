/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kafitous <kafitous@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 15:36:22 by kafitous          #+#    #+#             */
/*   Updated: 2026/05/30 18:12:03 by kafitous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_print_strategy(t_bench *data)
{
	ft_putstr_fd("[bench] stategy: ", 2);
	if (data->start == 1)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (data->start == 2)
		ft_putstr_fd("Medium / O(n*sqrt(n))\n", 2);
	else if (data->start == 3)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
}

static void	ft_print_ops_line1(t_bench *data)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(data->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	ft_print_ops_line2(t_bench *data)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(data->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_print_bench(t_bench *data)
{
	int	total;

	total = data->sa + data->sb + data->ss + data->pa + data->pb
		+ data->ra + data->rb + data->rr + data->rra + data->rrb + data->rrr;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_put_float(data->disorder);
	ft_putstr_fd("%\n", 2);
	ft_print_strategy(data);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	ft_print_ops_line1(data);
	ft_print_ops_line2(data);
}
