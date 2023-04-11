/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dballini <dballini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:35:07 by dballini          #+#    #+#             */
/*   Updated: 2023/04/11 13:03:27 by dballini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_child(t_pipex piper)
{
	int	i;

	i = 0;
	ft_free_parent(piper);
	while (piper.cmd_args[i])
	{
		free(piper.cmd_args[i]);
		i++;
	}
	free(piper.cmd_args);
	free(piper.my_cmd);
}

void	ft_free_parent(t_pipex piper)
{
	int	i;

	i = 0;
	close(piper.f1);
	close(piper.f2);
	while (piper.cmd_paths[i])
	{
		free(piper.cmd_paths[i]);
		i++;
	}
	free(piper.cmd_paths);
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
