#include "ft_substr.c"
#include <stdio.h>
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
#include "ft_strlen.c"

int main()
{
    {
        char st[] = "What the fuck"; int s = 9; size_t l = 5; char *sub;
        printf("Test 1 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 9; size_t l = 4; char *sub;
        printf("Test 2 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 9; size_t l = 3; char *sub;
        printf("Test 3 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 9; size_t l = 1; char *sub;
        printf("Test 4 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 9; size_t l = 0; char *sub;
        printf("Test 5 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 0; size_t l = 0; char *sub;
        printf("Test 6 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 0; size_t l = 7; char *sub;
        printf("Test 7 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 10; size_t l = 7; char *sub;
        printf("Test 8 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 13; size_t l = 5; char *sub;
        printf("Test 9 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 1; size_t l = 15; char *sub;
        printf("Test 10 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    /* {
        char st[] = "null"; int s = 1; size_t l = 15; char *sub;
        printf("Test 11 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(NULL, s, l));
        free(sub);
    } */ //null error
    {
        char st[] = "What the fuck"; int s = -1; size_t l = -2; char *sub;
        printf("Test 12 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = -1; size_t l = 2; char *sub;
        printf("Test 13 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "\\0"; int s = 0; size_t l = 1; char *sub;
        printf("Test 14 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr("\0", s, l));
        free(sub);
    }
    {
        char st[] = ""; int s = 0; size_t l = 5; char *sub;
        printf("Test 15 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "What the fuck"; int s = 20; size_t l = 5; char *sub;
        printf("Test 16 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "Hello\nWorld\t!"; int s = 6; size_t l = 6; char *sub;
        printf("Test 17 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    {
        char st[] = "Hello\nWorld\t!"; int s = 400; size_t l = 20; char *sub;
        printf("Test 18 (\"%s\" - %d - %zu): \"%s\"\n", st, s, l, sub = ft_substr(st, s, l));
        free(sub);
    }
    return 0;
}