#include "libft.h"
#include <string.h>
#include "ft_strncmp.c"

int main()
{
        //char *s1 = "abcd";
        //char *s2 = "abcy";
        //size_t n = 5;
    printf("abcd - abcy (4): %d | %d\n", 
	ft_strncmp("abcd", "abcy", 4), strncmp("abcd", "abcy", 4));
    printf("abcd - abcy (3): %d | %d\n", 
	ft_strncmp("abcd", "abcy", 3), strncmp("abcd", "abcy", 3));
	printf("abcd - abcy (5): %d | %d\n", 
	ft_strncmp("abcd", "abcy", 5), strncmp("abcd", "abcy", 5));
	printf("abcd - abcd (4): %d | %d\n", 
	ft_strncmp("abcd", "abcd", 4), strncmp("abcd", "abcd", 4));
	printf("a - a (1): %d | %d\n", 
	ft_strncmp("a", "a", 1), strncmp("a", "a", 1));
	printf("zex - rex (3): %d | %d\n", 
	ft_strncmp("zex", "rex", 3), strncmp("zex", "rex", 3));
	printf("tour - tourin (6): %d | %d\n", 
	ft_strncmp("tour", "tourin", 6), strncmp("tour", "tourin", 6));
	printf("tour - tourin (5): %d | %d\n", 
	ft_strncmp("tour", "tourin", 5), strncmp("tour", "tourin", 5));
	printf("a - a (0): %d | %d\n", 
	ft_strncmp("a", "a", 0), strncmp("a", "a", 0));
	printf("a - a (-1): %d | %d\n", 
	ft_strncmp("a", "a", -1), strncmp("a", "a", -1));
	printf(" - a (1): %d | %d\n", 
	ft_strncmp("", "a", 1), strncmp("", "a", 1));	
	printf("null null (1): %d | %d\n", 
	ft_strncmp(NULL, NULL, 1), strncmp(NULL, NULL, 1));	
    printf("test\\200 - test\\0 (6): %d | %d\n", 
	ft_strncmp("test\200", "test\0", 6), strncmp("test\200", "test\0", 6));
        return 0;
}
