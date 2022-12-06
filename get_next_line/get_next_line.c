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
	if (!extra || ft_strchr(extra, '\n') == NULL)
		return (NULL);
	while (extra[i] != '\n' && extra[i])
		i++;
	if (extra[i] == '\n')
		i++;
	if (!extra[i++])
	{
		free (extra);
		return (0);
	}
	i--;
	p = ft_calloc(ft_strlen(extra) - i + 1, 1);
	if (!p)
		return(NULL);
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
		free (str);
		if (check == 0)
			break ;
		if (ft_strchr(ret, '\n') != NULL)
			break ;
	}
	if (ret[0] == '\0')
	{
		free (ret);
		ret = 0;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*tmp;
	char			*line;
	static char		*extra;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (ft_strchr(extra, '\n') == NULL)
		line = ft_read(fd, extra);
	else
	{
		line = ft_strdup(extra);
		free (extra);
		extra = 0;
	}
	if (line == 0 && !extra)
		return (line);
	tmp = ft_strdup(line);
	extra = ft_getextra(line);
	line = ft_cut(tmp);
	return (line);
}
/*int	main(void)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	fd = open("/nfs/homes/dballini/Documents/libft/42/get_next_line/t.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i < 15)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
	return (0);
}*/
