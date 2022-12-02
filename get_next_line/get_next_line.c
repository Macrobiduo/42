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

char	*ft_getextra(char *extra)
{
	if (!extra)
		return (NULL);
	while (*extra)
	{
		if (*extra == '\n')
		{
			extra++;
			break ;
		}
		extra++;
	}
	return (extra);
}

char	*ft_read(int fd)
{
	char		*ret;
	char		*str;
	int			check;

	check = 1;
	ret = ft_calloc(1, 1);
	while (check > 0)
	{
		str = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
		if (!str)
			return (NULL);
		check = read(fd, str, BUFFER_SIZE);
		if (check == 0)
			break ;
		else	
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
	line = ft_read(fd);
	if (extra)
		line = ft_strjoin(extra, line);
	extra = ft_getextra(line);
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
