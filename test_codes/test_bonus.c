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
#include "ft_lstdelone.c"
#include "ft_lstclear.c"
#include "ft_lstiter.c"
#include "ft_lstmap.c"
#include <string.h>

void del(void *ptr)
{
    free(ptr);
}

void f(void *ptr)
{
    int *p1 = (int *)ptr;
    *p1 += 1;
}

void *fret(void *ptr)
{
    int *p = (int*)malloc(sizeof(int));
    if (p == NULL)
        return NULL;
    *p = *(int *)ptr;
    *p += 1;
    return ((void*)p);
}

void normal_del_cl(t_list **start, t_list **node, void (*del)(void*), int mode)
{
    t_list *curnd = *start;
    while (curnd && curnd->next != *node && curnd != *node)
        curnd = curnd->next;
    
    if (mode == 1)
    {
        if (curnd->next == *node)
            curnd->next = (*node)->next;
        if (curnd == *node)
            *start = (*node)->next;
        ft_lstdelone(*node, del);
    }
    else
    {
        if (curnd->next == *node)
            curnd->next = NULL;
        if (node == *start)
            *start = NULL;
        ft_lstclear(node, del);
    }
}

int main()
{
    int *np = (int*)malloc(sizeof(int));
    if (np == NULL)
        return 0;
    *np = 10;
    t_list *node = ft_lstnew(np); ///if -> free(del);
    t_list *start;
    start = node;
    printf("%d\n", *(int*)((start)->content));
    char *str = (char*)malloc(7 * sizeof(char));
    if (str == NULL)
        return 0;
    strcpy(str, "string");
    t_list *node2 = ft_lstnew(str);   
    ft_lstadd_front(&start, node2);
    printf("%s\n", (char*)((start)->content));
    printf("%d\n", ft_lstsize(start));
    t_list *end = ft_lstlast(start);
    printf("%d\n", *(int*)((end)->content));
    double *dp = (double*)malloc(sizeof(double));
    if (dp == NULL)
        return 0;
    *dp = 2.83;
    t_list *node3 = ft_lstnew(dp);
    ft_lstadd_back(&start, node3);
    printf("%d\n", ft_lstsize(start));
    end = ft_lstlast(start);
    printf("%f\n", *(double*)((end)->content));
    t_list *node4 = ft_lstnew(NULL);
    ft_lstadd_back(&start, node4);
    printf("%d\n", ft_lstsize(start));
    end = ft_lstlast(start);
    normal_del_cl(&start, &node3, del, 1);
    end = ft_lstlast(start);
    printf("%d\n", ft_lstsize(start));
    int *np2 = (int*)malloc(sizeof(int));
    if (np2 == NULL)
        return 0;
    *np2 = 10;
    t_list *node5 = ft_lstnew(np2);
    ft_lstadd_back(&start, node5);
    int *np3 = (int*)malloc(sizeof(int));
    if (np3 == NULL)
        return 0;
    *np3 = 10;
    t_list *node6 = ft_lstnew(np3);
    ft_lstadd_back(&start, node6);
    int *np4 = (int*)malloc(sizeof(int));
    if (np4 == NULL)
        return 0;
    *np4 = 10;
    t_list *node7 = ft_lstnew(np4);
    ft_lstadd_back(&start, node7);
    printf("%d\n", ft_lstsize(start));
    normal_del_cl(&start, &node4, del, 2);
    printf("%d\n", ft_lstsize(start));
    int *np5 = (int*)malloc(sizeof(int));
    if (np5 == NULL)
        return 0;
    *np5 = 10;
    t_list *node8 = ft_lstnew(np5);
    ft_lstadd_back(&start, node8);
    int *np6 = (int*)malloc(sizeof(int));
    if (np6 == NULL)
        return 0;
    *np6 = 10;
    t_list *node9 = ft_lstnew(np6);
    ft_lstadd_back(&start, node9);
    ft_lstiter(node, f);
    for (t_list *temp = node; temp; temp = temp->next)
    {
        printf("%d ", *(int*)temp->content);
    }
    printf("\n");
    normal_del_cl(&start, &node2, del, 1);
    printf("%d\n", ft_lstsize(start));
    t_list *newl = ft_lstmap(start, fret, del);
    for (; newl; newl = newl->next)
    {
        printf("%d ", *(int*)newl->content);
    }
    printf("\n%d\n", ft_lstsize(start));

    /* free(np); free(str); free(dp); */
    return 0;
}