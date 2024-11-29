#include "libft.h"
#include <stdio.h>
#include "ft_striteri.c"

void f(unsigned int i, char *c);

int main()
{
    int c = 0;
    c++;
    {
        char s[] = "random text"; char t[] = "random text"; ft_striteri(t, f);
        printf("Test %d (%s): %s\n", c, s, t);
    }
    c++;
    {
        char s[] = ""; char t[] = ""; ft_striteri(t, f);
        printf("Test %d (%s): %s\n", c, s, t);
    }
    c++;
    {
        char s[] = "a"; char t[] = "a"; ft_striteri(t, f);
        printf("Test %d (%s): %s\n", c, s, t);
    }
    c++;
    {
        char s[] = "\0"; char t[] = "\0"; ft_striteri(t, f);
        printf("Test %d (%s): %s\n", c, s, t);
    }
    c++;
    {
        char s[] = "\200"; char t[] = "\200"; ft_striteri(t, f);
        printf("Test %d (%s): %s\n", c, s, t);
    }
    return (0);
}

void f(unsigned int i, char *c)
{
    *c += 1;
}