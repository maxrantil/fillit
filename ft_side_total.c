/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_total.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:06:44 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/19 14:45:51 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_side_total_eight(char *tm)
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

int	ft_side_total_six(char *tm)
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

void	ft_free_read(t_r_var pni)
{
	ft_strdel(&pni.temp2);
	ft_strdel(&pni.temp3);
	ft_strdel(&pni.buffer);
}
