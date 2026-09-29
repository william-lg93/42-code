/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wineto-m <wineto-m@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 01:12:18 by wineto-m          #+#    #+#             */
/*   Updated: 2026/05/26 03:37:31 by wineto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fluxprincipal(int fd, t_list **stash)
{
	char	*buffer;
	int		play;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	play = read(fd, buffer, BUFFER_SIZE);
	while (play > 0)
	{
		buffer[play] = '\0';
		ft_lstadd_back(stash, ft_lstnew(buffer));
		if (ft_strchr(buffer, '\n'))
		{
			free(buffer);
			return ;
		}
		play = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
}

char	*buildline(t_list *stash)
{
	char	*tmp;

	char *(line) = NULL;
	while (stash != NULL)
	{
		if (!stash->str)
			break ;
		if (ft_strchr(stash->str, '\n'))
		{
			tmp = line;
			line = ft_strjoin(line, stash->str);
			free(tmp);
			if (ft_strchr(line, '\n'))
				line[ft_strchr(line, '\n') - line + 1] = '\0';
			break ;
		}
		tmp = line;
		line = ft_strjoin(line, stash->str);
		free(tmp);
		stash = stash->next;
	}
	return (line);
}

t_list	*clean(t_list *stash)
{
	t_list	*tmp;

	while (stash && !ft_strchr(stash->str, '\n'))
	{
		tmp = stash;
		stash = stash->next;
		free(tmp->str);
		free(tmp);
	}
	if (!stash)
		return (NULL);
	tmp = stash;
	if (*(ft_strchr(tmp->str, '\n') + 1) == '\0')
	{
		free(tmp->str);
		free(tmp);
		return (NULL);
	}
	stash = ft_lstnew(ft_strchr(tmp->str, '\n') + 1);
	stash->next = tmp->next;
	free(tmp->str);
	free(tmp);
	return (stash);
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	fluxprincipal(fd, &stash);
	line = buildline(stash);
	stash = clean(stash);
	return (line);
}
