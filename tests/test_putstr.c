#include <stdio.h>
#include <unistd.h> // For write() and close()
#include "ft_putstr_fd.c"

int main()
{
    int fd;
    char *str;
    int c = 0;

    // Test 1: Normal string
    c++;
    fd = 1; str = "Hello, world!";
    printf("Test %d (%s/%d): ", c, str, fd);
    fflush(stdout);
    ft_putstr_fd(str, fd);
    printf(" | ");
    fflush(stdout);
    printf("%s", str); // Standard printf
    printf("\n");

    // Test 2: Empty string
    c++;
    fd = 1; str = "";
    printf("Test %d (empty/%d): ", c, fd);
    fflush(stdout);
    ft_putstr_fd(str, fd);
    printf(" | ");
    fflush(stdout);
    printf("(Expect nothing visible)\n");

    // Test 3: String with special characters
    c++;
    fd = 1; str = "Line1\nLine2\tTabbed";
    printf("Test %d (%s/%d): ", c, str, fd);
    fflush(stdout);
    ft_putstr_fd(str, fd);
    printf(" | ");
    fflush(stdout);
    printf("%s", str); // Standard printf
    printf(" (Special characters test)\n");

    // Test 4: String with NULL character inside
    c++;
    fd = 1; str = "Before\0After";
    printf("Test %d (string with NULL/%d): ", c, fd);
    fflush(stdout);
    ft_putstr_fd(str, fd); // Only "Before" will be printed
    printf(" | ");
    fflush(stdout);
    printf("Before (NULL test, expect no 'After')\n");

    return 0;
}
