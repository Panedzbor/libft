#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include "pch.h"
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include "ft_toupper.c"
#include "ft_tolower.c"

int main()
{
	printf("%d %d %d %d\n", isalpha('A'), isalpha('D'), isalpha('z'), isalpha('@'));
	printf("%d %d %d %d\n\n", ft_isalpha('A'), ft_isalpha('D'), ft_isalpha('z'), ft_isalpha('@'));
	printf("%d %d %d %d\n", isdigit('1'), isdigit('0'), isdigit('9'), isdigit('@'));
	printf("%d %d %d %d\n\n", ft_isdigit('1'), ft_isdigit('0'), ft_isdigit('9'), ft_isdigit('@'));
	printf("%d %d %d %d\n", isalnum('1'), isalnum('a'), isalnum('G'), isalnum('@'));
	printf("%d %d %d %d\n\n", ft_isalnum('1'), ft_isalnum('a'), ft_isalnum('G'), ft_isalnum('@'));
	printf("%d %d %d %d\n", isascii('@'), isascii('a'), isascii(130), isascii(13));
	printf("%d %d %d %d\n\n", ft_isascii('@'), ft_isascii('a'), ft_isascii(130), ft_isascii(13));
	printf("%d %d %d %d %d\n", isprint(' '), isprint('"'), isprint('4'), isprint('F'), isprint('n'));
	printf("%d %d %d %d %d\n\n", ft_isprint(' '), ft_isprint('"'), ft_isprint('4'), ft_isprint('F'), ft_isprint('n'));
	printf("%c %c %c %c %c\n", toupper(' '), toupper('"'), toupper('4'), toupper('F'), toupper('n'));
	printf("%c %c %c %c %c\n\n", ft_toupper(' '), ft_toupper('"'), ft_toupper('4'), ft_toupper('F'), ft_toupper('n'));
	printf("%c %c %c %c %c\n", tolower(' '), tolower('"'), tolower('4'), tolower('F'), tolower('n'));
	printf("%c %c %c %c %c\n\n", ft_tolower(' '), ft_tolower('"'), ft_tolower('4'), ft_tolower('F'), ft_tolower('n'));
	return 0;
}
