/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:30:45 by ogcetin           #+#    #+#             */
/*   Updated: 2023/05/26 20:33:32 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**split_env(char **env)
{
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		tmp = ft_strnstr(env[i], "PATH=", 5);
		if (tmp)
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

void	free_2d(char **l)
{
	int	i;

	i = 0;
	while (l[i])
		free(l[i++]);
	free(l);
}

char	*path_finder(char *cmd, char **env)
{
	t_path		path;
	int			i;

	path.sp_env = split_env(env);
	path.sp_cmd = ft_split(cmd, ' ');
	i = -1;
	while (path.sp_env[++i])
	{
		path.full_path = ft_strjoin(path.sp_env[i], "/", NULL);
		path.full_path = \
			ft_strjoin(path.full_path, path.sp_cmd[0], path.full_path);
		if (access(path.full_path, F_OK) == 0)
		{
			free_2d(path.sp_cmd);
			free_2d(path.sp_env);
			return (path.full_path);
		}
		free(path.full_path);
	}
	free_2d(path.sp_cmd);
	free_2d(path.sp_env);
	return (NULL);
}
