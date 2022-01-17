/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonnrot <llonnrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:37:04 by llonnrot          #+#    #+#             */
/*   Updated: 2021/12/30 15:18:46 by llonnrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_read_file(int fd, char **copy_of_file)
{
	t_r_var	pni;

	pni.count = 0;
	pni.readret = 1;
	pni.temp2 = ft_strnew(BUFF_SIZE);
	pni.temp3 = ft_strnew(BUFF_SIZE);
	pni.buffer = ft_strnew(BUFF_SIZE);
	while (pni.readret)
	{
		if (pni.readret == -1)
			return (-1);
		pni.readret = read(fd, pni.buffer, BUFF_SIZE);
		ft_strdel(&pni.temp2);
		pni.temp2 = ft_strjoin(pni.temp3, pni.buffer);
		ft_strdel(&pni.temp3);
		pni.temp3 = ft_strdup(pni.temp2);
		ft_bzero(pni.buffer, ft_strlen(pni.buffer));
		pni.count++;
	}
	*copy_of_file = pni.temp3;
	ft_strdel(&pni.temp2);
	ft_strdel(&pni.buffer);
	return (pni.count);
}
