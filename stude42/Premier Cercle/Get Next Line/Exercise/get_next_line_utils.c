/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:15:51 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/26 02:54:57 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst != NULL)
		lst = &(*lst)->next;
	*lst = new;
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *(str);
	int (i) = 0;
	int (j) = 0;
	int (k) = 0;
	int (l) = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	while (s1[k])
		k++;
	while (s2[l])
		l++;
	str = malloc (sizeof(char) * (k + l + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*str;

	int (i) = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	str = malloc (sizeof(char) * i + 1);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->str = ft_strdup(content);
	lst->next = NULL;
	return (lst);
}
