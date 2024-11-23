#include <stdio.h>
#include "libft.h"
#include "ft_strtrim.c"

int main()
{
    int c = 0;
    c++;
    {
        const char *s = "abrakadabra"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "tarakan"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "cabac"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "cyabac"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "yabac"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "bbcferro"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "aaaaaaa"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "c"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "$"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = ""; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "dog"; const char *set = "";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = ""; const char *set = "";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "AaAbBcC"; const char *set = "aAbB";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "AaAbBcC"; const char *set = "abc";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }
    c++;
    {
        const char *s = "!@#$%^&*()test!"; const char *set = "!@#$";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(s, set));
    }

    /* c++;
    {
        const char *s = "null"; const char *set = "null";
        printf("Test %d (\"%s\"/\"%s\"): \"%s\"\n", c, s, set, ft_strtrim(NULL, NULL));
    } */
    
    return 0;
}