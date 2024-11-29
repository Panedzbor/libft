#include "libft.h"
#include "ft_itoa.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
#include "ft_strlen.c"


int main()
{
    int c = 0;
    int i;
    c++; i = 42;
    printf("Test %d (%d): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = 4;
    printf("Test %d (%d): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = +4;
    printf("Test %d (%d - +4 manual): \"%s\"\n", c, i, ft_itoa(+4));
    c++; i = -1;
    printf("Test %d (%d - small negative): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = 0;
    printf("Test %d (%d): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = -0;
    printf("Test %d (%d (-0)): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = -0;
    printf("Test %d (%d (-0 manually)): \"%s\"\n", c, i, ft_itoa(-0));
    c++; i = +0;
    printf("Test %d (%d - +0 manual): \"%s\"\n", c, i, ft_itoa(+0));
    c++; i = -155;
    printf("Test %d (%d): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = -1234567;
    printf("Test %d (%d - large negative): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = -2147483647;
    printf("Test %d (%d - int min+1): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = 2147483646;
    printf("Test %d (%d - int max-1): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = 2147483647;
    printf("Test %d (%d - int max): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = -2147483648;
    printf("Test %d (%d - int min): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = -2147483649;
    printf("Test %d (%d - int min-1): \"%s\"\n", c, i, ft_itoa(i));
    c++; i = -2147483649;
    printf("Test %d (%d - int min-1 manual): \"%s\"\n", c, i, ft_itoa(-2147483649));
    c++; i = 2147483648;
    printf("Test %d (%d - int max+1 manual): \"%s\"\n", c, i, ft_itoa(2147483648));
    c++; i = 'a';
    printf("Test %d (%d - char 'a' manual): \"%s\"\n", c, i, ft_itoa('a'));

    return 0;
}