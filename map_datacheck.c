/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_datacheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:55:08 by dclement          #+#    #+#             */
/*   Updated: 2024/03/18 15:21:11 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_linecount(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	is_valid_char(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1'
		|| c == '0')
		return (TRUE);
	return (FALSE);
}

// int	is_unique_char(char c, char to_check, t_bool *bool)
// {
// 	if (c == to_check && *bool == FALSE)
// 		*bool = TRUE;
// 	else if (c == to_check && *bool == TRUE)
// 		return (FALSE);
// 	return (TRUE);
// }

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
