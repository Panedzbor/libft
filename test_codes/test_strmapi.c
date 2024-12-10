#include "libft.h"
#include <stdio.h>
#include "ft_strmapi.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
#include "ft_strlen.c"

char f(unsigned int i, char c);

int main()
{
    int c = 0;
    c++;
    {
        const char *s = "random text"; char *t = ft_strmapi(s, f);
        printf("Test %d (%s): %s\n", c, s, t);
        free (t);
    }
    c++;
    {
        const char *s = ""; char *t = ft_strmapi(s, f);
        printf("Test %d (%s): %s\n", c, s, t);
        free (t);
    }
    c++;
    {
        const char *s = "a"; char *t = ft_strmapi(s, f);
        printf("Test %d (%s): %s\n", c, s, t);
        free (t);
    }
    c++;
    {
        const char *s = "\0"; char *t = ft_strmapi(s, f);
        printf("Test %d (%s): %s\n", c, s, t);
        free (t);
    }
    c++;
    {
        const char *s = "\200"; char *t = ft_strmapi(s, f);
        printf("Test %d (%s): %s\n", c, s, t);
        free (t);
    }
    return (0);
}

char f(unsigned int i, char c)
{
    return ((char)(c + 1));
}