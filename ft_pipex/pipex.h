/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:48:29 by dballini          #+#    #+#             */
/*   Updated: 2023/04/11 13:03:09 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct t_pipex
{
	int		end[2];
	pid_t	child1;
	pid_t	child2;
	int		f1;
	int		f2;
	char	*paths;
	char	*my_cmd;
	char	**cmd_paths;
	char	**cmd_args;
}		t_pipex;

int		emsg(char *err);
char	*ft_get_cmd(char **paths, char *cmd);
char	*ft_get_path(char **envp);
void	ft_free_tab(char **tab);
void	msg_error(char *err);
void	ft_child(t_pipex piper, char *av[], char *envp[]);
void	ft_parent(t_pipex piper, char *av[], char *envp[]);
void	ft_pipex(t_pipex piper, char *av[], char *envp[]);
void	ft_free_child(t_pipex piper);
void	ft_free_parent(t_pipex piper);
#endif