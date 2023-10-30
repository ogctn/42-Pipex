/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogcetin <ogcetin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:39:37 by ogcetin           #+#    #+#             */
/*   Updated: 2023/05/22 17:39:56 by ogcetin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_double(char ***m)
{
	int	i;

	i = 0;
	while (m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	free(m[0]);
	m = NULL;
}
