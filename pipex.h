/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:49:36 by ogcetin           #+#    #+#             */
/*   Updated: 2023/05/26 20:36:41 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./Libft/libft.h"

# define OUTFILE 4
# define INFILE 1
# define READ_END 0
# define WRITE_END 1

typedef struct s_path
{
	char	**sp_env;
	char	**sp_cmd;
	char	*full_path;
}			t_path;

void	ft_error(char *reason);
void	arg_checker(int ac, char **av, char **env);
char	*path_finder(char *cmd, char **env);
char	**space_split_argv(char **av, int mode);
void	set_fd_child(int fd[2]);
void	set_fd_parent(int fd[2], int output);
void	close_pipe(int fd[2]);
void	wait_twice(void);

#endif