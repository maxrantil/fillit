/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:28:24 by mrantil           #+#    #+#             */
/*   Updated: 2021/11/06 21:11:40 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"  

int main(void) 
{  
	char str[] = "stackoverflow";
    char str1[] = "stackoverflow";
    char str2[] = "stackoverflow";
    char str3[] = "stackoverflow";

    //char dst[60] = "ABCDEFGHIJKLMNOP";
    //char dst1[60] = "ABCDEFGHIJKLMNOP";
    //char dst2[60] = "ABCDEFGHIJKLMNOP";
    //char dst3[60] = "ABCDEFGHIJKLMNOP";
    int y = 7;

    printf("        %s\n\n", str);

    memmove(str + 5, str, y);
    ft_memmove(str1 + 5, str1, y);
    memcpy(str2 + 5, str2, y);
    ft_memcpy(str3 + 5, str3, y);

    printf("memmove:		%s\n", str);
    printf("ft_memmove:		%s\n", str1);
    printf("\n");
    printf("memcpy:			%s\n", str2);
    printf("ft_memcpy:		%s\n", str3);
	printf("\n");

	struct person 			{

        int		age;
        char	name[12];

    }	man = { 34, "George" };
	
	struct person1			{

		int		age1;
		char	name1[12];

	}	man1 = { 34, "George" };


	void			*buffer;
	void			*buffer1;
	int				*bufint;
	int				*bufint1;
    unsigned char	*bufchar;
	unsigned char	*bufchar1;
    int				x;
	int				xx;

    struct person guy;
	struct person1 guy1;

    /* output the structure */
    printf("memcpy struct:				%s is %d years old\n",man.name, man.age);
	printf("ft_memcpy struct:			%s is %d years old\n",man1.name1, man1.age1);

	/* allocate the void buffer */
    buffer = malloc( sizeof(struct person) );
    if( buffer==NULL )
    {
        fprintf(stderr,"Unable to allocate memory\n");
        exit(1);
    }
	buffer1 = malloc( sizeof(struct person1) );
    if( buffer1==NULL )
    {
        fprintf(stderr,"Unable to allocate memory\n");
        exit(1);
	}

	/* copy memory */
	memmove(buffer, &man, sizeof(struct person));
	ft_memmove(buffer1, &man1, sizeof(struct person1));

    /* copy structure */
    guy = man;
	guy1 = man1;

    /* output the duplicate structure */
    printf("memcpy dup structure:			%s is %d years old\n",guy.name, guy.age);
	printf("ft_memcpy dup structure:		%s is %d years old\n",guy1.name1, guy1.age1);

	/* dump the buffer */
    puts("Buffer dump:");
        /* reference (void)buffer as (char)bufchar */
    bufchar = buffer;
    for( x=0; x<(int)sizeof(struct person); x++ )
    {
        printf(" %02X",*(bufchar+x));
    }
    putchar('\n');
	bufchar1 = buffer1;
    for( xx=0; xx<(int)sizeof(struct person1); xx++ )
	{
	printf(" %02X",*(bufchar1+xx));
	}
	putchar('\n');

	/* sneak into the buffer */
        /* reference (void)buffer as (int)bufint */
    bufint = (int *)buffer;
	bufint1 = (int *)buffer1;
        /* reference (void)buffer (offset 4) as (char)bufchar */
    bufchar = (unsigned char *)buffer+4;
	bufchar1 = (unsigned char *)buffer1+4;
        /* data can now be accessed directly */
    printf("Int portion:		%d\n",*(bufint));
	printf("Int portion(ft):	%d\n",*(bufint1));
	ft_putchar('\n');
    printf("String portion:		%s\n",bufchar);
	printf("String portion(ft):	%s\n",bufchar1);

    return(0);
}
