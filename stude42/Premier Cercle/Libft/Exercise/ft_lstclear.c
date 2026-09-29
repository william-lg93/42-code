/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:10:25 by wineto-m          #+#    #+#             */
/*   Updated: 2026/04/30 20:50:24 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tls;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tls = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tls;
	}
	*lst = NULL;
}
