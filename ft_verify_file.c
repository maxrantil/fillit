/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonnrot <llonnrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:11:43 by llonnrot          #+#    #+#             */
/*   Updated: 2021/12/30 15:19:43 by llonnrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_verify_file(char *copy_of_file, char	**tetrominos)
{
	if (copy_of_file[ft_strlen(copy_of_file) - 1] != '\n')
		return (-1);
	if (copy_of_file[ft_strlen(copy_of_file) - 2] != '.'
		 && copy_of_file[ft_strlen(copy_of_file) - 2] != '#')
		return (-1);
	ft_divide_pieces(copy_of_file, tetrominos);
	if (ft_verify_pieces(tetrominos) == -1)
		ft_putstr("error, piece not valid\n");
	if (ft_verify_pieces_two(tetrominos) == -1)
		ft_putstr("error, piece not valid\n");
	return (0);
}
