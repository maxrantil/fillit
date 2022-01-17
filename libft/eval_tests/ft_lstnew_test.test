#include "libft.h"

void    print_list(t_list *list)
{
    while (list)
    {
        ft_putstr(list->content);
        ft_putchar('\n');
   //      ft_putnbr(*(int *)list->content);
   //      ft_putchar('\n');
        ft_putnbr(list->content_size);
        ft_putchar('\n');
        list = list->next;
    }
}

int    main(void)
{
    char    *str;
//     int        nbr;

    str = "We will rock you!";
//     nbr = 42;
    print_list(ft_lstnew(str, ft_strlen(str) + 1));
//     print_list(ft_lstnew(&nbr, sizeof(int)));
}
