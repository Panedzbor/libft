#include <stdio.h>
#include <stdlib.h>
#include "ft_atoi.c"
int main(void)
{
    //char* str = "	 \t \v \f \r   \n---+--+1234ab567";
 
 printf("0: %d | %d\n", ft_atoi("0"), atoi("0"));
 printf("00: %d | %d\n", ft_atoi("00"), atoi("00"));
 printf("001: %d | %d\n", ft_atoi("001"), atoi("001"));
 printf("002: %d | %d\n", ft_atoi("002"), atoi("002"));
 printf("010: %d | %d\n", ft_atoi("010"), atoi("010"));
 printf("000001: %d | %d\n", ft_atoi("000001"), atoi("000001"));
 printf("1: %d | %d\n", ft_atoi("1"), atoi("1"));
 printf("-3: %d | %d\n", ft_atoi("-3"), atoi("-3"));
 printf("50: %d | %d\n", ft_atoi("50"), atoi("50"));
 printf("2147483647: %d | %d\n", ft_atoi("2147483647"), atoi("2147483647"));
 printf("-2147483648: %d | %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
 printf("2147483648: %d | %d\n", ft_atoi("2147483648"), atoi("2147483648"));
 printf("2147483647000: %d | %d\n", ft_atoi("2147483647000"),
 atoi("2147483647000"));
 printf("2147483647000000: %d | %d\n", ft_atoi("2147483647000000"),
 atoi("2147483647000000"));
 printf("abc: %d | %d\n", ft_atoi("abc"), atoi("abc"));
 printf("52ab: %d | %d\n", ft_atoi("52ab"), atoi("52ab"));
 printf("ab43: %d | %d\n", ft_atoi("ab43"), atoi("ab43"));
 printf("ab43qw: %d | %d\n", ft_atoi("ab43qw"), atoi("ab43qw"));
 printf("	 \t \v \f \r   \n---+--+1234ab567: %d | %d\n",
 ft_atoi("	 \t \v \f \r   \n---+--+1234ab567"),
 atoi("	 \t \v \f \r   \n---+--+1234ab567"));
 printf("----23: %d | %d\n", ft_atoi("----23"), atoi("----23"));
 printf("----ab23: %d | %d\n", ft_atoi("----ab23"), atoi("----ab23"));
 printf("----ab23ab: %d | %d\n", ft_atoi("----ab23ab"), atoi("----ab23ab"));
 printf("-: %d | %d\n", ft_atoi("-"), atoi("-"));
 printf("+1: %d | %d\n", ft_atoi("+1"), atoi("+1"));
 printf("++1: %d | %d\n", ft_atoi("++1"), atoi("++1"));
 printf("--1: %d | %d\n", ft_atoi("--1"), atoi("--1"));
 printf("a: %d | %d\n", ft_atoi("a"), atoi("a"));
 printf("space: %d | %d\n", ft_atoi(" "), atoi(" "));
 printf(" 12: %d | %d\n", ft_atoi(" 12"), atoi(" 12"));
 printf("  12: %d | %d\n", ft_atoi("  12"), atoi("  12"));
 printf("    -12: %d | %d\n", ft_atoi("    -12"), atoi("    -12"));
 printf("-    12: %d | %d\n", ft_atoi("-    12"), atoi("-    12"));
 printf(" -    12: %d | %d\n", ft_atoi(" -    12"), atoi(" -    12"));
 printf("    +12: %d | %d\n", ft_atoi("    +12"), atoi("    +12"));
 printf("    +12a: %d | %d\n", ft_atoi("    +12a"), atoi("    +12a"));
 printf("    +12 : %d | %d\n", ft_atoi("    +12 "), atoi("    +12 "));
 printf("    +0012 : %d | %d\n", ft_atoi("    +0012 "), atoi("    +0012 "));
 //printf("null: %d | %d\n", ft_atoi(NULL), atoi(NULL)); //- should give null error
 return 0;
}
