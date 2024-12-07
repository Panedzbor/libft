#include "libft.h"
#include "ft_putnbr_fd.c"
#include "ft_calloc.c"
#include "ft_bzero.c"
#include "ft_memset.c"
#include "ft_strlen.c"


int main()
{
    int c = 0;
    int i;
    int fd = 1;
    // Test cases
    c++; i = 42;
    printf("Test %d (%d): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    c++; i = 4;
    printf("Test %d (%d): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    c++; i = -1;
    printf("Test %d (%d - small negative): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    c++; i = 0;
    printf("Test %d (%d): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    c++; i = -155;
    printf("Test %d (%d): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    c++; i = -1234567;
    printf("Test %d (%d - large negative): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    c++; i = 2147483647;
    printf("Test %d (%d - int max): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    c++; i = -2147483648;
    printf("Test %d (%d - int min): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);

    // Character test (ASCII of 'a' is 97)
    c++; i = 'a';
    printf("Test %d (%d - char 'a'): ", c, i);
    fflush(stdout);
    ft_putnbr_fd(i, fd);
    write(1, "\n", 1);
    return 0;
}