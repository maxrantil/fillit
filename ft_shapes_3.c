/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/01/19 15:27:13 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_no_dots(char *copy_of_file)
{
	int	i;
	int	c;
	int	nl;

	i = 0;
	c = 0;
	nl = 0;
	while (copy_of_file[i] != '\0')
	{
		if (copy_of_file[i] == '.')
			c++;
		i++;
		if ((copy_of_file[i] == '\n' && copy_of_file[i + 1] == '\n')
			|| ft_strlen(copy_of_file) == 20)
			nl++;
	}
	if (c != 0 && nl != 0)
		return (0);
	return (-1);
}

int	ft_errorfd(void)
{
	ft_putstr("error\n");
	exit(1);
}

int	ft_errormain(char *copy_of_file)
{
	ft_putstr("error\n");
	ft_strdel(&copy_of_file);
	exit(1);
}

int	*ft_small_map(char **tetrominos, int i, int x, int add)
{
	static int	square[4];

	if (i == 2)
		add = -2;
	if (i == 3)
		add = -1;
	square[0] = 0;
	square[1] = 1;
	square[2] = 5 + add;
	square[3] = 6 + add;
	i = 0;
	while (tetrominos[x][i] == '.' || tetrominos[x][i] == '\n')
		i++;
	if (tetrominos[x][i] == '2' && tetrominos[x][i + 1] == '2'
		&& tetrominos[x][i + 5] == '2' && tetrominos[x][i + 6] == '2')
		return (square);
	else
		return (ft_i(tetrominos, i, x, add));
}

int	*ft_t_2(char **tetrominos, int i, int x, int add)
{
	static int	vertical_t_left[4];
	static int	vertical_t_right[4];

	vertical_t_left[0] = 1;
	vertical_t_left[1] = 5 + add;
	vertical_t_left[2] = 6 + add;
	vertical_t_left[3] = 11 + add * 2;
	vertical_t_right[0] = 0;
	vertical_t_right[1] = 5 + add;
	vertical_t_right[2] = 6 + add;
	vertical_t_right[3] = 10 + add * 2;
	if (tetrominos[x][i] == '1' && tetrominos[x][i + 4] == '1'
		&& tetrominos[x][i + 5] == '3' && tetrominos[x][i + 10] == '1')
		return (vertical_t_left);
	else if (tetrominos[x][i] == '1' && tetrominos[x][i + 5] == '3'
		&& tetrominos[x][i + 6] == '1' && tetrominos[x][i + 10] == '1')
		return (vertical_t_right);
	else
		return (NULL);
}
