#include <stdio.h>
#include <fcntl.h>  // For open() and O_* flags
#include <unistd.h> // For write() and close()
#include "ft_putchar_fd.c"

int main()
{
    int fd;
    char ch;
    int c = 0;

    // Test 1: Basic ASCII character
    c++;
    fd = 1; ch = 'a';
    printf("Test %d (%c/%d): ", c, ch, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf("\n");

    // Test 2: Out-of-range ASCII value (300)
    c++;
    fd = 1; ch = 300;
    printf("Test %d (%c/%d): ", c, ch, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf("\n");

    // Test 3: NULL character ('\0')
    c++;
    fd = 1; ch = '\0';
    printf("Test %d (\\0/%d): ", c, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf(" (Expect nothing visible for \\0)\n");

    // Test 4: DEL character (127)
    c++;
    fd = 1; ch = 127;
    printf("Test %d (%c/%d): ", c, ch, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf(" (DEL character)\n");

    // Test 5: Non-printable character (newline '\n')
    c++;
    fd = 1; ch = '\n';
    printf("Test %d (\\n/%d): ", c, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf(" (Newline test)\n");

    // Test 6: Non-printable character (tab '\t')
    c++;
    fd = 1; ch = '\t';
    printf("Test %d (\\t/%d): ", c, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf(" (Tab character test)\n");

    // Test 7: Negative value
    c++;
    fd = 1; ch = -1;
    printf("Test %d (%c/%d): ", c, ch, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf(" (Negative value test, expect unexpected behavior)\n");

    // Test 8: Large value
    c++;
    fd = 1; ch = 5000;
    printf("Test %d (%c/%d): ", c, ch, fd);
    fflush(stdout);
    ft_putchar_fd(ch, fd);
    printf(" | ");
    fflush(stdout);
    putchar(ch);
    printf(" (Large value test, expect unexpected behavior)\n");

    return 0;
}
