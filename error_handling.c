/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:54:13 by dclement          #+#    #+#             */
/*   Updated: 2024/03/18 13:00:28 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(const char *str)
{
	ft_printf("Error:\n %s", str);
	return (0);
}

void	*null_err(const char *str)
{
	ft_printf("Error:\n %s", str);
	return (0);
}
