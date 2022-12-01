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

char	*ft_getextra(char *src)
{
	char		*p;
	int		i;
	int		k;

	k = ft_strlen(src);
	i = 0;
	if (ft_strchr(src, '\n') == NULL)
		return (NULL);
	while (*src)
	{
		if (*src == '\n')
			break ;
		src++;
		i++;
	}
	src++;
	p = ft_calloc(k - i, 1);
	i = 0;
	while (*src)
		p[i++] = *src++;
	return (p);
}

char	*ft_read(int fd)
{
	char		*str;
	int			check;

	str = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (NULL);
	check = read(fd, str, BUFFER_SIZE);
	if (check == 0)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char		*extra;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = ft_calloc(1, 1);
	while (1)
	{
		if (extra)
			line = ft_strjoin(extra,line);
		line = ft_strjoin(line,ft_read(fd));
		if (line == 0)
			break ;
		if (ft_strchr(line, '\n') != NULL)
		{
			extra = ft_getextra(line);
			line = ft_cut(line);
			break ;
		}
	}
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
