#include "libft.h"
#include "ft_lstnew.c"
#include "ft_lstadd_front.c"
#include "ft_lstsize.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
#include "ft_strlen.c"
#include "ft_lstlast.c"
#include "ft_lstadd_back.c"

int main()
{
    int n = 10;
    t_list *node = ft_lstnew(&n);
    t_list **start;
    start = &node;
    printf("%d\n", *(int*)((*start)->content));
    char str[] = "string";
    t_list *node2 = ft_lstnew(str);   
    ft_lstadd_front(start, node2);
    printf("%s\n", (char*)((*start)->content));
    printf("%d\n", ft_lstsize(*start));
    t_list **end = ft_lstlast(*start);
    printf("%d\n", *(int*)((*end)->content));
    double d = 2.83;
    t_list *node3 = ft_lstnew(&d);
    ft_lstadd_back(start, node3);
    printf("%d\n", ft_lstsize(*start));
    end = ft_lstlast(*start);
    printf("%f\n", *(int*)((*end)->content));


    return 0;
}