/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:39:48 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/23 17:20:56 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputnbr(t_list **alst)
{
	t_list	*ptr;

	if (*alst == NULL)
		return ;
	ptr = *alst;
	write(1, "head:\n", 6);
	while (ptr != NULL)
	{
		ft_putnbr((int)ptr->content);
		write(1, "\n", 1);
		ptr = ptr->next;
	}
}
