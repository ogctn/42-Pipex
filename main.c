/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:10:01 by ogcetin           #+#    #+#             */
/*   Updated: 2023/05/26 20:34:27 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_pipex(char **av, char **env)
{
	char	**args;
	int		fd[2];
	int		output;
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		args = space_split_argv(av, 1);
		set_fd_child(fd);
		execve(path_finder(args[0], env), args, env);
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		output = open(av[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
		args = space_split_argv(av, 2);
		set_fd_parent(fd, output);
		execve(path_finder(args[0], env), args, env);
		exit(1);
	}
	close_pipe(fd);
	wait(NULL);
}

int	main(int ac, char **av, char **env)
{
	arg_checker(ac, av, env);
	execute_pipex(av, env);
	return (0);
}
