#include <stdio.h>
#include <string.h>
#include "ft_memchr.c"

int main()
{
    char c = 'a';

    printf("abcd (4): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abcd", c, 4), (char *)(char *)memchr("abcd", c, 4));
    printf("abcd (5): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abcd", c, 5), (char *)memchr("abcd", c, 5));
    printf("abcd (6): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abcd", c, 6), (char *)memchr("abcd", c, 6));
    printf("abcd (3): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abcd", c, 3), (char *)memchr("abcd", c, 3));
    printf("abcd (1): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abcd", c, 1), (char *)memchr("abcd", c, 1));
    //printf("abcd (0): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abcd", c, 0), (char *)memchr("abcd", c, 0)); //argument is 0 error
    //printf("abcd (0): result \"%s\"\n", (char *)ft_memchr("abcd", c, 0)); //my function accepts this but I can't do anything with it
    //printf("null (1): result \"%s\" | \"%s\"\n", (char *)ft_memchr(NULL, c, 1), (char *)memchr(NULL, c, 1)); //should give null error
    printf("bcd (3): result \"%s\" | \"%s\"\n", (char *)ft_memchr("bcd", c, 3), (char *)memchr("bcd", c, 3));
    printf("bcda (4): result \"%s\" | \"%s\"\n", (char *)ft_memchr("bcda", c, 4), (char *)memchr("bcda", c, 4));
    printf("a (1): result \"%s\" | \"%s\"\n", (char *)ft_memchr("a", c, 1), (char *)memchr("a", c, 1));
    printf("\"\" (1): result \"%s\" | \"%s\"\n", (char *)ft_memchr("", c, 1), (char *)memchr("", c, 1));
    printf("abacd (5): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abacd", c, 5), (char *)memchr("abacd", c, 5));
    printf("abacda (6): result \"%s\" | \"%s\"\n", (char *)ft_memchr("abacda", c, 6), (char *)memchr("abacda", c, 6));
    printf("zero sign: result \"%s\" | \"%s\"\n", (char *)ft_memchr("abacda", '\0', 7), (char *)memchr("abacda", '\0', 7));
    printf("zero sign in empty: result \"%s\" | \"%s\"\n", (char *)ft_memchr("", '\0', 1), (char *)memchr("", '\0', 1));
    printf("aaaaa (5): result \"%s\" | \"%s\"\n", (char *)ft_memchr("aaaaa", c, 5), (char *)memchr("aaaaa", c, 5));
    printf("longer string of characters: result \"%s\" | \"%s\"\n", (char *)ft_memchr("longer string of characters", c, 27), (char *)memchr("longer string of characters", c, 27));
    

    return 0;
}