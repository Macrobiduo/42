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
	while (*src)
	{
		if (*src == '\n')
		{
			src++;
			break ;
		}
		src++;
	}
	return (src);
}

char	*ft_read(int fd)
{
	char		*str;
	int			check;

	str = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	if (!str)
		return (NULL);
	check = read(fd, str, BUFFER_SIZE);
	if (check == 0)
		return (NULL);
	str[check] = '\0';
	return (str);
}

char	*ft_process(int fd, char *temp)
{
	static char		*extra;
	char			*str;

	while (1)
	{
		if (extra && temp[0] == '\0')
			temp = ft_strjoin(ft_cut(extra), temp);
		if (ft_strchr(temp, '\n') == NULL)
		{
			str = ft_read(fd);
			if (str == 0 && temp[0] != 0)
				return (temp);
			if (str == 0 && temp[0] == 0)
				return (str);
			temp = ft_strjoin(temp, ft_cut(str));
			extra = ft_getextra(str);
		}
		else
			break ;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*temp;

	temp = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = ft_process(fd, temp);
	return (temp);
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
