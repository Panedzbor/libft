#include "../libft/libft.h"
#include "../libft/ft_lstnew.c"
#include "../libft/ft_lstadd_front.c"
#include "../libft/ft_lstsize.c"
#include "../libft/ft_calloc.c"
#include "../libft/ft_bzero.c"
#include "../libft/ft_memset.c"
#include "../libft/ft_strlen.c"
#include "../libft/ft_lstlast.c"
#include "../libft/ft_lstadd_back.c"
#include "../libft/ft_lstdelone.c"
#include "../libft/ft_lstclear.c"
#include "../libft/ft_lstiter.c"
#include "../libft/ft_lstmap.c"
#include <string.h>
#include <stdio.h>

void del(void *ptr)
{
    free(ptr);
}

void fb(void *ptr)
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
    printf("Test 1: Trying to create a node with ft_lstnew...");
    fflush(stdout);
    t_list *node = ft_lstnew(np);
    if (node == NULL)
    {
        free(np);
        //pass = false;
        printf(" - FAIL\n");
        return 0;
    }
    //compare_results("", np, node->content, 1, ++test, &pass, 1, 0);
    t_list *start;
    start = node;
    //printf("%d\n", *(int*)((start)->content));
    char *str = (char*)malloc(7 * sizeof(char));
    if (str == NULL)
    {
        free(np);
        free(node);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return 0;
    }
    strcpy(str, "string");
    printf("Test 2: Trying to create node #2 with ft_lstnew...");
    t_list *node2 = ft_lstnew(str);
    if (node2 == NULL)
    {
        free(np);
        free(node);
        free(str);
        //pass = false;
        printf(" - FAIL\n");
        return 0;
    }
    //compare_results("", str, node2->content, 2, ++test, &pass, 1, 0);  
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
    t_list *check;
    check = node3;
    double check2 = *(double*)node3->content;
    ft_lstadd_back(&start, node3);
    printf("%d\n", ft_lstsize(start));
    end = ft_lstlast(start);
    printf("%f\n", *(double*)((end)->content));
    t_list *node4 = ft_lstnew(NULL);
    ft_lstadd_back(&start, node4);
    printf("%d\n", ft_lstsize(start));
    end = ft_lstlast(start);
    void *check1 = node3->content;
    normal_del_cl(&start, &node3, del, 1);
    if (check1 != node3->content)
        printf("good\n");
    end = ft_lstlast(start);
    printf("%d\n", ft_lstsize(start));
    int *np2 = (int*)malloc(sizeof(int));
    if (np2 == NULL)
        return 0;
    *np2 = 12;
    t_list *node5 = ft_lstnew(np2);
    ft_lstadd_back(&start, node5);
    int *np3 = (int*)malloc(sizeof(int));
    if (np3 == NULL)
        return 0;
    *np3 = 13;
    t_list *node6 = ft_lstnew(np3);
    ft_lstadd_back(&start, node6);
    int *np4 = (int*)malloc(sizeof(int));
    if (np4 == NULL)
        return 0;
    *np4 = 14;
    t_list *node7 = ft_lstnew(np4);
    ft_lstadd_back(&start, node7);
    printf("%d\n", ft_lstsize(start));
    check = node4;
    normal_del_cl(&start, &node4, del, 2);
    printf("%d\n", ft_lstsize(start));
    int *np5 = (int*)malloc(sizeof(int));
    if (np5 == NULL)
        return 0;
    *np5 = 15;
    t_list *node8 = ft_lstnew(np5);
    ft_lstadd_back(&start, node8);
    int *np6 = (int*)malloc(sizeof(int));
    if (np6 == NULL)
        return 0;
    *np6 = 16;
    t_list *node9 = ft_lstnew(np6);
    ft_lstadd_back(&start, node9);
    ft_lstiter(node, fb);
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