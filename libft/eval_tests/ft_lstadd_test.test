/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:21:24 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/19 15:10:00 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
 
int main(void)
{
	t_list *temp;

	temp = ft_lstnew("Test0\n", 6);
	ft_lstadd(&temp, temp);
	ft_lstadd(&temp, temp);
	ft_lstadd(&temp, temp);
	ft_lstadd(&temp, temp);
	ft_lstadd(&temp, temp);
 
	while (temp)
	{
		printf("%s", temp->content);
        temp = temp->next;
	}	
}
