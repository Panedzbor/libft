#include <stdio.h>
#include "ft_strjoin.c"

int main()
{
    int c = 0;
    c++;
    {
        const char s1[] = "Hello "; const char s2[] = "World!"; char *r;
        r = ft_strjoin(s1, s2);
        printf("Test %d (\"%s%s\"): \"%s\"\n", c, s1, s2, r);
        free(r);
    }
    c++;
    {
        const char s1[] = "Hello "; const char s2[] = ""; char *r;
        r = ft_strjoin(s1, s2);
        printf("Test %d (\"%s%s\"): \"%s\"\n", c, s1, s2, r);
        free(r);
    }
    c++;
    {
        const char s1[] = ""; const char s2[] = "World"; char *r;
        r = ft_strjoin(s1, s2);
        printf("Test %d (\"%s%s\"): \"%s\"\n", c, s1, s2, r);
        free(r);
    }
    c++;
    {
        const char s1[] = ""; const char s2[] = ""; char *r;
        r = ft_strjoin(s1, s2);
        printf("Test %d (\"%s%s\"): \"%s\"\n", c, s1, s2, r);
        free(r);
    }
    c++;
    {
        const char s1[] = "\0"; const char s2[] = "\0"; char *r;
        r = ft_strjoin(s1, s2);
        printf("Test %d (\"\\0\\0\"): \"%s\"\n", c, r);
        free(r);
    }
    /* c++;
    {
        const char s1[] = "null"; const char s2[] = "null"; char *r;
        r = ft_strjoin(NULL, NULL);
        printf("Test %d (\"%s%s\"): \"%s\"\n", c, s1, s2, r);
        free(r);
    } */ //null error
    c++;
    {
        const char s1[] = "Hello\n"; const char s2[] = "\tWorld!"; char *r;
        r = ft_strjoin(s1, s2);
        printf("Test %d (\"%s%s\"): \"%s\"\n", c, s1, s2, r);
        free(r);
    }
    c++;
    {
        const char s1[] = "This is a very long string. "; 
        const char s2[] = "Another very long string to join with the first one."; 
        char *r;
        r = ft_strjoin(s1, s2);
        printf("Test %d (Long strings): \"%s\"\n", c, r);
        free(r);
    }
    /* c++;
    {
        char s1[2147483647]; char s2[2147483647];
        for (unsigned long i = 0; i < 2147483647; i++)
        {
            s1[i] = 'a'; s2[i] = 'a';
        }
        char *r;
        r = ft_strjoin((const char *)s1, (const char *)s2);
        printf("Test %d (very long strings): \"%s\"\n", c, r);
        free(r);
    } */
   /*  c++;
    {
        char s1[2147483648]; char s2[2147483648];
        for (unsigned long i = 0; i < 2147483648; i++)
        {
            s1[i] = 'a'; s2[i] = 'a';
        }
        char *r;
        r = ft_strjoin((const char *)s1, (const char *)s2);
        printf("Test %d (very long strings): \"%s\"\n", c, r);
        free(r);
    } */

    return 0;
}