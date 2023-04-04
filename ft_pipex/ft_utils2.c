/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:46:01 by dballini          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:47 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	emsg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(command, 0) == 0)
			return (command);
		free (command);
		paths++;
	}
	return (NULL);
}

char	*ft_get_path(char **envp)
{
	while (ft_strcmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
