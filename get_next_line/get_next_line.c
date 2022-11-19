/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:41:01 by dballini          #+#    #+#             */
/*   Updated: 2022/11/17 14:41:01 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_ellipse(char *t)
{
	unsigned int			i;
	unsigned int			j;
	char					*s;

	i = 0;
	j = 0;
	while (t[i] != '\n')
		i++;
	while (t[i] != '\0')
	{
		j++;
		i++;
	}
	s = (char *) malloc (j);
	i -= j - 1;
	j = 0;
	while (t[i])
	{
		s[j] = t[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char			*str;
	char			*temp;
	static char		*extra;
	int				i;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_calloc(1, 1);
	if (extra != NULL)
			temp = ft_strjoin(temp, extra);
	while (1)
	{
		str = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
		if (!str)
			return (0);
		read(fd, str, BUFFER_SIZE);
		temp = ft_strjoin(temp, str);
		if (ft_strchr(str, '\n') != NULL && ft_strchr(str, '\0') != NULL)
		{
			free(str);
			break ;
		}
	}
	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			i++;
			extra = ft_ellipse(temp);
			break ;
		}
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
int main ()
{
	int		i = 0; 
	char	*s;
	int	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i <= 6)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
	}
	return (0);
}