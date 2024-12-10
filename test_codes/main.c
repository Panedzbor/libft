#include "../libft/libft.h"
# include <stdio.h>
# include <ctype.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <setjmp.h>
# include <bsd/string.h>

#include "../libft/ft_isprint.c"
#include "../libft/ft_toupper.c"
#include "../libft/ft_tolower.c"
#include "../libft/ft_strrchr.c"
#include "../libft/ft_memset.c"
#include "../libft/ft_putchar_fd.c"
#include "../libft/ft_putendl_fd.c"
#include "../libft/ft_putnbr_fd.c"
#include "../libft/ft_putstr_fd.c"
#include "../libft/ft_split.c"
#include "../libft/ft_strchr.c"
#include "../libft/ft_strdup.c"
#include "../libft/ft_striteri.c"
#include "../libft/ft_strjoin.c"
#include "../libft/ft_calloc.c"
#include "../libft/ft_strlen.c"
#include "../libft/ft_isalpha.c"
#include "../libft/ft_isdigit.c"
#include "../libft/ft_isalnum.c"
#include "../libft/ft_isascii.c"
#include "../libft/ft_bzero.c"





// Function prototypes
void run_test_is(bool *grandpass);
void run_test_strlen(bool *grandpass);
void run_test_strchr(bool *grandpass);
void run_test_strrchr(bool *grandpass);
void run_test_memset();
void run_test_putchar();
void run_test_putendl();
void run_test_putnbr();
void run_test_putstr();
void run_test_split();
void run_test_strchrs();
void run_test_strdup();
void run_test_striteri();
void run_test_strjoin();
void run_test_strlcat();
void run_test_strlcpy();
void run_test_strmapi();
void run_test_strncmp();
void run_test_strnstr();
void run_test_strtrim();
void run_test_substr();

jmp_buf buf; 
void signal_handler(int sig) 
{ 
    printf("Error: Caught signal %d (%s)\n", sig, strsignal(sig)); 
    longjmp(buf, 1);
}

int main() {
    bool grandpass = true;
    signal(SIGSEGV, signal_handler);
    
    run_test_is(&grandpass);
    run_test_strlen(&grandpass);
    run_test_strchr(&grandpass);
    run_test_strrchr(&grandpass);
/*     run_test_memset();
    run_test_putchar();
    run_test_putendl();
    run_test_putnbr();
    run_test_putstr();
    run_test_split();
    run_test_strchrs();
    run_test_strdup();
    run_test_striteri();
    run_test_strjoin();
    run_test_strlcat();
    run_test_strlcpy();
    run_test_strmapi();
    run_test_strncmp();
    run_test_strnstr();
    run_test_strtrim();
    run_test_substr(); */
    return 0;
}

void compare_results(const char* func_name, void *std_result, void *custom_result, int mode, int test, bool *pass, int datatype) {
    /* int a = *(int*)std_result;
    int b = *(int*)custom_result; */
    
    if (mode == 1)
    {
        if (datatype == 1)
        {
            if (*(int *)std_result == *(int *)custom_result) {
                printf("Test %d: %14s %4d || %d - PASS\n", test, func_name, *(int *)std_result, *(int *)custom_result);
            } else {
                printf("Test %d: %14s %4d || %d - FAIL\n", test, func_name, *(int *)std_result, *(int *)custom_result);
                *pass = false;
            }
        }
        else
        {
            if (std_result && custom_result)
            {
                if (strcmp((const char *)std_result, (const char *)custom_result) == 0)
                {
                    printf("Test %d: %14s %4s || %s - PASS\n", test, func_name, (char *)std_result, (char *)custom_result);
                }
                else
                {
                    printf("Test %d: %14s %4s || %s - FAIL\n", test, func_name, (char *)std_result, (char *)custom_result);
                    *pass = false;   
                }
            }
            else if (!(std_result && custom_result))
            {
                printf("Test %d: %14s %4s || %s - PASS\n", test, func_name, (char *)std_result, (char *)custom_result);
            }
            else{
                printf("Test %d: %14s %4s || %s - FAIL\n", test, func_name, (char *)std_result, (char *)custom_result);
                *pass = false;   
            }
        }
    }
    else
    {
        if ((*(int *)std_result > 0 && *(int *)custom_result > 0) || (*(int *)std_result == 0 && *(int *)custom_result == 0) || (*(int *)std_result < 0 && *(int *)custom_result < 0)) {
            printf("Test %d: %14s %4d || %d - PASS\n", test, func_name, *(int *)std_result, *(int *)custom_result);
        } else {
            printf("Test %d: %14s %4d || %d - FAIL\n", test, func_name, *(int *)std_result, *(int *)custom_result);
            *pass = false;
        }
    }
}

void run_test_is(bool *grandpass) {
    bool pass = true;
    int test = 0;
    int resulta, resultb;
    printf("Running test_is...\n");

    // isalpha function comparison
    printf("isalpha vs ft_isalpha:\n");
    resulta = isalpha('A'); resultb = ft_isalpha('A');
    compare_results("isalpha('A')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalpha('D'); resultb = ft_isalpha('D');
    compare_results("isalpha('D')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalpha('z'); resultb = ft_isalpha('z');
    compare_results("isalpha('z')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalpha('@'); resultb = ft_isalpha('@');
    compare_results("isalpha('@')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalpha(':'); resultb = ft_isalpha(':');
    compare_results("isalpha(':')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalpha(58); resultb = ft_isalpha(58);
    compare_results("isalpha(58)", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalpha(-1); resultb = ft_isalpha(-1);
    compare_results("isalpha(-1)", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalpha(580); resultb = ft_isalpha(580);
    compare_results("isalpha(580)", &resulta, &resultb, 2, ++test, &pass, 1);
    printf("Total grade: ");
    if (pass == true)
        printf("PASS\n");
    else {
        printf("FAIL\n");
        pass = true;
        *grandpass = false;
    }

    test = 0;
    // isdigit function comparison
    printf("\nisdigit vs ft_isdigit:\n");
    resulta = isdigit('1'); resultb = ft_isdigit('1');
    compare_results("isdigit('1')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isdigit('0'); resultb = ft_isdigit('0');
    compare_results("isdigit('0')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isdigit('9'); resultb = ft_isdigit('9');
    compare_results("isdigit('9')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isdigit('@'); resultb = ft_isdigit('@');
    compare_results("isdigit('@')", &resulta, &resultb, 2, ++test, &pass, 1);
    printf("Total grade: ");
    if (pass == true)
        printf("PASS\n");
    else {
        printf("FAIL\n");
        pass = true;
        *grandpass = false;
    }

    test = 0;
    // isalnum function comparison
    printf("\nisalnum vs ft_isalnum:\n");
    resulta = isalnum('1'); resultb = ft_isalnum('1');
    compare_results("isalnum('1')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalnum('a'); resultb = ft_isalnum('a');
    compare_results("isalnum('a')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalnum('G'); resultb = ft_isalnum('G');
    compare_results("isalnum('G')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isalnum('@'); resultb = ft_isalnum('@');
    compare_results("isalnum('@')", &resulta, &resultb, 2, ++test, &pass, 1);
    printf("Total grade: ");
    if (pass == true)
        printf("PASS\n");
    else {
        printf("FAIL\n");
        pass = true;
        *grandpass = false;
    }

    test = 0;
    // isascii function comparison
    printf("\nisascii vs ft_isascii:\n");
    resulta = isascii('@'); resultb = ft_isascii('@');
    compare_results("isascii('@')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isascii('a'); resultb = ft_isascii('a');
    compare_results("isascii('a')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isascii(130); resultb = ft_isascii(130);
    compare_results("isascii(130)", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isascii(13); resultb = ft_isascii(13);
    compare_results("isascii(13)", &resulta, &resultb, 2, ++test, &pass, 1);
    printf("Total grade: ");
    if (pass == true)
        printf("PASS\n");
    else {
        printf("FAIL\n");
        pass = true;
        *grandpass = false;
    }

    test = 0;
    // isprint function comparison
    printf("\nisprint vs ft_isprint:\n");
    resulta = isprint(' '); resultb = ft_isprint(' ');
    compare_results("isprint(' ')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isprint('"'); resultb = ft_isprint('"');
    compare_results("isprint('\"')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isprint('4'); resultb = ft_isprint('4');
    compare_results("isprint('4')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isprint('F'); resultb = ft_isprint('F');
    compare_results("isprint('F')", &resulta, &resultb, 2, ++test, &pass, 1);
    resulta = isprint('n'); resultb = ft_isprint('n');
    compare_results("isprint('n')", &resulta, &resultb, 2, ++test, &pass, 1);
    printf("Total grade: ");
    if (pass == true)
        printf("PASS\n");
    else {
        printf("FAIL\n");
        pass = true;
        *grandpass = false;
    }

    test = 0;
    // toupper function comparison
    printf("\ntoupper vs ft_toupper:\n");
    resulta = toupper(' '); resultb = ft_toupper(' ');
    compare_results("toupper(' ')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = toupper('"'); resultb = ft_toupper('"');
    compare_results("toupper('\"')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = toupper('4'); resultb = ft_toupper('4');
    compare_results("toupper('4')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = toupper('F'); resultb = ft_toupper('F');
    compare_results("toupper('F')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = toupper('n'); resultb = ft_toupper('n');
    compare_results("toupper('n')", &resulta, &resultb, 1, ++test, &pass, 1);
    printf("Total grade: ");
    if (pass == true)
        printf("PASS\n");
    else {
        printf("FAIL\n");
        pass = true;
        *grandpass = false;
    }

    test = 0;
    // tolower function comparison
    printf("\ntolower vs ft_tolower:\n");
    resulta = tolower(' '); resultb = ft_tolower(' ');
    compare_results("tolower(' ')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = tolower('"'); resultb = ft_tolower('"');
    compare_results("tolower('\"')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = tolower('4'); resultb = ft_tolower('4');
    compare_results("tolower('4')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = tolower('F'); resultb = ft_tolower('F');
    compare_results("tolower('F')", &resulta, &resultb, 1, ++test, &pass, 1);
    resulta = tolower('n'); resultb = ft_tolower('n');
    compare_results("tolower('n')", &resulta, &resultb, 1, ++test, &pass, 1);

    // Final grade check
    printf("Total grade: ");
    if (pass == true)
        printf("PASS\n");
    else {
        printf("FAIL\n");
        pass = true;
        *grandpass = false;
    }

    printf("\nFinished test_is...\n");
    printf("Overall grade: ");
    if (*grandpass == true)
        printf("PASS\n");
    else
        printf("FAIL\n");
}


void run_test_strlen(bool *grandpass) {
    bool pass = true;
    int test = 0;
    int resulta, resultb;
    printf("\nRunning test_strlen...\n");

    // strlen function comparison
    printf("strlen vs ft_strlen:\n");

    if (setjmp(buf) == 0) {
        resulta = strlen("Text"); resultb = ft_strlen("Text");
        compare_results("strlen('Text')", &resulta, &resultb, 1, ++test, &pass, 1);
    } else {
        printf("Test %d: %14s - Segmentation Fault\n", ++test, "strlen('Text')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strlen("a"); resultb = ft_strlen("a");
        compare_results("strlen('a')", &resulta, &resultb, 1, ++test, &pass, 1);
    } else {
        printf("Test %d: %14s - Segmentation Fault\n", ++test, "strlen('a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strlen(""); resultb = ft_strlen("");
        compare_results("strlen('')", &resulta, &resultb, 1, ++test, &pass, 1);
    } else {
        printf("Test %d: %14s - Segmentation Fault\n", ++test, "strlen('')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strlen("\0"); resultb = ft_strlen("\0");
        compare_results("strlen('\\0')", &resulta, &resultb, 1, ++test, &pass, 1);
    } else {
        printf("Test %d: %14s - Segmentation Fault\n", ++test, "strlen('\\0')");
        pass = false;
    }

    // Handling segfault for NULL input
    if (setjmp(buf) == 0) {
        resulta = 1; resultb = ft_strlen(NULL);
        compare_results("strlen(NULL)", &resulta, &resultb, 2, ++test, &pass, 1);
        pass = false;
    } else {
        printf("Test %d: %14s - Segmentation Fault - PASS\n", ++test, "strlen(NULL)");
    }

    printf("Total grade: ");
    if (pass == true) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        *grandpass = false;
    }

    printf("\nFinished test_strlen...\n");
    printf("Overall grade: ");
    if (*grandpass == true) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}


void run_test_strchr(bool *grandpass) {
    bool pass = true;
    int test = 0;
    char c = 'a';
    char *resulta, *resultb;
    printf("\nRunning test_strchr...\n");

    // strchr function comparison
    printf("strchr vs ft_strchr:\n");

    if (setjmp(buf) == 0) {
        resulta = strchr("abcd", c); resultb = ft_strchr("abcd", c);
        compare_results("strchr('abcd', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('abcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("bcd", c); resultb = ft_strchr("bcd", c);
        compare_results("strchr('bcd', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('bcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("bcda", c); resultb = ft_strchr("bcda", c);
        compare_results("strchr('bcda', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('bcda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("a", c); resultb = ft_strchr("a", c);
        compare_results("strchr('a', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('a', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("", c); resultb = ft_strchr("", c);
        compare_results("strchr('', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("abacd", c); resultb = ft_strchr("abacd", c);
        compare_results("strchr('abacd', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('abacd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("abacda", c); resultb = ft_strchr("abacda", c);
        compare_results("strchr('abacda', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('abacda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("abacda", '\0'); resultb = ft_strchr("abacda", '\0');
        compare_results("strchr('abacda', '\\0')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('abacda', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("", '\0'); resultb = ft_strchr("", '\0');
        compare_results("strchr('', '\\0')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("aaaaa", c); resultb = ft_strchr("aaaaa", c);
        compare_results("strchr('aaaaa', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('aaaaa', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("longer string of characters", c); resultb = ft_strchr("longer string of characters", c);
        compare_results("strchr('longer string of characters', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('longer string of characters', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("char overflow", 't' + 256); resultb = ft_strchr("char overflow", 't' + 256);
        compare_results("strchr('char overflow', 't' + 256)", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('char overflow', 't' + 256)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("char overflow", 't' + 258); resultb = ft_strchr("char overflow", 't' + 258);
        compare_results("strchr('char overflow', 't' + 258)", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strchr('char overflow', 't' + 258)");
        pass = false;
    }

    printf("Total grade: ");
    if (pass == true) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        *grandpass = false;
    }

    printf("\nFinished test_strchr...\n");
    printf("Overall grade: ");
    if (*grandpass == true) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}

void run_test_strrchr(bool *grandpass) {
    bool pass = true;
    int test = 0;
    char c = 'a';
    char *resulta, *resultb;
    printf("\nRunning test_strrchr...\n");

    // strrchr function comparison
    printf("strrchr vs ft_strrchr:\n");

    if (setjmp(buf) == 0) {
        resulta = strrchr("abcd", c); resultb = ft_strrchr("abcd", c);
        compare_results("strrchr('abcd', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('abcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("bcd", c); resultb = ft_strrchr("bcd", c);
        compare_results("strrchr('bcd', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('bcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("bcda", c); resultb = ft_strrchr("bcda", c);
        compare_results("strrchr('bcda', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('bcda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("a", c); resultb = ft_strrchr("a", c);
        compare_results("strrchr('a', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('a', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("", c); resultb = ft_strrchr("", c);
        compare_results("strrchr('', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("abacd", c); resultb = ft_strrchr("abacd", c);
        compare_results("strrchr('abacd', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('abacd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("abacda", c); resultb = ft_strrchr("abacda", c);
        compare_results("strrchr('abacda', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('abacda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("abacda", '\0'); resultb = ft_strrchr("abacda", '\0');
        compare_results("strrchr('abacda', '\\0')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('abacda', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("", '\0'); resultb = ft_strrchr("", '\0');
        compare_results("strrchr('', '\\0')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("aaaaa", c); resultb = ft_strrchr("aaaaa", c);
        compare_results("strrchr('aaaaa', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('aaaaa', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("longer string of characters", c); resultb = ft_strrchr("longer string of characters", c);
        compare_results("strrchr('longer string of characters', 'a')", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('longer string of characters', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("char overflow", 't' + 256); resultb = ft_strrchr("char overflow", 't' + 256);
        compare_results("strrchr('char overflow', 't' + 256)", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('char overflow', 't' + 256)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("char overflow", 't' + 258); resultb = ft_strrchr("char overflow", 't' + 258);
        compare_results("strrchr('char overflow', 't' + 258)", resulta, resultb, 1, ++test, &pass, 2);
    } else {
        printf("Test %d: %14s - Segmentation Fault - FAIL\n", ++test, "strrchr('char overflow', 't' + 258)");
        pass = false;
    }

    printf("Total grade: ");
    if (pass == true) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        *grandpass = false;
    }

    printf("\nFinished test_strrchr...\n");
    printf("Overall grade: ");
    if (*grandpass == true) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}



void run_test_memset() {
    printf("\nRunning test_memset...\n");
    // Code from test_memset.c
    {
        char str[50] = "GeeksForGeeks is for programming geeks.";
        printf("\nBefore memset(): %s\n", str);
        // Fill 8 characters starting from str[13] with '.'
        ft_memset(str + 13, '.', 8*sizeof(char));
        printf("After memset():  %s\n", str);
    }
    printf("Finished test_memset.\n\n");
}
void run_test_putchar() {
    printf("Running test_putchar...\n");
    // Code from test_putchar.c
    {
        ft_putchar_fd('a', 1);
    }
    printf("Finished test_putchar.\n\n");
}
void run_test_putendl() {
    printf("Running test_putendl...\n");
    // Code from test_putendl.c
    {
        ft_putendl_fd("Hello, world!", 1);
    }
    printf("Finished test_putendl.\n\n");
}
void run_test_putnbr() {
    printf("Running test_putnbr...\n");
    // Code from test_putnbr.c
    {
        ft_putnbr_fd(42, 1);
    }
    printf("Finished test_putnbr.\n\n");
}
void run_test_putstr() {
    printf("Running test_putstr...\n");
    // Code from test_putstr.c
    {
        ft_putstr_fd("Hello, world!", 1);
    }
    printf("Finished test_putstr.\n\n");
}
void run_test_split() {
    printf("Running test_split...\n");
    // Code from test_split.c
    {
        char **result = ft_split("Hello world this is a test", ' ');
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    }
    printf("Finished test_split.\n\n");
}
void run_test_strchrs() {
    printf("Running test_strchrs...\n");
    // Code from test_strchrs.c
    {
        const char *s = "Hello, world!";
        char c = 'o';
        char *result = ft_strchr(s, c);
        printf("Result: %s\n", result);
    }
    printf("Finished test_strchrs.\n\n");
}
void run_test_strdup() {
    printf("Running test_strdup...\n");
    // Code from test_strdup.c
    {
        const char *s = "Hello, world!";
        char *result = ft_strdup(s);
        printf("Result: %s\n", result);
        free(result);
    }
    printf("Finished test_strdup.\n\n");
}
void run_test_striteri() {
    printf("Running test_striteri...\n");
    // Code from test_striteri.c
    {
        void my_func(unsigned int i, char *c) {
            *c = *c + i;
        }
        char s[] = "Hello";
        ft_striteri(s, my_func);
        printf("Result: %s\n", s);
    }
    printf("Finished test_striteri.\n\n");
}
void run_test_strjoin() {
    printf("Running test_strjoin...\n");
    // Code from test_strjoin.c
    {
        const char *s1 = "Hello, ";
        const char *s2 = "world!";
        char *result = ft_strjoin(s1, s2);
        printf("Result: %s\n", result);
        free(result);
    }
    printf("Finished test_strjoin.\n\n");
}