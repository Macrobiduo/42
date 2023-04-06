/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:48:31 by dballini          #+#    #+#             */
/*   Updated: 2023/04/06 14:26:50 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(pipex_t piper, char *av[], char *envp[])
{
	dup2(piper.end[1], 1);
	close(piper.end[0]);
	dup2(piper.f1, 0);
	piper.cmd_args = ft_split(av[2], ' ');
	piper.my_cmd = ft_get_cmd(piper.cmd_paths, piper.cmd_args[0]);
	if (!piper.my_cmd)
	{
		ft_free_child(piper);
		emsg(ERR_CMD);
		exit(1);
	}
	execve(piper.my_cmd, piper.cmd_args, envp);
}

void	ft_parent(pipex_t piper, char *av[], char *envp[])
{
	dup2(piper.end[0], 0);
	close(piper.end[1]);
	dup2(piper.f2, 1);
	piper.cmd_args = ft_split(av[3], ' ');
	piper.my_cmd = ft_get_cmd(piper.cmd_paths, piper.cmd_args[0]);
	if (!piper.my_cmd)
	{
		ft_free_child(piper);
		emsg(ERR_CMD);
		exit(1);
	}
	execve(piper.my_cmd, piper.cmd_args, envp);
}

void	ft_pipex(pipex_t piper, char *av[], char *envp[])
{
	if(pipe(piper.end) < 0)
		msg_error(ERR_PIPE);
	piper.child1 = fork();
	if (piper.child1 == 0)
		ft_child(piper, av, envp);
	piper.child2 = fork();
	if (piper.child2 == 0)
		ft_parent(piper, av, envp);
	close(piper.end[0]);
	close(piper.end[1]);
	waitpid(piper.child1, NULL, 0);
	waitpid(piper.child2, NULL, 0);
	ft_free_parent(piper);
}

int   main(int ac, char *av[], char *envp[])
{
	pipex_t	piper;

	if (ac != 5)
		return (emsg(ERR_INPUT));
	piper.f1 = open(av[1], O_RDONLY);
	if (piper.f1 < 0)
		msg_error(ERR_INFILE);
	piper.f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (piper.f2 < 0)
		msg_error(ERR_OUTFILE);
	piper.paths = ft_get_path(envp);
	piper.cmd_paths = ft_split(piper.paths, ':');
	ft_pipex(piper, av, envp);
	return (0);
}