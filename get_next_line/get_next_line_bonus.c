/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:35:58 by dballini          #+#    #+#             */
/*   Updated: 2022/12/13 18:36:48 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(src);
	if (size == 0)
		return (src);
	new = (char *)malloc(size + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_getextra(char *extra)
{
	int			i;
	int			j;
	char		*p;

	i = 0;
	j = -1;
	while (extra[i] != '\n' && extra[i])
		i++;
	if (extra[i] == '\n')
		i++;
	if (!extra[i])
	{
		free (extra);
		return (0);
	}
	p = ft_calloc(ft_strlen(extra) - i + 1, 1);
	if (!p)
		return (NULL);
	while (extra[i])
	{
		p[++j] = extra[i];
		i++;
	}
	free (extra);
	return (p);
}

char	*ft_read(int fd, char *ret)
{
	char		*str;
	int			check;

	if (!ret)
		ret = ft_calloc (1, 1);
	while (1)
	{
		str = ft_calloc(BUFFER_SIZE + 1, 1);
		check = read(fd, str, BUFFER_SIZE);
		ret = ft_strjoin(ret, str);
		if (check == 0)
			break ;
		if (ft_strchr(ret, '\n') != NULL)
			break ;
	}
	if (ret[0] == '\0' && check == 0)
	{
		free (ret);
		ret = 0;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*extra[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (ft_strchr(extra[fd], '\n') == 0)
		extra[fd] = ft_read(fd, extra[fd]);
	if (extra[fd] == NULL)
		return (NULL);
	line = ft_cut(ft_strdup(extra[fd]));
	extra[fd] = ft_getextra(extra[fd]);
	return (line);
}
