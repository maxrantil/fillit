/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_total.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:06:44 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/01 16:37:08 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	side_total_eight(char *tm)
{
	int	i;

	i = 0;
	while (tm[i] != '\0')
	{
		if (tm[i] == '2' || tm[i] == '.'
			|| tm[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	side_total_six(char *tm)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tm[i] != '\0')
	{
		if (tm[i] == '2')
			count++;
		else if (tm[i] == '3')
			count = 2;
		if (count == 2)
			return (1);
		i++;
	}
	return (0);
}
