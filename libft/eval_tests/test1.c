/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:01:00 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/26 16:46:00 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED(...) printf("\033[;31m" __VA_ARGS__)
#define GREEN(...) printf("\033[0;32m" __VA_ARGS__)
#define CYAN(...) printf("\033[0;36m" __VA_ARGS__)
#define RESET(...) printf("\033[0m" __VA_ARGS__)

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main()
{
	//ft_strlen

	if (ft_strlen("1234567890") == 10)
	{
		printf("ft_strlen	TEST "); 
		GREEN("OK\n");
		RESET();
	}
	else
	{
		RED("ft_strlen(1234567890) == 10\n");
		RESET();
	}
	ft_putchar('\n');

	//ft_isalpha

	int	ialpha = 89;
	int balpha = 124;
	while (ialpha != 91)
	{
		if (ft_isalpha(ialpha) == isalpha(ialpha))
		{
			printf("ft_isalpha	TEST ");
			GREEN("OK\n");
			RESET();
		}
		else
		{
			RED("ialpha != 91\n");
			RESET();
		}
		ialpha++;
	}
	while (balpha != 121)
	{
		if (ft_isalpha(balpha) == isalpha(balpha))
		{
			printf("ft_isalpha	TEST ");
			GREEN("OK\n");
			RESET();
		}
		else
		{
			RED("balpha != 121\n");
			RESET();
		}
        balpha--;
	}
	ft_putchar('\n');

	//ft_isdigit
	
	int aisdigit = 46;
	int	bisdigit = 59;

	while (aisdigit != 50)
	{
        if (ft_isdigit(aisdigit) == isdigit(aisdigit))
        {
            printf("ft_isdigit	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("aisdigit != 46\n");
            RESET();
        }
		aisdigit++;
	}
	while (bisdigit != 55)
	{
		if (ft_isdigit(bisdigit) == isdigit(bisdigit))
        {
            printf("ft_isdigit	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("bisdigit != 55\n");
            RESET();
        }
        bisdigit--;
	}
	ft_putchar('\n');

	//ft_isalnum
	
    int aisalnum = 45;
	int	bisalnum = 92;
	int	cisalnum = 95;
	int	disalnum = 124;

	while (aisalnum != 52)
	{
		if (ft_isalnum(aisalnum) == isalnum(aisalnum))
        {
            printf("ft_isalnum	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("bisalum != 52\n");
            RESET();
        }
		aisalnum++;
	}
	while (disalnum != 120)
	{
		if (ft_isalnum(aisalnum) == isalnum(aisalnum))
		{
            printf("ft_isalnum	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("bisalum != 120\n");
            RESET();
        }
        disalnum--;
	}
	while (cisalnum != 99)
    {
		if (ft_isalnum(aisalnum) == isalnum(aisalnum))
        {
            printf("ft_isalnum	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("bisalum != 99\n");
            RESET();
        }
        cisalnum++;
    }
    while (bisalnum != 88)
    {
		if (ft_isalnum(aisalnum) == isalnum(aisalnum))
        {
            printf("ft_isalnum	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("bisalum != 88\n");
            RESET();
        }
        bisalnum--;
    }
	ft_putchar('\n');
	
	//ft_isascii
	
	int aisascii = 1510;    
	int bisascii = 5;

	if (isascii(aisascii) == ft_isascii(aisascii))
	{
            printf("ft_isascii	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("aisascii != 1510\n");
            RESET();
        }
	if (isascii(bisascii) == ft_isascii(bisascii))
	{
            printf("ft_isascii	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("bisascii != 5\n");
            RESET();
        }
	ft_putchar('\n');

	//ft_isprint
	
	int aisprint = 110;
	int bisprint = 5;

	if (isprint(aisprint) == ft_isprint(aisprint))
	{
            printf("ft_isprint	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("aisprint != 110\n");
            RESET();
        }
	if (isprint(bisprint) == ft_isprint(bisprint))
	{
            printf("ft_isprint	TEST ");
            GREEN("OK\n");
            RESET();
        }
        else
        {
            RED("bisprint != 5\n");
            RESET();
        }


	return (0);
}
