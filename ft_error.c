/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:15:32 by ogcetin           #+#    #+#             */
/*   Updated: 2023/05/26 18:08:04 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *reason)
{
	ft_putstr_fd("\x1b[31mPipex Error: ", 2);
	ft_putstr_fd(reason, 2);
	ft_putstr_fd("!\n\x1b[0m", 2);
	exit(-1);
}
