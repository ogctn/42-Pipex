/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:37:49 by ogcetin           #+#    #+#             */
/*   Updated: 2023/05/26 20:32:08 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**space_split_argv(char **av, int mode)
{
	char	**argv;
	char	*temp;

	if (mode == 1)
	{	
		temp = ft_strjoin(av[2], " ", NULL);
		temp = ft_strjoin(temp, av[1], temp);
		argv = ft_split(temp, ' ');
		free(temp);
		return (argv);
	}
	temp = ft_strjoin(av[3], " ", NULL);
	argv = ft_split(temp, ' ');
	free(temp);
	return (argv);
}

void	set_fd_child(int fd[2])
{
	close(fd[READ_END]);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
	{
		ft_error("Dup error");
	}
	close(fd[WRITE_END]);
}

void	set_fd_parent(int fd[2], int output)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		ft_error("Dup error");
	}
	close(fd[0]);
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		ft_error("Dup error");
	}
}

void	close_pipe(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}
