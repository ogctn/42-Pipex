/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:29:46 by ogcetin           #+#    #+#             */
/*   Updated: 2023/05/26 20:31:57 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_checker(int ac, char **av, char **env)
{
	char	*cmd;

	if (ac != 5)
		ft_error("Invalid number of arguments");
	if (access(av[1], F_OK) == -1)
		ft_error("File does not exist");
	if (access(av[1], R_OK) == -1)
		ft_error("No permissions");
	cmd = path_finder(av[2], env);
	if (!cmd)
		ft_error("cmd1 not found");
	free(cmd);
	cmd = path_finder(av[3], env);
	if (!cmd)
		ft_error("cmd2 not found");
	free(cmd);
}
