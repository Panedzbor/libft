#include <string.h>
#include <stdio.h>
#include "ft_memcmp.c"

int main()
{
        //char *s1 = "abcd";
        //char *s2 = "abcy";
        //size_t n = 5;
    printf("abcd - abcy (4): %d | %d\n", 
	ft_memcmp("abcd", "abcy", 4), memcmp("abcd", "abcy", 4));
    printf("abcd - abcy (3): %d | %d\n", 
	ft_memcmp("abcd", "abcy", 3), memcmp("abcd", "abcy", 3));
	printf("abcd - abcy (5): %d | %d\n", 
	ft_memcmp("abcd", "abcy", 5), memcmp("abcd", "abcy", 5));
    printf("abcd - abcy (6): %d | %d\n", 
	ft_memcmp("abcd", "abcy", 6), memcmp("abcd", "abcy", 6));
    printf("abcd - abcy (8): %d | %d\n", 
	ft_memcmp("abcd", "abcy", 8), memcmp("abcd", "abcy", 8));
    char a[8]={'a', 'b', 'c', 'd'};char a2[8]={'a', 'b', 'c', 'y'};
    printf("abcd - abcy [but being arrays of 8] (4): %d | %d\n", 
	ft_memcmp(a, a2, 4), memcmp(a, a2, 4)); //it gives the difference randomly but fuck it
	printf("abcd - abcd (4): %d | %d\n", 
	ft_memcmp("abcd", "abcd", 4), memcmp("abcd", "abcd", 4));
    printf("abcd - abcd (6): %d | %d\n", 
	ft_memcmp("abcd", "abcd", 6), memcmp("abcd", "abcd", 6));
	printf("a - a (1): %d | %d\n", 
	ft_memcmp("a", "a", 1), memcmp("a", "a", 1));
	printf("zex - rex (3): %d | %d\n", 
	ft_memcmp("zex", "rex", 3), memcmp("zex", "rex", 3));
	printf("tour - tourin (6): %d | %d\n", 
	ft_memcmp("tour", "tourin", 6), memcmp("tour", "tourin", 6));
	printf("tour - tourin (5): %d | %d\n", 
	ft_memcmp("tour", "tourin", 5), memcmp("tour", "tourin", 5));
	printf("a - a (0): %d | %d\n", 
	ft_memcmp("a", "a", 0), memcmp("a", "a", 0));
	/*printf("a - a (-1): %d | %d\n",
	ft_memcmp("a", "a", -1), memcmp("a", "a", -1));  //segfault */
	printf(" - a (1): %d | %d\n",
	ft_memcmp("", "a", 1), memcmp("", "a", 1));
    printf("a -  (1): %d | %d\n",
	ft_memcmp("a", "", 1), memcmp("a", "", 1));
    printf("a -  (2): %d | %d\n",
	ft_memcmp("a", "", 2), memcmp("a", "", 2));
	/*printf("null null (1): %d | %d\n", 
	ft_memcmp(NULL, NULL, 1), memcmp(NULL, NULL, 1));*/ //should give null error
        return 0;
}