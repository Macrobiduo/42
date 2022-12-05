/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:39:12 by dballini          #+#    #+#             */
/*   Updated: 2022/11/25 15:39:12 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(src);
	if (size == 0)
		return (src);
	new = malloc(size + 1);
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
	int		i;
	int		j;
	char		*p;

	i = 0;
	j = -1;
	if (!extra || ft_strchr(extra, '\n') == NULL)
		return (NULL);
	while (extra[i] != '\n' && extra[i])
		i++;
	if (!extra[i + 1])
		return (0);
	p = ft_calloc(ft_strlen(extra) - i, 1);
	while (extra[i++])
		p[++j] = extra[i];
	free (extra);
	return (p);
}

char	*ft_read(int fd)
{
	char		*ret;
	char		*str;
	int			check;

	ret = ft_calloc (1, 1);
	while (1)
	{	
		str = ft_calloc (BUFFER_SIZE + 1, 1);
		if (!str)
			return (NULL);
		check = read(fd, str, BUFFER_SIZE);
		if (check == 0)
			break ;
		ret = ft_strjoin(ret, str);
		if (ft_strchr(ret, '\n') != NULL)
			break ;
	}
	if (ret[0] == '\0')
		ret = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*extra;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (ft_strchr(extra, '\n') == NULL)
		line = ft_read(fd);
	else
	{
		line = ft_strdup(extra);
		extra = 0;
	}
	if (line == 0 && !extra)
		return (line);
	if (extra)
		line = ft_strjoin(ft_strdup(extra), line);
	extra = ft_getextra(ft_strdup(line));
	line = ft_cut(line);
	return (line);
}
int	main(void)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	fd = open("/nfs/homes/dballini/Documents/libft/42/get_next_line/t.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < 6)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
	return (0);
}