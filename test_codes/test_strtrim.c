#include <stdio.h>
#include "libft.h"
#include "ft_strtrim.c"

int main()
{
    int c = 0;
    c++;
    {
        const char *s = "abrakadabra"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "tarakan"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "cabac"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "cyabac"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "yabac"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "bbcferro"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "aaaaaaa"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "c"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "$"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = ""; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "dog"; const char *set = ""; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = ""; const char *set = ""; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "AaAbBcC"; const char *set = "aAbB"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "AaAbBcC"; const char *set = "abc"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }
    c++;
    {
        const char *s = "!@#$%^&*()test!"; const char *set = "!@#$"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, p);
        free(p);
    }

    /* c++;
    {
        const char *s = "null"; const char *set = "null"; char *p = ft_strtrim(s, set);
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(NULL, NULL));
        free(p);
    } */
    
    return 0;
}