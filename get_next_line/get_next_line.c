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

char	*ft_process1(int fd, char *ret, char *temp)
{
	if (ft_strchr(ret, '\n') == NULL && temp != 0)
	{
		ret = ft_strjoin(ret, temp);
		temp = ft_read(fd);
	}
	if (temp == 0 && ret[0] == '\0')
		return (0);
	return (ret);
}

char	*ft_process(int fd, char *ret, char *temp)
{
	static char		*extra;

	while (1)
	{
		if (extra != NULL)
		{
			ret = ft_strjoin(ret, ft_cut(extra));
			extra = ft_getextra(extra);
		}
		ret = ft_process1(fd, ret, temp);
		if (ret == 0)
			break ;
		if (ft_strchr(ret, '\n') == NULL && temp == 0)
			break ;
		if (ft_strchr(temp, '\n') != NULL)
		{
			ret = ft_strjoin(ret, ft_cut(temp));
			extra = ft_getextra(temp);
			break ;
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char			*temp;
	char				*ret;

	ret = ft_calloc(1, 1);
	temp = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ret = ft_process(fd, ret, temp);
	return (ret);
}
/*int	main(void)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	fd = open("test.txt", O_RDONLY);
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
