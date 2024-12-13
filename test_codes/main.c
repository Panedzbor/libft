#include "../libft/libft.h"
/* # include <stdio.h>
# include <ctype.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>(*i)++;
# include <setjmp.h>
# include <bsd/string.h> */

#include "../libft/ft_isprint.c"
#include "../libft/ft_toupper.c"
#include "../libft/ft_tolower.c"
#include "../libft/ft_strrchr.c"
#include "../libft/ft_strncmp.c"
#include "../libft/ft_strnstr.c"
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
#include "../libft/ft_lstnew.c"
#include "../libft/ft_lstadd_front.c"
#include "../libft/ft_lstsize.c"
#include "../libft/ft_lstlast.c"
#include "../libft/ft_lstadd_back.c"
#include "../libft/ft_lstdelone.c"
#include "../libft/ft_lstclear.c"
#include "../libft/ft_lstiter.c"
#include "../libft/ft_lstmap.c"

#define RESET       "\033[0m"  // Reset to default color
#define RED         "\033[31m"
#define GREEN       "\033[32m"

struct tests
{
    char *function;
    bool passed;
};



// Function prototypes
void run_test_is(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strlen(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strchr(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strrchr(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strncmp(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strnstr(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strlcpy(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strlcat(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_memset(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_bzero(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_memcpy(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_memmove(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_memchr(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_memcmp(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_atoi(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strdup(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_calloc(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_substr(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strjoin(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strtrim(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_split(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_itoa(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_strmapi(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_striteri(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_putchar(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_putstr(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_putendl(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_putnbr(bool *grandpass, struct tests (*t)[43], int *i);
void run_test_bonus(bool *grandpass, struct tests (*t)[43], int *i);

jmp_buf buf; 
void signal_handler(int sig) 
{ 
    printf("Error: Caught signal %d (%s)\n", sig, strsignal(sig)); 
    longjmp(buf, 1);
}

char f(unsigned int i, char c) {
    return ((char)(c + 1));
}

void fi(unsigned int i, char *c) {
    *c += 1;
}

void del(void *ptr)
{
    free(ptr);
}

void fb(void *ptr)
{
    int *p1 = (int *)ptr;
    *p1 += 1;
}

void *fret(void *ptr)
{
    int *p = (int*)malloc(sizeof(int));
    if (p == NULL)
        return NULL;
    *p = *(int *)ptr;
    *p += 1;
    return ((void*)p);
}

void normal_del_cl(t_list **start, t_list **node, void (*del)(void*), int mode)
{
    t_list *curnd = *start;
    while (curnd && curnd->next != *node && curnd != *node)
        curnd = curnd->next;
    
    if (mode == 1)
    {
        if (curnd->next == *node)
            curnd->next = (*node)->next;
        if (curnd == *node)
            *start = (*node)->next;
        ft_lstdelone(*node, del);
    }
    else
    {
        if (curnd->next == *node)
            curnd->next = NULL;
        if (node == *start)
            *start = NULL;
        ft_lstclear(node, del);
    }
}

int main() {
    bool grandpass = true;
    signal(SIGSEGV, signal_handler);

    struct tests t[43] = {
        {"ft_isalpha", true},
        {"ft_isdigit", true},
        {"ft_isalnum", true},
        {"ft_isascii", true},
        {"ft_isprint", true},
        {"ft_toupper", true},
        {"ft_tolower", true},
        {"ft_strlen", true},
        {"ft_strchr", true},
        {"ft_strrchr", true},
        {"ft_strncmp", true},
        {"ft_strnstr", true},
        {"ft_strlcpy", true},
        {"ft_strlcat", true},
        {"ft_memset", true},
        {"ft_bzero", true},
        {"ft_memcpy", true},
        {"ft_memmove", true},
        {"ft_memchr", true},
        {"ft_memcmp", true},
        {"ft_atoi", true},
        {"ft_strdup", true},
        {"ft_calloc", true},
        {"ft_substr", true},
        {"ft_strjoin", true},
        {"ft_strtrim", true},
        {"ft_split", true},
        {"ft_itoa", true},
        {"ft_strmapi", true},
        {"ft_striteri", true},
        {"ft_putchar", true},
        {"ft_putstr", true},
        {"ft_putendl", true},
        {"ft_putnbr", true},
        {"ft_lstnew", true},
        {"ft_lstadd_front", true},
        {"ft_lstadd_back", true},
        {"ft_lstsize", true},
        {"ft_lstlast", true},
        {"ft_lstdelone", true},
        {"ft_lstclear", true},
        {"ft_lstiter", true},
        {"ft_lstmap", true}
    };
    int i = 0;
    run_test_is(&grandpass, t, &i);
    run_test_strlen(&grandpass, t, &i);
    run_test_strchr(&grandpass, t, &i);
    run_test_strrchr(&grandpass, t, &i);
    run_test_strncmp(&grandpass, t, &i);
    run_test_strnstr(&grandpass, t, &i);
    run_test_strlcpy(&grandpass, t, &i);
    run_test_strlcat(&grandpass, t, &i);
    run_test_memset(&grandpass, t, &i);
    run_test_bzero(&grandpass, t, &i);
    run_test_memcpy(&grandpass, t, &i);
    run_test_memmove(&grandpass, t, &i);
    run_test_memchr(&grandpass, t, &i);
    run_test_memcmp(&grandpass, t, &i);
    run_test_atoi(&grandpass, t, &i);
    run_test_strdup(&grandpass, t, &i);
    run_test_calloc(&grandpass, t, &i);
    run_test_substr(&grandpass, t, &i);
    run_test_strjoin(&grandpass, t, &i);
    run_test_strtrim(&grandpass, t, &i);
    run_test_split(&grandpass, t, &i);
    run_test_itoa(&grandpass, t, &i);
    run_test_strmapi(&grandpass, t, &i);
    run_test_striteri(&grandpass, t, &i);
    run_test_putchar(&grandpass, t, &i);
    run_test_putstr(&grandpass, t, &i);
    run_test_putendl(&grandpass, t, &i);
    run_test_putnbr(&grandpass, t, &i);
    /* printf("before bonus it should be 34: %d\n", i); */
    run_test_bonus(&grandpass, t, &i);
    
    if (grandpass == true)
    {
        printf("\n\nCongratulations! You've passed the test!!!\n");
    }
    else
    {
        printf("\n\nTest failed :( There are still functions to work on...\n");
        printf("\nFunctions with errors:\n");
        for (i = 0; i < 43; i++)
        {
            if (t[i].passed == false)
                printf("%s\n", t[i].function);
        }
        printf("\nDon't give up ;)\n");
    }
    return 0;
}

int compare_results(const char* func_name, void *std_result, void *custom_result, int mode, int test, bool *pass, int datatype, size_t n) {
    /* int a = *(int*)std_result;
    int b = *(int*)custom_result; */
    
    if (mode == 1)
    {
        if (datatype == 1)
        {
            if (*(int *)std_result == *(int *)custom_result) {
                printf("Test %d: %50s %15d || %-15d - ", test, func_name, *(int *)std_result, *(int *)custom_result);
                printf(GREEN "PASS");
                printf(RESET "\n");
            } else {
                printf("Test %d: %50s %15d || %-15d - ", test, func_name, *(int *)std_result, *(int *)custom_result);
                printf(RED "FAIL");
                printf(RESET "\n");
                *pass = false;
                return 0;
            }
        }
        else if (datatype == 2)
        {
            if (std_result && custom_result)
            {
                if (strcmp((const char *)std_result, (const char *)custom_result) == 0)
                {
                    printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                    printf(GREEN "PASS\n");
                    printf(RESET "\n");
                }
                else
                {
                    printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                    printf(RED "FAIL");
                    printf(RESET "\n");
                    *pass = false;
                    return 0;   
                }
            }
            else if (!(std_result && custom_result))
            {
                printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                printf(GREEN "PASS\n");
                printf(RESET "\n");
            }
            else{
                printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                printf(RED "FAIL");
                printf(RESET "\n");
                *pass = false;   
                return 0;
            }
        }
        else if (datatype == 3)
        {
            if (std_result && custom_result)
            {
                if (memcmp((const void *)std_result, (const void *)custom_result, n) == 0)
                {
                    printf("Test %d: %50s   ", test, func_name);
                    fflush(stdout);
                    write(1, std_result, n);
                    write(1, " || ", 4);
                    write(1, custom_result, n);
                    printf(" - ");
                    printf(GREEN "PASS\n");
                    printf(RESET "\n");
                }
                else
                {
                    printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                    printf(RED "FAIL");
                    printf(RESET "\n");
                    *pass = false;   
                    return 0;
                }
            }
            else if (!(std_result && custom_result))
            {
                printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                printf(GREEN "PASS\n");
                printf(RESET "\n");
            }
            else{
                printf("Test %d: %50s %15s || %-15s - ", test, func_name, (char *)std_result, (char *)custom_result);
                printf(RED "FAIL");
                printf(RESET "\n");
                *pass = false;   
                return 0;
            }
        }
        else if(datatype == 4)
        {
            if(std_result == custom_result)
            {
                printf("Test %d: %50s %15p || %-15p - ", test, func_name, std_result, custom_result);
                printf(GREEN "PASS\n");
                printf(RESET "\n");
            }
            else
            {
                printf("Test %d: %50s %15p || %-15p - ", test, func_name, std_result, custom_result);
                printf(RED "FAIL");
                printf(RESET "\n");
                *pass = false;
                return 0;
            }
        }
    }
    else if (mode == 2)
    {
        if ((*(int *)std_result > 0 && *(int *)custom_result > 0) || (*(int *)std_result == 0 && *(int *)custom_result == 0) || (*(int *)std_result < 0 && *(int *)custom_result < 0)) {
        {
            printf("Test %d: %50s %15d || %-15d - ", test, func_name, *(int *)std_result, *(int *)custom_result);
            printf(GREEN "PASS\n");
            printf(RESET "\n");
        }
        } else {
            printf("Test %d: %50s %15d || %-15d - ", test, func_name, *(int *)std_result, *(int *)custom_result);
            printf(RED "FAIL");
            printf(RESET "\n");
            *pass = false;
            return 0;
        }
    }
    else if (mode == 3)
    {
        if (datatype == 1)
            printf("%14s %15d || %-15d - Not tested\n", func_name, *(int *)std_result, *(int *)custom_result);
        else if (datatype == 2)
            printf("%14s %15s || %-15s - Not tested\n", func_name, (char *)std_result, (char *)custom_result);
    }
    return 1;
}

void run_test_is(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    bool pass2 = true;
    int test = 0;
    int resulta, resultb;
    printf("Running test_is...\n");

    // isalpha function comparison
    printf("isalpha vs ft_isalpha:\n");
    resulta = isalpha('A'); resultb = ft_isalpha('A');
    compare_results("isalpha('A')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalpha('D'); resultb = ft_isalpha('D');
    compare_results("isalpha('D')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalpha('z'); resultb = ft_isalpha('z');
    compare_results("isalpha('z')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalpha('@'); resultb = ft_isalpha('@');
    compare_results("isalpha('@')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalpha(':'); resultb = ft_isalpha(':');
    compare_results("isalpha(':')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalpha(58); resultb = ft_isalpha(58);
    compare_results("isalpha(58)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalpha(-1); resultb = ft_isalpha(-1);
    compare_results("isalpha(-1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalpha(580); resultb = ft_isalpha(580);
    compare_results("isalpha(580)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    /* resulta = isalpha('こ'); resultb = ft_isalpha('こ');
    compare_results("isalpha('こ')", &resulta, &resultb, 2, ++test, &pass, 1, 0); */
    printf("Total grade: ");
    if (pass == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        pass = true;
        pass2 = false;
    }
    (*i)++;
    test = 0;
    // isdigit function comparison
    printf("\nisdigit vs ft_isdigit:\n");
    resulta = isdigit('1'); resultb = ft_isdigit('1');
    compare_results("isdigit('1')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isdigit('0'); resultb = ft_isdigit('0');
    compare_results("isdigit('0')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isdigit('9'); resultb = ft_isdigit('9');
    compare_results("isdigit('9')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isdigit('@'); resultb = ft_isdigit('@');
    compare_results("isdigit('@')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    /* resulta = isdigit('こ'); resultb = ft_isdigit('こ');
    compare_results("isdigit('こ')", &resulta, &resultb, 2, ++test, &pass, 1, 0); */
    printf("Total grade: ");
    if (pass == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        pass = true;
        pass2 = false;
    }
    (*i)++;
    test = 0;
    // isalnum function comparison
    printf("\nisalnum vs ft_isalnum:\n");
    resulta = isalnum('1'); resultb = ft_isalnum('1');
    compare_results("isalnum('1')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalnum('a'); resultb = ft_isalnum('a');
    compare_results("isalnum('a')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalnum('G'); resultb = ft_isalnum('G');
    compare_results("isalnum('G')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isalnum('@'); resultb = ft_isalnum('@');
    compare_results("isalnum('@')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    /* resulta = isalnum('こ'); resultb = ft_isalnum('こ');
    compare_results("isalnum('こ')", &resulta, &resultb, 2, ++test, &pass, 1, 0); */
    printf("Total grade: ");
    if (pass == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        pass = true;
        pass2 = false;
    }
    (*i)++;
    test = 0;
    // isascii function comparison
    printf("\nisascii vs ft_isascii:\n");
    resulta = isascii('@'); resultb = ft_isascii('@');
    compare_results("isascii('@')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isascii('a'); resultb = ft_isascii('a');
    compare_results("isascii('a')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isascii(130); resultb = ft_isascii(130);
    compare_results("isascii(130)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isascii(13); resultb = ft_isascii(13);
    compare_results("isascii(13)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    /* resulta = isacii('こ'); resultb = ft_isascii('こ');
    compare_results("isascii('こ')", &resulta, &resultb, 2, ++test, &pass, 1, 0); */
    printf("Total grade: ");
    if (pass == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        pass = true;
        pass2 = false;
    }
    (*i)++;
    test = 0;
    // isprint function comparison
    printf("\nisprint vs ft_isprint:\n");
    resulta = isprint(' '); resultb = ft_isprint(' ');
    compare_results("isprint(' ')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isprint('"'); resultb = ft_isprint('"');
    compare_results("isprint('\"')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isprint('4'); resultb = ft_isprint('4');
    compare_results("isprint('4')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isprint('F'); resultb = ft_isprint('F');
    compare_results("isprint('F')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    resulta = isprint('n'); resultb = ft_isprint('n');
    compare_results("isprint('n')", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    /* resulta = isprint('こ'); resultb = ft_isprint('こ');
    compare_results("isprint('こ')", &resulta, &resultb, 2, ++test, &pass, 1, 0); */
    printf("Total grade: ");
    if (pass == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        pass = true;
        pass2 = false;
    }
    (*i)++;
    test = 0;
    // toupper function comparison
    printf("\ntoupper vs ft_toupper:\n");
    resulta = toupper(' '); resultb = ft_toupper(' ');
    compare_results("toupper(' ')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = toupper('"'); resultb = ft_toupper('"');
    compare_results("toupper('\"')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = toupper('4'); resultb = ft_toupper('4');
    compare_results("toupper('4')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = toupper('F'); resultb = ft_toupper('F');
    compare_results("toupper('F')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = toupper('n'); resultb = ft_toupper('n');
    compare_results("toupper('n')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    /* resulta = toupper('こ'); resultb = ft_toupper('こ');
    compare_results("toupper('こ')", &resulta, &resultb, 2, ++test, &pass, 1, 0); */
    printf("Total grade: ");
    if (pass == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        pass = true;
        pass2 = false;
    }
    (*i)++;
    test = 0;
    // tolower function comparison
    printf("\ntolower vs ft_tolower:\n");
    resulta = tolower(' '); resultb = ft_tolower(' ');
    compare_results("tolower(' ')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = tolower('"'); resultb = ft_tolower('"');
    compare_results("tolower('\"')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = tolower('4'); resultb = ft_tolower('4');
    compare_results("tolower('4')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = tolower('F'); resultb = ft_tolower('F');
    compare_results("tolower('F')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    resulta = tolower('n'); resultb = ft_tolower('n');
    compare_results("tolower('n')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    /* resulta = tolower('こ'); resultb = ft_tolower('こ');
    compare_results("tolower('こ')", &resulta, &resultb, 2, ++test, &pass, 1, 0); */

    // Final grade check
    printf("Total grade: ");
    if (pass == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        pass = true;
        pass2 = false;
    }
    (*i)++;
    printf("\nFinished test_is...\n");
    printf("Overall grade fot is* and to* functions: ");
    if (pass2 == true)
    {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }
    else
    {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false;
    }
}

void run_test_strlen(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    int resulta, resultb;
    printf("\nRunning test_strlen...\n");

    // strlen function comparison
    printf("strlen vs ft_strlen:\n");

    if (setjmp(buf) == 0) {
        resulta = strlen("Text"); resultb = ft_strlen("Text");
        compare_results("strlen('Text')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlen('Text')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strlen("a"); resultb = ft_strlen("a");
        compare_results("strlen('a')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlen('a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strlen(""); resultb = ft_strlen("");
        compare_results("strlen('')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlen('')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strlen("\0"); resultb = ft_strlen("\0");
        compare_results("strlen('\\0')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlen('\\0')");
        pass = false;
    }

    // Handling segfault for NULL input
    if (setjmp(buf) == 0) {
        resulta = 1; resultb = ft_strlen(NULL);
        compare_results("strlen(NULL)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
        pass = false;
        printf("Test %d: %50s - Segmentation Fault expected - ", ++test, "strlen(NULL)");
        printf(RED "FAIL");
        printf(RESET" \n");
    } else {
        printf("Test %d: %50s - Segmentation Fault - ", ++test, "strlen(NULL)");
        printf(GREEN "PASS");
        printf(RESET" \n");
    }
    

    printf("\nFinished test_strlen...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strchr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    char c = 'a';
    char *resulta, *resultb;
    printf("\nRunning test_strchr...\n");

    // strchr function comparison
    printf("strchr vs ft_strchr:\n");

    if (setjmp(buf) == 0) {
        resulta = strchr("abcd", c); resultb = ft_strchr("abcd", c);
        compare_results("strchr('abcd', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('abcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("bcd", c); resultb = ft_strchr("bcd", c);
        compare_results("strchr('bcd', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('bcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("bcda", c); resultb = ft_strchr("bcda", c);
        compare_results("strchr('bcda', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('bcda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("a", c); resultb = ft_strchr("a", c);
        compare_results("strchr('a', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('a', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("", c); resultb = ft_strchr("", c);
        compare_results("strchr('', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("abacd", c); resultb = ft_strchr("abacd", c);
        compare_results("strchr('abacd', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('abacd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("abacda", c); resultb = ft_strchr("abacda", c);
        compare_results("strchr('abacda', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('abacda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("abacda", '\0'); resultb = ft_strchr("abacda", '\0');
        compare_results("strchr('abacda', '\\0')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('abacda', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("", '\0'); resultb = ft_strchr("", '\0');
        compare_results("strchr('', '\\0')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("aaaaa", c); resultb = ft_strchr("aaaaa", c);
        compare_results("strchr('aaaaa', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('aaaaa', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("longer string of characters", c); resultb = ft_strchr("longer string of characters", c);
        compare_results("strchr('longer string of characters', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('longer string of characters', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("char overflow", 't' + 256); resultb = ft_strchr("char overflow", 't' + 256);
        compare_results("strchr('char overflow', 't' + 256)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('char overflow', 't' + 256)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strchr("char overflow", 't' + 258); resultb = ft_strchr("char overflow", 't' + 258);
        compare_results("strchr('char overflow', 't' + 258)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strchr('char overflow', 't' + 258)");
        pass = false;
    }

    printf("\nFinished test_strchr...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strrchr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    char c = 'a';
    char *resulta, *resultb;
    printf("\nRunning test_strrchr...\n");

    // strrchr function comparison
    printf("strrchr vs ft_strrchr:\n");

    if (setjmp(buf) == 0) {
        resulta = strrchr("abcd", c); resultb = ft_strrchr("abcd", c);
        compare_results("strrchr('abcd', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('abcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("bcd", c); resultb = ft_strrchr("bcd", c);
        compare_results("strrchr('bcd', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('bcd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("bcda", c); resultb = ft_strrchr("bcda", c);
        compare_results("strrchr('bcda', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('bcda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("a", c); resultb = ft_strrchr("a", c);
        compare_results("strrchr('a', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('a', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("", c); resultb = ft_strrchr("", c);
        compare_results("strrchr('', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("abacd", c); resultb = ft_strrchr("abacd", c);
        compare_results("strrchr('abacd', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('abacd', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("abacda", c); resultb = ft_strrchr("abacda", c);
        compare_results("strrchr('abacda', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('abacda', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("abacda", '\0'); resultb = ft_strrchr("abacda", '\0');
        compare_results("strrchr('abacda', '\\0')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('abacda', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("", '\0'); resultb = ft_strrchr("", '\0');
        compare_results("strrchr('', '\\0')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('', '\\0')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("aaaaa", c); resultb = ft_strrchr("aaaaa", c);
        compare_results("strrchr('aaaaa', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('aaaaa', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("longer string of characters", c); resultb = ft_strrchr("longer string of characters", c);
        compare_results("strrchr('longer string of characters', 'a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('longer string of characters', 'a')");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("char overflow", 't' + 256); resultb = ft_strrchr("char overflow", 't' + 256);
        compare_results("strrchr('char overflow', 't' + 256)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('char overflow', 't' + 256)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strrchr("char overflow", 't' + 258); resultb = ft_strrchr("char overflow", 't' + 258);
        compare_results("strrchr('char overflow', 't' + 258)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strrchr('char overflow', 't' + 258)");
        pass = false;
    }

    printf("\nFinished test_strrchr...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strncmp(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    int resulta, resultb;
    printf("\nRunning test_strncmp...\n");

    // strncmp function comparison
    printf("strncmp vs ft_strncmp:\n");

    if (setjmp(buf) == 0) {
        resulta = strncmp("abcd", "abcy", 4);  // Library function first
        resultb = ft_strncmp("abcd", "abcy", 4);  // My implementation second
        compare_results("ft_strncmp('abcd', 'abcy', 4)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('abcd', 'abcy', 4)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("abcd", "abcy", 3); 
        resultb = ft_strncmp("abcd", "abcy", 3);
        compare_results("ft_strncmp('abcd', 'abcy', 3)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('abcd', 'abcy', 3)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("abcd", "abcy", 5); 
        resultb = ft_strncmp("abcd", "abcy", 5);
        compare_results("ft_strncmp('abcd', 'abcy', 5)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('abcd', 'abcy', 5)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("abcd", "abcd", 4); 
        resultb = ft_strncmp("abcd", "abcd", 4);
        compare_results("ft_strncmp('abcd', 'abcd', 4)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('abcd', 'abcd', 4)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("a", "a", 1); 
        resultb = ft_strncmp("a", "a", 1);
        compare_results("ft_strncmp('a', 'a', 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('a', 'a', 1)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("zex", "rex", 3); 
        resultb = ft_strncmp("zex", "rex", 3);
        compare_results("ft_strncmp('zex', 'rex', 3)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('zex', 'rex', 3)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("tour", "tourin", 6); 
        resultb = ft_strncmp("tour", "tourin", 6);
        compare_results("ft_strncmp('tour', 'tourin', 6)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('tour', 'tourin', 6)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("tour", "tourin", 5); 
        resultb = ft_strncmp("tour", "tourin", 5);
        compare_results("ft_strncmp('tour', 'tourin', 5)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('tour', 'tourin', 5)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("a", "a", 0); 
        resultb = ft_strncmp("a", "a", 0);
        compare_results("ft_strncmp('a', 'a', 0)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('a', 'a', 0)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("a", "a", -1); 
        resultb = ft_strncmp("a", "a", -1);
        compare_results("ft_strncmp('a', 'a', -1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('a', 'a', -1)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("", "a", 1); 
        resultb = ft_strncmp("", "a", 1);
        compare_results("ft_strncmp('', 'a', 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('', 'a', 1)");
        pass = false;
    }

    /* if (setjmp(buf) == 0) {
        resulta = strncmp(NULL, NULL, 1); 
        resultb = ft_strncmp(NULL, NULL, 1);
        compare_results("ft_strncmp(NULL, NULL, 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault - FAIL\n", ++test, "strncmp(NULL, NULL, 1)");
        pass = false;
    } */

    /* if (setjmp(buf) == 0) {
        resulta = strncmp("a", NULL, 1); 
        resultb = ft_strncmp("a", NULL, 1);
        compare_results("ft_strncmp('a', NULL, 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
        pass = false;
        printf("Test %d: %50s - Segmentation Fault expected - FAIL\n", ++test, "strncmp('a', NULL, 1)");
    } else {
        printf("Test %d: %50s - Segmentation Fault - PASS\n", ++test, "strncmp('a', NULL, 1)");
    }

    if (setjmp(buf) == 0) {
        resulta = strncmp("a", NULL, 1); 
        resultb = ft_strncmp(NULL, "a", 1);
        compare_results("ft_strncmp(NULL, 'a', 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
        pass = false;
        printf("Test %d: %50s - Segmentation Fault expected - FAIL\n", ++test, "strncmp(NULL, 'a', 1)");
    } else {
        printf("Test %d: %50s - Segmentation Fault - PASS\n", ++test, "strncmp(NULL, 'a', 1)");
    } */

    /* if (setjmp(buf) == 0) {
        resulta = strncmp("a", NULL, 3); 
        resultb = ft_strncmp(NULL, "a", 3);
        compare_results("ft_strncmp(NULL, 'a', 3)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
        pass = false;
        printf("Test %d: %50s - Segmentation Fault expected - FAIL\n", ++test, "strncmp(NULL, 'a', 3)");
    } else {
        printf("Test %d: %50s - Segmentation Fault - PASS\n", ++test, "strncmp(NULL, 'a', 3)");
    } */

    if (setjmp(buf) == 0) {
        resulta = strncmp("test\200", "test\0", 6); 
        resultb = ft_strncmp("test\200", "test\0", 6);
        compare_results("ft_strncmp('test\\200', 'test\\0', 6)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "ft_strncmp('test\\200', 'test\\0', 6)");
        pass = false;
    }

    printf("\nFinished test_strncmp...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strnstr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    char *resulta, *resultb;
    printf("\nRunning test_strnstr...\n");

    // strnstr function comparison
    printf("strnstr vs ft_strnstr:\n");

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "romo", 0);
        resultb = ft_strnstr("Voroboromoroko", "romo", 0);
        compare_results("strnstr('Voroboromoroko', 'romo', 0)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'romo', 0)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "romo", 9);
        resultb = ft_strnstr("Voroboromoroko", "romo", 9);
        compare_results("strnstr('Voroboromoroko', 'romo', 9)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'romo', 9)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "romo", 14);
        resultb = ft_strnstr("Voroboromoroko", "romo", 14);
        compare_results("strnstr('Voroboromoroko', 'romo', 14)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'romo', 14)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "romo", 15);
        resultb = ft_strnstr("Voroboromoroko", "romo", 15);
        compare_results("strnstr('Voroboromoroko', 'romo', 15)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'romo', 15)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "romo", 20);
        resultb = ft_strnstr("Voroboromoroko", "romo", 20);
        compare_results("strnstr('Voroboromoroko', 'romo', 20)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'romo', 20)");
        pass = false;
    }

    // Additional test cases
    if (setjmp(buf) == 0) {
        resulta = strnstr("", "romo", 10);
        resultb = ft_strnstr("", "romo", 10);
        compare_results("strnstr('', 'romo', 10)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('', 'romo', 10)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "", 20);
        resultb = ft_strnstr("Voroboromoroko", "", 20);
        compare_results("strnstr('Voroboromoroko', '', 20)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', '', 20)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("", "", 0);
        resultb = ft_strnstr("", "", 0);
        compare_results("strnstr('', '', 0)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('', '', 0)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "x", 20);
        resultb = ft_strnstr("Voroboromoroko", "x", 20);
        compare_results("strnstr('Voroboromoroko', 'x', 20)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'x', 20)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "oko", 12);
        resultb = ft_strnstr("Voroboromoroko", "oko", 12);
        compare_results("strnstr('Voroboromoroko', 'oko', 12)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'oko', 12)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "oko", 11);
        resultb = ft_strnstr("Voroboromoroko", "oko", 11);
        compare_results("strnstr('Voroboromoroko', 'oko', 11)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'oko', 11)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "oroboro", 10);
        resultb = ft_strnstr("Voroboromoroko", "oroboro", 10);
        compare_results("strnstr('Voroboromoroko', 'oroboro', 10)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'oroboro', 10)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "Voroboromoroko", 20);
        resultb = ft_strnstr("Voroboromoroko", "Voroboromoroko", 20);
        compare_results("strnstr('Voroboromoroko', 'Voroboromoroko', 20)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'Voroboromoroko', 20)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("Voroboromoroko", "Voro", 3);
        resultb = ft_strnstr("Voroboromoroko", "Voro", 3);
        compare_results("strnstr('Voroboromoroko', 'Voro', 3)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('Voroboromoroko', 'Voro', 3)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("abcdef", "def", 6);
        resultb = ft_strnstr("abcdef", "def", 6);
        compare_results("strnstr('abcdef', 'def', 6)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('abcdef', 'def', 6)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("abcdef", "def", 5);
        resultb = ft_strnstr("abcdef", "def", 5);
        compare_results("strnstr('abcdef', 'def', 5)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('abcdef', 'def', 5)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("abcdef", "abc", 2);
        resultb = ft_strnstr("abcdef", "abc", 2);
        compare_results("strnstr('abcdef', 'abc', 2)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('abcdef', 'abc', 2)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("a", "a", 1);
        resultb = ft_strnstr("a", "a", 1);
        compare_results("strnstr('a', 'a', 1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('a', 'a', 1)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("a", "b", 1);
        resultb = ft_strnstr("a", "b", 1);
        compare_results("strnstr('a', 'b', 1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('a', 'b', 1)");
        pass = false;
    }

    if (setjmp(buf) == 0) {
        resulta = strnstr("abcabcabc", "abc", 9);
        resultb = ft_strnstr("abcabcabc", "abc", 9);
        compare_results("strnstr('abcabcabc', 'abc', 9)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "strnstr('abcabcabc', 'abc', 9)");
        pass = false;
    }

    // printf("Search null in null with size 9: \"%s\" | \"%s\"\n", ft_strnstr(NULL, NULL, 9), strnstr(NULL, NULL, 9)); //segfault

    printf("\nFinished test_strnstr...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strlcpy(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    size_t resulta, resultb;
    printf("\nRunning test_strlcpy...\n");

    // Test cases for strlcpy function comparison
    printf("strlcpy vs ft_strlcpy:\n");

    // Test 1
    {
        char dest[6], dest2[6]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 6\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 6);
            resultb = ft_strlcpy(dest, src, 6);
            compare_results("strlcpy('Hello World!', 6)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 6)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 6)");
            pass = false;
        }
    }

    // Test 2
    {
        char dest[6], dest2[6]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 5\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 5);
            resultb = ft_strlcpy(dest, src, 5);
            compare_results("strlcpy('Hello World!', 5)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 5)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 5)");
            pass = false;
        }
    }

    // Test 3
    {
        char dest[6], dest2[6]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 10\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 10);
            resultb = ft_strlcpy(dest, src, 10);
            compare_results("strlcpy('Hello World!', 10)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 10)", dest2, dest, 3, test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 10)");
            pass = false;
        }
    }

    // Test 4
    {
        char dest[6], dest2[6]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[6], 8\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 8);
            resultb = ft_strlcpy(dest, src, 8);
            compare_results("strlcpy('Hello World!', 8)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 8)", dest2, dest, 3, test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 8)");
            pass = false;
        }
    }

    // Test 5
    {
        char dest[20], dest2[20]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[20], 12\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 12);
            resultb = ft_strlcpy(dest, src, 12);
            compare_results("strlcpy('Hello World!', 12)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 12)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 12)");
            pass = false;
        }
    }

    // Test 6
    {
        char dest[20], dest2[20]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[20], 20\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 20);
            resultb = ft_strlcpy(dest, src, 20);
            compare_results("strlcpy('Hello World!', 20)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 20)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 20)");
            pass = false;
        }
    }

    // Test 7
    {
        char dest[1], dest2[1]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[1], 1\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 1);
            resultb = ft_strlcpy(dest, src, 1);
            compare_results("strlcpy('Hello World!', 1)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 1)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 1)");
            pass = false;
        }
    }

    // Test 8
    {
        char dest[1], dest2[1]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[1], 0\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 0);
            resultb = ft_strlcpy(dest, src, 0);
            compare_results("strlcpy('Hello World!', 0)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 0)", dest2, dest, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 0)");
            pass = false;
        }
    }

    // Test 9
    {
        char dest[1], dest2[1]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[1], (st)-1\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, (size_t)-1);
            resultb = ft_strlcpy(dest, src, (size_t)-1);
            compare_results("strlcpy('Hello World!', (st)-1)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', (st)-1)", dest2, dest, 3, test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', (st)-1)");
            pass = false;
        }
    }

    // Test 10
    {
        char dest[1], dest2[1]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[1], (st)-2\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, (size_t)-2);
            resultb = ft_strlcpy(dest, src, (size_t)-2);
            compare_results("strlcpy('Hello World!', (st)-2)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', (st)-2)", dest2, dest, 3, test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', (st)-2)");
            pass = false;
        }
    }

    // Test 11
    {
        char dest[1], dest2[1]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[1], -2\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, -2);
            resultb = ft_strlcpy(dest, src, -2);
            compare_results("strlcpy('Hello World!', -2)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', -2)", dest2, dest, 3, test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', -2)");
            pass = false;
        }
    }

    // Test 12
    {
        char dest[6], dest2[6]; char src[] = "";
        printf("Test: char src[] = \"\"; char dest[6], 6\n");
        char empty[] = "";
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, empty, 6);
            resultb = ft_strlcpy(dest, empty, 6);
            compare_results("strlcpy('', 6)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('', 6)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('', 6)");
            pass = false;
        }
    }

    // Test 13
    {
        char dest[20], dest2[20]; char src[] = "Hello World!";
        printf("Test: char src[] = \"Hello World!\"; char dest[20], 2147483647\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, src, 2147483647);
            resultb = ft_strlcpy(dest, src, 2147483647);
            compare_results("strlcpy('Hello World!', 2147483647)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello World!', 2147483647)", dest2, dest, 3, test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello World!', 2147483647)");
            pass = false;
        }
    }

    // Test 14
    {
        char dest[6], dest2[6]; char src[] = "Hello";
        printf("Test: char src[] = \"Hello\"; char dest[6], 6\n");
        if (setjmp(buf) == 0) {
            resulta = strlcpy(dest2, "Hello", 6);
            resultb = ft_strlcpy(dest, "Hello", 6);
            compare_results("strlcpy('Hello', 6)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcpy('Hello', 6)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcpy('Hello', 6)");
            pass = false;
        }
    }

    printf("\nFinished test_strlcpy...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strlcat(bool *grandpass, struct tests (*t)[43], int *i) {

    bool pass = true;
    int test = 0;
    size_t resulta, resultb;
    printf("\nRunning test_strlcat...\n");

    // Test cases for strlcat function comparison
    printf("strlcat vs ft_strlcat:\n");

    // Test 1
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, -1\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, -1);
            resultb = ft_strlcat(dest, src, -1);
            compare_results("strlcat('World', -1)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', -1)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', -1)");
            pass = false;
        }
    }

    // Test 2
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 0\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 0);
            resultb = ft_strlcat(dest, src, 0);
            compare_results("strlcat('World', 0)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 0)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 0)");
            pass = false;
        }
    }

    // Test 3
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 9\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 9);
            resultb = ft_strlcat(dest, src, 9);
            compare_results("strlcat('World', 9)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 9)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 9)");
            pass = false;
        }
    }

    // Test 4
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 10\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 10);
            resultb = ft_strlcat(dest, src, 10);
            compare_results("strlcat('World', 10)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 10)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 10)");
            pass = false;
        }
    }

    // Test 5
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 11\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 11);
            resultb = ft_strlcat(dest, src, 11);
            compare_results("strlcat('World', 11)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 11)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 11)");
            pass = false;
        }
    }

    // Test 6
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 12\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 12);
            resultb = ft_strlcat(dest, src, 12);
            compare_results("strlcat('World', 12)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 12)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 12)");
            pass = false;
        }
    }

    // Test 7
    {
        char src[] = "";
        char dest[11] = {};
        char dest2[11] = {};
        printf("Test: char src[] = \"\"; char dest[11], -1\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, -1);
            resultb = ft_strlcat(dest, src, -1);
            compare_results("strlcat('', -1)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('', -1)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('', -1)");
            pass = false;
        }
    }

    // Test 8
    {
        char src[] = "";
        char dest[11] = {};
        char dest2[11] = {};
        printf("Test: char src[] = \"\"; char dest[11], 0\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 0);
            resultb = ft_strlcat(dest, src, 0);
            compare_results("strlcat('', 0)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('', 0)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('', 0)");
            pass = false;
        }
    }

    // Test 9
    {
        char src[] = "";
        char dest[11] = {};
        char dest2[11] = {};
        printf("Test: char src[] = \"\"; char dest[11], 1\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 1);
            resultb = ft_strlcat(dest, src, 1);
            compare_results("strlcat('', 1)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('', 1)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('', 1)");
            pass = false;
        }
    }

    // Test 10
    {
        char src[] = "";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"\"; char dest[11] = {'H','e','l','l','o'}, 1\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 1);
            resultb = ft_strlcat(dest, src, 1);
            compare_results("strlcat('', 1)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('', 1)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('', 1)");
            pass = false;
        }
    }

    // Test 11
    {
        char src[] = "";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"\"; char dest[11] = {'H','e','l','l','o'}, 2\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 2);
            resultb = ft_strlcat(dest, src, 2);
            compare_results("strlcat('', 2)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('', 2)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('', 2)");
            pass = false;
        }
    }

    // Test 12
    {
        char src[] = "World";
        char dest[7] = {'H','e','l','l','o'};
        char dest2[7] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[7] = {'H','e','l','l','o'}, 11\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 11);
            resultb = ft_strlcat(dest, src, 11);
            compare_results("strlcat('World', 11)", &resulta, &resultb, 3, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 11)", dest2, dest, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 11)");
            pass = false;
        }
    }

    // Test 13
    {
        char src[] = "World";
        char dest[6] = {'H','e','l','l','o'};
        char dest2[6] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[6] = {'H','e','l','l','o'}, 11\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 11);
            resultb = ft_strlcat(dest, src, 11);
            compare_results("strlcat('World', 11)", &resulta, &resultb, 3, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 11)", dest2, dest, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 11)");
            pass = false;
        }
    }

    // Test 14
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 13\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 13);
            resultb = ft_strlcat(dest, src, 13);
            compare_results("strlcat('World', 13)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 13)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 13)");
            pass = false;
        }
    }

    // Test 15
    {
        char src[] = "World";
        char dest[13] = {'H','e','l','l','o'};
        char dest2[13] = {'H','e','l','l','o'};
        printf("Test: char src[] = \"World\"; char dest[13] = {'H','e','l','l','o'}, 13\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 13);
            resultb = ft_strlcat(dest, src, 13);
            compare_results("strlcat('World', 13)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 13)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 13)");
            pass = false;
        }
    }

    // Edge Case 1
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Edge Case: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 1\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 1);
            resultb = ft_strlcat(dest, src, 1);
            compare_results("strlcat('World', 1)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 1)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 1)");
            pass = false;
        }
    }

    // Edge Case 2
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Edge Case: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o'}, 5\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 5);
            resultb = ft_strlcat(dest, src, 5);
            compare_results("strlcat('World', 5)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 5)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 5)");
            pass = false;
        }
    }

    // Edge Case 3
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o','W','o','r','l','d'};
        char dest2[11] = {'H','e','l','l','o','W','o','r','l','d'};
        printf("Edge Case: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o','W','o','r','l','d'}, 10\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 10);
            resultb = ft_strlcat(dest, src, 10);
            compare_results("strlcat('World', 10)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 10)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 10)");
            pass = false;
        }
    }

    // Edge Case 4
    {
        char src[] = "";
        char dest[11] = {};
        char dest2[11] = {};
        printf("Edge Case: char src[] = \"\"; char dest[11], 15\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 15);
            resultb = ft_strlcat(dest, src, 15);
            compare_results("strlcat('', 15)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('', 15)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('', 15)");
            pass = false;
        }
    }

    // Edge Case 5
    {
        char src[] = "World";
        char dest[11] = {'H','e','l','l','o','W','o','r','l','d','!'};
        char dest2[11] = {'H','e','l','l','o','W','o','r','l','d','!'};
        printf("Edge Case: char src[] = \"World\"; char dest[11] = {'H','e','l','l','o','W','o','r','l','d','!'}, 15\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 15);
            resultb = ft_strlcat(dest, src, 15);
            compare_results("strlcat('World', 15)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('World', 15)", dest2, dest, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('World', 15)");
            pass = false;
        }
    }

    // Edge Case 6
    {
        char src[] = "ThisIsAVeryLargeStringThatExceedsBufferSize";
        char dest[11] = {'H','e','l','l','o'};
        char dest2[11] = {'H','e','l','l','o'};
        printf("Edge Case: char src[] = \"ThisIsAVeryLargeStringThatExceedsBufferSize\"; char dest[11] = {'H','e','l','l','o'}, 11\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest2, src, 11);
            resultb = ft_strlcat(dest, src, 11);
            compare_results("strlcat('ThisIsAVeryLargeStringThatExceedsBufferSize', 11)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('ThisIsAVeryLargeStringThatExceedsBufferSize', 11)", dest2, dest, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('ThisIsAVeryLargeStringThatExceedsBufferSize', 11)");
            pass = false;
        }
    }

    // WarMachine test case
    {
        char src[] = "lorem ipsum dolor sit amet";
        char dest[15];
        char dest2[15];
        memset(dest, 'r', 15);
        memset(dest2, 'r', 15);
        printf("WarMachine test 7 (that failed):\nExpected result: return value: 31 - result string: rrrrrrrrrrrrrrr\n");
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest, src, 5);
            resultb = ft_strlcat(dest2, src, 5);
            compare_results("[WarMachine test]strlcat('rrrrrrrrrrrrrrr', 5)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("[WarMachine test]strlcat('rrrrrrrrrrrrrrr', 5)", dest, dest2, 1, ++test, &pass, 3, 15);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('rrrrrrrrrrrrrrr', 31)");
            pass = false;
        }
    }

    // Final Test
    {
        char dest[50] = "rrrrrrrrrrrrrrr";
        char dest2[50] = "rrrrrrrrrrrrrrr";
        char src[] = "";
        size_t size = 31;
        if (setjmp(buf) == 0) {
            resulta = strlcat(dest, src, size);
            resultb = ft_strlcat(dest2, src, size);
            compare_results("strlcat('rrrrrrrrrrrrrrr', 31)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
            compare_results("strlcat('rrrrrrrrrrrrrrr', 31)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "strlcat('rrrrrrrrrrrrrrr', 31)");
            pass = false;
        }
    }

    printf("\nFinished test_strlcat...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_memset(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_memset...\n");

    // Test cases for memset function comparison
    printf("memset vs ft_memset:\n");

    // Test 1
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_memset(str1 + 13, '~', 8 * sizeof(char));
            memset(str2 + 13, '~', 8 * sizeof(char));
            compare_results("memset(str1 + 13, '~', 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(str1 + 13, '~', 8)");
            pass = false;
        }
    }

    // Test 2
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_memset(str1 + 35, '~', 8 * sizeof(char));
            memset(str2 + 35, '~', 8 * sizeof(char));
            compare_results("memset(str1 + 35, '~', 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(str1 + 35, '~', 8)");
            pass = false;
        }
    }

    // Test 3
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_memset(str1, '~', 8 * sizeof(char));
            memset(str2, '~', 8 * sizeof(char));
            compare_results("memset(str1, '~', 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(str1, '~', 8)");
            pass = false;
        }
    }

    // Test 4
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_memset(str1, '~', 0 * sizeof(char));
            memset(str2, '~', 0 * sizeof(char));
            compare_results("memset(str1, '~', 0)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(str1, '~', 0)");
            pass = false;
        }
    }

    // Test 5
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_memset(str1 + 50, '~', 8 * sizeof(char));
            memset(str2 + 50, '~', 8 * sizeof(char));
            compare_results("memset(str1 + 50, '~', 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(str1 + 50, '~', 8)");
            pass = false;
        }
    }

    // Test 6
    {
        char str1[50];
        char str2[50];
        if (setjmp(buf) == 0) {
            ft_memset(str1, 127, 8 * sizeof(char));
            memset(str2, 127, 8 * sizeof(char));
            compare_results("memset(str1, 127, 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(str1, 127, 8)");
            pass = false;
        }
    }

    // Test 7
{
    int n = 10;
    int arr[n];
    int arr2[n];
    if (setjmp(buf) == 0) {
        ft_memset(arr, 0, n * sizeof(arr[0]));
        memset(arr2, 0, n * sizeof(arr2[0]));
        for (int i = 0; i < n; i++) {
            compare_results("memset(arr, 0, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
        }
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(arr, 0, n)");
        pass = false;
    }
}

// Test 8
{
    int n = 10;
    int arr[n];
    int arr2[n];
    if (setjmp(buf) == 0) {
        ft_memset(arr, 1, n * sizeof(arr[0]));
        memset(arr2, 1, n * sizeof(arr2[0]));
        for (int i = 0; i < n; i++) {
            compare_results("memset(arr, 1, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
        }
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(arr, 1, n)");
        pass = false;
    }
}

// Test 9
{
    int n = 5;
    float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    if (setjmp(buf) == 0) {
        ft_memset(arr, 1, n * sizeof(arr[0]));
        memset(arr2, 1, n * sizeof(arr2[0]));
        for (int i = 0; i < n; i++) {
            compare_results("memset(arr, 1, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
        }
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(arr, 1, n)");
        pass = false;
    }
}

// Test 10
{
    int n = 0;
    int arr[0];
    int arr2[0];
    if (setjmp(buf) == 0) {
        ft_memset(arr, 1, n * sizeof(arr[0]));
        memset(arr2, 1, n * sizeof(arr2[0]));
        for (int i = 0; i < n; i++) {
            compare_results("memset(arr, 1, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
        }
    } else {
        printf("Test %d: %50s - Segmentation Fault\n", ++test, "memset(arr, 1, n)");
        pass = false;
    }
}

    printf("\nFinished test_memset...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_bzero(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_bzero...\n");

    // Test cases for bzero function comparison
    printf("bzero vs ft_bzero:\n");

    // Test 1
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_bzero(str1 + 13, 8 * sizeof(char));
            bzero(str2 + 13, 8 * sizeof(char));
            compare_results("bzero(str1 + 13, 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(str1 + 13, 8)");
            pass = false;
        }
    }

    // Test 2
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_bzero(str1 + 35, 8 * sizeof(char));
            bzero(str2 + 35, 8 * sizeof(char));
            compare_results("bzero(str1 + 35, 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(str1 + 35, 8)");
            pass = false;
        }
    }

    // Test 3
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_bzero(str1, 8 * sizeof(char));
            bzero(str2, 8 * sizeof(char));
            compare_results("bzero(str1, 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(str1, 8)");
            pass = false;
        }
    }

    // Test 4
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_bzero(str1, 0 * sizeof(char));
            bzero(str2, 0 * sizeof(char));
            compare_results("bzero(str1, 0)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(str1, 0)");
            pass = false;
        }
    }

    /* // Test 5
    {
        char str1[50] = "GeeksForGeeks is for programming geeks.";
        char str2[50] = "GeeksForGeeks is for programming geeks.";
        if (setjmp(buf) == 0) {
            ft_bzero(str1 + 50, 8 * sizeof(char));
            bzero(str2 + 50, 8 * sizeof(char));
            compare_results("bzero(str1 + 50, 8)", str1, str2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(str1 + 50, 8)");
            pass = false;
        }
    } */
    
    // Test 6
    {
        int n = 10;
        int arr[n];
        int arr2[n];
        if (setjmp(buf) == 0) {
            ft_bzero(arr, n * sizeof(arr[0]));
            bzero(arr2, n * sizeof(arr2[0]));
            for (int i = 0; i < n; i++) {
                compare_results("bzero(arr, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(arr, n)");
            pass = false;
        }
    }

    // Test 7
    {
        int n = 10;
        int arr[n];
        int arr2[n];
        if (setjmp(buf) == 0) {
            ft_bzero(arr, n * sizeof(arr[0]));
            bzero(arr2, n * sizeof(arr2[0]));
            for (int i = 0; i < n; i++) {
                compare_results("bzero(arr, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(arr, n)");
            pass = false;
        }
    }

    // Test 8
    {
        int n = 5;
        float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        if (setjmp(buf) == 0) {
            ft_bzero(arr, n * sizeof(arr[0]));
            bzero(arr2, n * sizeof(arr2[0]));
            for (int i = 0; i < n; i++) {
                compare_results("bzero(arr, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(arr, n)");
            pass = false;
        }
    }

    // Test 9
    {
        int n = 0;
        int arr[0];
        int arr2[0];
        if (setjmp(buf) == 0) {
            ft_bzero(arr, n * sizeof(arr[0]));
            bzero(arr2, n * sizeof(arr2[0]));
            for (int i = 0; i < n; i++) {
                compare_results("bzero(arr, n)", &arr[i], &arr2[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(arr, n)");
            pass = false;
        }
    }

    // Test 10
    {
        char str1[50] = {};
        char str2[50] = {};
        if (setjmp(buf) == 0) {
            ft_bzero(str1, 8 * sizeof(char));
            bzero(str2, 8 * sizeof(char));
            for (int i = 0; i < sizeof(str1); i++) {
                compare_results("bzero(str1, 8)", &str1[i], &str2[i], 1, ++test, &pass, 2, 0);
            }
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(str1, 8)");
            pass = false;
        }
    }

    /* // Test 11 - should give segfault
    {
        if (setjmp(buf) == 0) {
            ft_bzero(NULL, 8 * sizeof(char));
            bzero(NULL, 8 * sizeof(char));
            // compare_results("bzero(NULL, 8)", NULL, NULL, 1, ++test, &pass, 1, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "bzero(NULL, 8)");
            pass = false;
        }
    } */

    printf("\nFinished test_bzero...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_memcpy(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_memcpy...\n");

    // Test cases for memcpy function comparison
    printf("memcpy vs ft_memcpy:\n");

    // Test 1
    {
        char dest[10], dest2[10], src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 5);
            memcpy(dest2, src, 5);
            compare_results("memcpy(dest, src, 5)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 5)");
            pass = false;
        }
    }

    // Test 2
    {
        char dest[10], dest2[10], src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 2);
            memcpy(dest2, src, 2);
            compare_results("memcpy(dest, src, 2)", dest, dest2, 1, ++test, &pass, 3, 2);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 2)");
            pass = false;
        }
    }

    // Test 3
    {
        char dest[3], dest2[3], src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 4);
            memcpy(dest2, src, 4);
            compare_results("memcpy(dest, src, 4)", dest, dest2, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 4)");
            pass = false;
        }
    }

    // Test 4
    {
        char dest[3], dest2[3], src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 5);
            memcpy(dest2, src, 5);
            compare_results("memcpy(dest, src, 5)", dest, dest2, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 5)");
            pass = false;
        }
    }

    // Test 5
    {
        char dest[3], dest2[3], src[1] = "";
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 1);
            memcpy(dest2, src, 1);
            compare_results("memcpy(dest, src, 1)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 1)");
            pass = false;
        }
    }

    // Test 6
    {
        char dest[3], dest2[3], src[1] = "";
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 3);
            memcpy(dest2, src, 3);
            compare_results("memcpy(dest, src, 3)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 3)");
            pass = false;
        }
    }

    // Test 7 - Zero-Length Copy
    {
        char dest[10] = "XXXXXXXXX", dest2[10] = "XXXXXXXXX", src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 0);
            memcpy(dest2, src, 0);
            compare_results("memcpy(dest, src, 0)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 0)");
            pass = false;
        }
    }

    // Test 8 - Overlapping Buffers
    {
        char src_dest1[20] = "HelloWorld!", src_dest2[20] = "HelloWorld!";
        if (setjmp(buf) == 0) {
            ft_memcpy(src_dest1 + 2, src_dest1, 5);
            memcpy(src_dest2 + 2, src_dest2, 5);
            compare_results("memcpy(src_dest1 + 2, src_dest1, 5)", src_dest1, src_dest2, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(src_dest1 + 2, src_dest1, 5)");
            pass = false;
        }
    }

    // Test 9 - Overlapping Buffers
    {
        char src_dest1[20] = "HelloWorld!", src_dest2[20] = "HelloWorld!";
        if (setjmp(buf) == 0) {
            ft_memcpy(src_dest1 + 7, src_dest1, 5);
            memcpy(src_dest2 + 7, src_dest2, 5);
            compare_results("memcpy(src_dest1 + 7, src_dest1, 5)", src_dest1, src_dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(src_dest1 + 7, src_dest1, 5)");
            pass = false;
        }
    }

    // Test 10 - Overlapping Buffers
    {
        char src_dest1[20] = "HelloWorld!", src_dest2[20] = "HelloWorld!";
        if (setjmp(buf) == 0) {
            ft_memcpy(src_dest1, src_dest1 + 4, 6);
            memcpy(src_dest2, src_dest2 + 4, 6);
            compare_results("memcpy(src_dest1, src_dest1 + 4, 6)", src_dest1, src_dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(src_dest1, src_dest1 + 4, 6)");
            pass = false;
        }
    }

    // Test 13 - Large Buffers
    {
        char src[1000], dest[1000], dest2[1000];
        for (int i = 0; i < 999; i++) {
            src[i] = 'A' + (i % 26);
        }
        src[999] = '\0';
        if (setjmp(buf) == 0) {
            ft_memcpy(dest, src, 1000);
            memcpy(dest2, src, 1000);
            compare_results("memcpy(dest, src, 1000)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memcpy(dest, src, 1000)");
            pass = false;
        }
    }

    printf("\nFinished test_memcpy...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_memmove(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_memmove...\n");

    // Test cases for memmove function comparison
    printf("memmove vs ft_memmove:\n");

    // Test 1
    {
        char dest[10], dest2[10], src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memmove(dest, src, 5);
            memmove(dest2, src, 5);
            compare_results("memmove(dest, src, 5)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(dest, src, 5)");
            pass = false;
        }
    }

    // Test 2
    {
        char dest[10], dest2[10], src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memmove(dest, src, 2);
            memmove(dest2, src, 2);
            compare_results("memmove(dest, src, 2)", dest, dest2, 1, ++test, &pass, 3, 2);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(dest, src, 2)");
            pass = false;
        }
    }

    // Test 3
    {
        char dest[3], dest2[3], src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memmove(dest, src, 4);
            memmove(dest2, src, 4);
            compare_results("memmove(dest, src, 4)", dest, dest2, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(dest, src, 4)");
            pass = false;
        }
    }

    // Test 4
    {
        char dest[3], dest2[3], src[1] = "";
        if (setjmp(buf) == 0) {
            ft_memmove(dest, src, 1);
            memmove(dest2, src, 1);
            compare_results("memmove(dest, src, 1)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(dest, src, 1)");
            pass = false;
        }
    }

    // Test 5 - Zero-Length Copy
    {
        char dest[10] = "XXXXXXXXX", dest2[10] = "XXXXXXXXX", src[10] = "Abcd";
        if (setjmp(buf) == 0) {
            ft_memmove(dest, src, 0);
            memmove(dest2, src, 0);
            compare_results("memmove(dest, src, 0)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(dest, src, 0)");
            pass = false;
        }
    }

    // Test 6 - Overlapping Buffers
    {
        char src_dest1[20] = "HelloWorld!", src_dest2[20] = "HelloWorld!";
        if (setjmp(buf) == 0) {
            ft_memmove(src_dest1 + 2, src_dest1, 5);
            memmove(src_dest2 + 2, src_dest2, 5);
            compare_results("memmove(src_dest1 + 2, src_dest1, 5)", src_dest1, src_dest2, 3, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(src_dest1 + 2, src_dest1, 5)");
            pass = false;
        }
    }

    // Test 7 - Overlapping Buffers
    {
        char src_dest1[20] = "HelloWorld!", src_dest2[20] = "HelloWorld!";
        if (setjmp(buf) == 0) {
            ft_memmove(src_dest1 + 7, src_dest1, 5);
            memmove(src_dest2 + 7, src_dest2, 5);
            compare_results("memmove(src_dest1 + 7, src_dest1, 5)", src_dest1, src_dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(src_dest1 + 7, src_dest1, 5)");
            pass = false;
        }
    }

    // Test 8 - Overlapping Buffers
    {
        char src_dest1[20] = "HelloWorld!", src_dest2[20] = "HelloWorld!";
        if (setjmp(buf) == 0) {
            ft_memmove(src_dest1, src_dest1 + 4, 6);
            memmove(src_dest2, src_dest2 + 4, 6);
            compare_results("memmove(src_dest1, src_dest1 + 4, 6)", src_dest1, src_dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(src_dest1, src_dest1 + 4, 6)");
            pass = false;
        }
    }

    // Test 9 - Same Source and Destination
    {
        char src_dest1[20] = "HelloWorld!", src_dest2[20] = "HelloWorld!";
        if (setjmp(buf) == 0) {
            ft_memmove(src_dest1, src_dest1, 6);
            memmove(src_dest2, src_dest2, 6);
            compare_results("memmove(src_dest1, src_dest1, 6)", src_dest1, src_dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(src_dest1, src_dest1, 6)");
            pass = false;
        }
    }

    // Test 10 - Large Buffers
    {
        char src[1000], dest[1000], dest2[1000];
        for (int i = 0; i < 999; i++) {
            src[i] = 'A' + (i % 26);
        }
        src[999] = '\0';
        if (setjmp(buf) == 0) {
            ft_memmove(dest, src, 1000);
            memmove(dest2, src, 1000);
            compare_results("memmove(dest, src, 1000)", dest, dest2, 1, ++test, &pass, 2, 0);
        } else {
            printf("Test %d: %50s - Segmentation Fault\n", ++test, "memmove(dest, src, 1000)");
            pass = false;
        }
    }

    printf("\nFinished test_memmove...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_memchr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    char c = 'a';
    printf("\nRunning test_memchr...\n");

    // Test cases for memchr function comparison
    printf("memchr vs ft_memchr:\n");

    // Test 1
    {
        const char *str = "abcd";
        const char *resulta = (char *)memchr(str, c, 4);
        const char *resultb = (char *)ft_memchr(str, c, 4);
        compare_results("memchr('abcd', 'a', 4)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 2
    {
        const char *str = "abcd";
        const char *resulta = (char *)memchr(str, c, 5);
        const char *resultb = (char *)ft_memchr(str, c, 5);
        compare_results("memchr('abcd', 'a', 5)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 3
    {
        const char *str = "abcd";
        const char *resulta = (char *)memchr(str, c, 6);
        const char *resultb = (char *)ft_memchr(str, c, 6);
        compare_results("memchr('abcd', 'a', 6)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 4
    {
        const char *str = "abcd";
        const char *resulta = (char *)memchr(str, c, 3);
        const char *resultb = (char *)ft_memchr(str, c, 3);
        compare_results("memchr('abcd', 'a', 3)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 5
    {
        const char *str = "abcd";
        const char *resulta = (char *)memchr(str, c, 1);
        const char *resultb = (char *)ft_memchr(str, c, 1);
        compare_results("memchr('abcd', 'a', 1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 6
    {
        const char *str = "bcd";
        const char *resulta = (char *)memchr(str, c, 3);
        const char *resultb = (char *)ft_memchr(str, c, 3);
        compare_results("memchr('bcd', 'a', 3)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 7
    {
        const char *str = "bcda";
        const char *resulta = (char *)memchr(str, c, 4);
        const char *resultb = (char *)ft_memchr(str, c, 4);
        compare_results("memchr('bcda', 'a', 4)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 8
    {
        const char *str = "a";
        const char *resulta = (char *)memchr(str, c, 1);
        const char *resultb = (char *)ft_memchr(str, c, 1);
        compare_results("memchr('a', 'a', 1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 9
    {
        const char *str = "";
        const char *resulta = (char *)memchr(str, c, 1);
        const char *resultb = (char *)ft_memchr(str, c, 1);
        compare_results("memchr('', 'a', 1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 10
    {
        const char *str = "abacd";
        const char *resulta = (char *)memchr(str, c, 5);
        const char *resultb = (char *)ft_memchr(str, c, 5);
        compare_results("memchr('abacd', 'a', 5)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 11
    {
        const char *str = "abacda";
        const char *resulta = (char *)memchr(str, c, 6);
        const char *resultb = (char *)ft_memchr(str, c, 6);
        compare_results("memchr('abacda', 'a', 6)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 12
    {
        const char *str = "abacda";
        const char *resulta = (char *)memchr(str, '\0', 7);
        const char *resultb = (char *)ft_memchr(str, '\0', 7);
        compare_results("memchr('abacda', '\\0', 7)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 13
    {
        const char *str = "";
        const char *resulta = (char *)memchr(str, '\0', 1);
        const char *resultb = (char *)ft_memchr(str, '\0', 1);
        compare_results("memchr('', '\\0', 1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 14
    {
        const char *str = "aaaaa";
        const char *resulta = (char *)memchr(str, c, 5);
        const char *resultb = (char *)ft_memchr(str, c, 5);
        compare_results("memchr('aaaaa', 'a', 5)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 15
    {
        const char *str = "longer string of characters";
        const char *resulta = (char *)memchr(str, c, 27);
        const char *resultb = (char *)ft_memchr(str, c, 27);
        compare_results("memchr('longer string of characters', 'a', 27)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 16 - Argument is 0 Error
    {
        const char *str = "abcd";
        const char *resulta = (char *)memchr(str, c, 0);
        const char *resultb = (char *)ft_memchr(str, c, 0);
        compare_results("memchr('abcd', 'a', 0)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    /* // Test 17 - segfault Error
    {
        const char *resulta = (char *)memchr(NULL, c, 1);
        const char *resultb = (char *)ft_memchr(NULL, c, 1);
        compare_results("memchr(NULL, 'a', 1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    } */

    printf("\nFinished test_memchr...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_memcmp(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_memcmp...\n");

    // Test cases for memcmp function comparison
    printf("memcmp vs ft_memcmp:\n");

    // Test 1
    {
        int resulta = memcmp("abcd", "abcy", 4);
        int resultb = ft_memcmp("abcd", "abcy", 4);
        compare_results("memcmp('abcd', 'abcy', 4)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 2
    {
        int resulta = memcmp("abcd", "abcy", 3);
        int resultb = ft_memcmp("abcd", "abcy", 3);
        compare_results("memcmp('abcd', 'abcy', 3)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 3
    {
        int resulta = memcmp("abcd", "abcy", 5);
        int resultb = ft_memcmp("abcd", "abcy", 5);
        compare_results("memcmp('abcd', 'abcy', 5)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 4
    {
        int resulta = memcmp("abcd", "abcy", 6);
        int resultb = ft_memcmp("abcd", "abcy", 6);
        compare_results("memcmp('abcd', 'abcy', 6)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 5
    {
        int resulta = memcmp("abcd", "abcy", 8);
        int resultb = ft_memcmp("abcd", "abcy", 8);
        compare_results("memcmp('abcd', 'abcy', 8)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 6
    {
        char a[8] = {'a', 'b', 'c', 'd'};
        char a2[8] = {'a', 'b', 'c', 'y'};
        int resulta = memcmp(a, a2, 4);
        int resultb = ft_memcmp(a, a2, 4);
        compare_results("memcmp(a, a2, 4)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 7
    {
        int resulta = memcmp("abcd", "abcd", 4);
        int resultb = ft_memcmp("abcd", "abcd", 4);
        compare_results("memcmp('abcd', 'abcd', 4)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 8
    {
        int resulta = memcmp("abcd", "abcd", 6);
        int resultb = ft_memcmp("abcd", "abcd", 6);
        compare_results("memcmp('abcd', 'abcd', 6)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 9
    {
        int resulta = memcmp("a", "a", 1);
        int resultb = ft_memcmp("a", "a", 1);
        compare_results("memcmp('a', 'a', 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 10
    {
        int resulta = memcmp("zex", "rex", 3);
        int resultb = ft_memcmp("zex", "rex", 3);
        compare_results("memcmp('zex', 'rex', 3)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 11
    {
        int resulta = memcmp("tour", "tourin", 6);
        int resultb = ft_memcmp("tour", "tourin", 6);
        compare_results("memcmp('tour', 'tourin', 6)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 12
    {
        int resulta = memcmp("tour", "tourin", 5);
        int resultb = ft_memcmp("tour", "tourin", 5);
        compare_results("memcmp('tour', 'tourin', 5)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 13
    {
        int resulta = memcmp("a", "a", 0);
        int resultb = ft_memcmp("a", "a", 0);
        compare_results("memcmp('a', 'a', 0)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 14
    {
        int resulta = memcmp("", "a", 1);
        int resultb = ft_memcmp("", "a", 1);
        compare_results("memcmp('', 'a', 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 15
    {
        int resulta = memcmp("a", "", 1);
        int resultb = ft_memcmp("a", "", 1);
        compare_results("memcmp('a', '', 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 16
    {
        int resulta = memcmp("a", "", 2);
        int resultb = ft_memcmp("a", "", 2);
        compare_results("memcmp('a', '', 2)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }

    // Test 17 - null pointers should give a null error
    /*
    {
        int resulta = memcmp(NULL, NULL, 1);
        int resultb = ft_memcmp(NULL, NULL, 1);
        compare_results("memcmp(NULL, NULL, 1)", &resulta, &resultb, 2, ++test, &pass, 1, 0);
    }
    */

    printf("\nFinished test_memcmp...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_atoi(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_atoi...\n");

    // Test cases for atoi function comparison
    printf("atoi vs ft_atoi:\n");

    // Test 1
    {
        int resulta = atoi("0");
        int resultb = ft_atoi("0");
        compare_results("atoi('0')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 2
    {
        int resulta = atoi("00");
        int resultb = ft_atoi("00");
        compare_results("atoi('00')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 3
    {
        int resulta = atoi("001");
        int resultb = ft_atoi("001");
        compare_results("atoi('001')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 4
    {
        int resulta = atoi("002");
        int resultb = ft_atoi("002");
        compare_results("atoi('002')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 5
    {
        int resulta = atoi("010");
        int resultb = ft_atoi("010");
        compare_results("atoi('010')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 6
    {
        int resulta = atoi("000001");
        int resultb = ft_atoi("000001");
        compare_results("atoi('000001')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 7
    {
        int resulta = atoi("1");
        int resultb = ft_atoi("1");
        compare_results("atoi('1')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 8
    {
        int resulta = atoi("-3");
        int resultb = ft_atoi("-3");
        compare_results("atoi('-3')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 9
    {
        int resulta = atoi("50");
        int resultb = ft_atoi("50");
        compare_results("atoi('50')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 10
    {
        int resulta = atoi("2147483647");
        int resultb = ft_atoi("2147483647");
        compare_results("atoi('2147483647')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 11
    {
        int resulta = atoi("-2147483648");
        int resultb = ft_atoi("-2147483648");
        compare_results("atoi('-2147483648')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 12
    {
        int resulta = atoi("2147483648");
        int resultb = ft_atoi("2147483648");
        compare_results("atoi('2147483648')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 13
    {
        int resulta = atoi("2147483647000");
        int resultb = ft_atoi("2147483647000");
        compare_results("atoi('2147483647000')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 14
    {
        int resulta = atoi("2147483647000000");
        int resultb = ft_atoi("2147483647000000");
        compare_results("atoi('2147483647000000')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 15
    {
        int resulta = atoi("abc");
        int resultb = ft_atoi("abc");
        compare_results("atoi('abc')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 16
    {
        int resulta = atoi("52ab");
        int resultb = ft_atoi("52ab");
        compare_results("atoi('52ab')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 17
    {
        int resulta = atoi("ab43");
        int resultb = ft_atoi("ab43");
        compare_results("atoi('ab43')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 18
    {
        int resulta = atoi("ab43qw");
        int resultb = ft_atoi("ab43qw");
        compare_results("atoi('ab43qw')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 19
    {
        int resulta = atoi("     \t \v \f \r   \n---+--+1234ab567");
        int resultb = ft_atoi("  \t \v \f \r   \n---+--+1234ab567");
        compare_results("atoi('  \\t \\v \\f \\r   \\n---+--+1234ab567')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 20
    {
        int resulta = atoi("----23");
        int resultb = ft_atoi("----23");
        compare_results("atoi('----23')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 21
    {
        int resulta = atoi("----ab23");
        int resultb = ft_atoi("----ab23");
        compare_results("atoi('----ab23')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 22
    {
        int resulta = atoi("----ab23ab");
        int resultb = ft_atoi("----ab23ab");
        compare_results("atoi('----ab23ab')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 23
    {
        int resulta = atoi("-");
        int resultb = ft_atoi("-");
        compare_results("atoi('-')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 24
    {
        int resulta = atoi("+1");
        int resultb = ft_atoi("+1");
        compare_results("atoi('+1')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 25
    {
        int resulta = atoi("++1");
        int resultb = ft_atoi("++1");
        compare_results("atoi('++1')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 26
    {
        int resulta = atoi("--1");
        int resultb = ft_atoi("--1");
        compare_results("atoi('--1')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 27
    {
        int resulta = atoi("a");
        int resultb = ft_atoi("a");
        compare_results("atoi('a')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 28
    {
        int resulta = atoi(" ");
        int resultb = ft_atoi(" ");
        compare_results("atoi(' ')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 29
    {
        int resulta = atoi(" 12");
        int resultb = ft_atoi(" 12");
        compare_results("atoi(' 12')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

        // Test 30
    {
        int resulta = atoi("  12");
        int resultb = ft_atoi("  12");
        compare_results("atoi('  12')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 31
    {
        int resulta = atoi("    -12");
        int resultb = ft_atoi("    -12");
        compare_results("atoi('    -12')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 32
    {
        int resulta = atoi("-    12");
        int resultb = ft_atoi("-    12");
        compare_results("atoi('-    12')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 33
    {
        int resulta = atoi(" -    12");
        int resultb = ft_atoi(" -    12");
        compare_results("atoi(' -    12')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 34
    {
        int resulta = atoi("    +12");
        int resultb = ft_atoi("    +12");
        compare_results("atoi('    +12')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 35
    {
        int resulta = atoi("    +12a");
        int resultb = ft_atoi("    +12a");
        compare_results("atoi('    +12a')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 36
    {
        int resulta = atoi("    +12 ");
        int resultb = ft_atoi("    +12 ");
        compare_results("atoi('    +12 ')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 37
    {
        int resulta = atoi("    +0012 ");
        int resultb = ft_atoi("    +0012 ");
        compare_results("atoi('    +0012 ')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 38
    {
        int resulta = atoi("\t\n\r\v\f  469 \n");
        int resultb = ft_atoi("\t\n\r\v\f  469 \n");
        compare_results("atoi('\\t\\n\\r\\v\\f  469 \\n')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    // Test 39
    {
        int resulta = atoi("\n\n\n  -46\b9 \n5d6");
        int resultb = ft_atoi("\n\n\n  -46\b9 \n5d6");
        compare_results("atoi('\\n\\n\\n  -46\\b9 \\n5d6')", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    }

    /* // Test 40 - segfault
    {
        int resulta = atoi(NULL);
        int resultb = ft_atoi(NULL);
        compare_results("atoi(NULL)", &resulta, &resultb, 1, ++test, &pass, 1, 0);
    } */

    printf("\nFinished test_atoi...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strdup(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_strdup...\n");

    // Test cases for strdup function comparison
    printf("strdup vs ft_strdup:\n");

    // Test 1
    {
        char *source = "abcd";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('abcd')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 2
    {
        char *source = " ";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup(' ')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 3
    {
        char *source = "";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 4
    {
        char *source = "y";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('y')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 5
    {
        char *source = "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 6
    {
        char *source = "    ";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('    ')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 7
    {
        char *source = "\n\n\n";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('\\n\\n\\n')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 8
    {
        char *source = "\0\0\0";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('\\0\\0\\0')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 9
    {
        char *source = "\0abc";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('\\0abc')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 10
    {
        char *source = "This is a diverse $1ring     ";
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('This is a diverse $1ring     ')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 11
    {
        char *source = "こんにちは世界"; // "Hello, World" in Japanese
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup('こんにちは世界')", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }

    // Test 12 - Large string 1M
    
    /* {
        size_t len = 1000000; // 1 million characters
        char *source = malloc(len + 1);
        memset(source, 'a', len);
        source[len] = '\0';
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup(Large string 1M)", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
        free(source);
    } */
   

    /* //Test 13 - Null source should give a null error
    {
        char *source = NULL;
        char *resulta = strdup(source);
        char *resultb = ft_strdup(source);
        compare_results("strdup(NULL)", resulta, resultb, 1, ++test, &pass, 2, 0);
        free(resulta);
        free(resultb);
    }  */


    printf("\nFinished test_strdup...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_calloc(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_calloc...\n");

    // Test cases for calloc function comparison
    printf("calloc vs ft_calloc:\n");

    // Test 1
    {
        size_t n = 0;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(0 chars)", resulta, resultb, 3, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    // Test 2
    {
        size_t n = 5;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(5 chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    // Test 3
    {
        size_t n = 5;
        int *resulta = (int *)calloc(n, sizeof(int));
        int *resultb = (int *)ft_calloc(n, sizeof(int));
        if (resulta != NULL && resultb != NULL) {
            for (size_t i = 0; i < n; i++) {
                compare_results("calloc(5 ints)", &resulta[i], &resultb[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            compare_results("calloc(5 ints)", (char *)&resulta, (char *)&resultb, 1, ++test, &pass, 1, 0);
        }
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    // Test 4
    {
        size_t n = SIZE_MAX;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(SIZE_MAX chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    } //

    // Test 4
    {
        size_t n = SIZE_MAX/3;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(SIZE_MAX/3 chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    } //segfault

    // Test 4
    {
        size_t n = SIZE_MAX - 1;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(SIZE_MAX - 1 chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    } //segfault

    // Test 5
    {
        size_t n = SIZE_MAX + 1;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(SIZE_MAX + 1 chars)", resulta, resultb, 3, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    // Test 6
    {
        size_t n = SIZE_MAX;
        int *resulta = (int *)calloc(n, sizeof(int));
        int *resultb = (int *)ft_calloc(n, sizeof(int));
        if (resulta != NULL && resultb != NULL) {
            for (size_t i = 0; i < n; i++) {
                compare_results("calloc(SIZE_MAX ints)", &resulta[i], &resultb[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            compare_results("calloc(SIZE_MAX ints)", (char *)&resulta, (char *)&resultb, 1, ++test, &pass, 1, 0);
        }
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    

    // Test 7
    {
        size_t n = SIZE_MAX / 3;
        int *resulta = (int *)calloc(n, sizeof(int));
        int *resultb = (int *)ft_calloc(n, sizeof(int));
        if (resulta != NULL && resultb != NULL) {
            for (size_t i = 0; i < n; i++) {
                compare_results("calloc(SIZE_MAX/3 ints)", &resulta[i], &resultb[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            compare_results("calloc(SIZE_MAX/3 ints)", (char *)&resulta, (char *)&resultb, 1, ++test, &pass, 1, 0);
        }
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    // Test 8
    {
        size_t n = SIZE_MAX / 2;
        int *resulta = (int *)calloc(n, sizeof(int));
        int *resultb = (int *)ft_calloc(n, sizeof(int));
        if (resulta != NULL && resultb != NULL) {
            for (size_t i = 0; i < n; i++) {
                compare_results("calloc(SIZE_MAX/2 ints)", &resulta[i], &resultb[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            compare_results("calloc(SIZE_MAX/2 ints)", (char *)&resulta, (char *)&resultb, 1, ++test, &pass, 1, 0);
        }
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    

    // Test 9
    {
        size_t n = SIZE_MAX / 2;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(SIZE_MAX/2 chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

    // Test 10
    {
        size_t n = SIZE_MAX / 2 + 56;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(SIZE_MAX/2+56 chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

    // Test 11
    {
        size_t n = SIZE_MAX / 2 - 56;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(SIZE_MAX/2-56 chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

    // Test 12
    {
        size_t n = 0;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(0 chars)", resulta, resultb, 3, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

    // Test 13
    {
        size_t n = 0;
        char *resulta = (char *)calloc(n, 0);
        char *resultb = (char *)ft_calloc(n, 0);
        compare_results("calloc(0 chars)", resulta, resultb, 3, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

        // Test 14
    {
        size_t n = 5;
        char *resulta = (char *)calloc(n, 0);
        char *resultb = (char *)ft_calloc(n, 0);
        compare_results("calloc(0 chars)", resulta, resultb, 3, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

    // Test 15
    {
        size_t n = 3;
        double *resulta = (double *)calloc(n, sizeof(double));
        double *resultb = (double *)ft_calloc(n, sizeof(double));
        if (resulta != NULL && resultb != NULL) {
            for (size_t i = 0; i < n; i++) {
                compare_results("calloc(3 doubles)", &resulta[i], &resultb[i], 1, ++test, &pass, 1, 0);
            }
        } else {
            compare_results("calloc(3 doubles)", (char *)&resulta, (char *)&resultb, 1, ++test, &pass, 1, 0);
        }
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

    // Test 16
    {
        size_t n = (size_t)-5;
        char *resulta = (char *)calloc(n, sizeof(char));
        char *resultb = (char *)ft_calloc(n, sizeof(char));
        compare_results("calloc(-5 chars)", resulta, resultb, 1, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }
    

    // Test 17
    {
        size_t n = 10;
        char *resulta = (char *)calloc(n, 0);
        char *resultb = (char *)ft_calloc(n, 0);
        compare_results("calloc(10 chars, 0 size)", resulta, resultb, 3, ++test, &pass, 2, 0);
        if (resulta != NULL) free(resulta);
        if (resultb != NULL) free(resultb);
    }

    printf("\nFinished test_calloc...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_substr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_substr...\n");

    // Test cases for substr function comparison
    printf("expected result vs. ft_substr:\n");

    // Test 1
    {
        char st[] = "What the heck";
        int s = 9;
        size_t l = 5;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 9, 5)", "heck", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 2
    {
        char st[] = "What the heck";
        int s = 9;
        size_t l = 4;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 9, 4)", "heck", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 3
    {
        char st[] = "What the heck";
        int s = 9;
        size_t l = 3;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 9, 3)", "hec", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 4
    {
        char st[] = "What the heck";
        int s = 9;
        size_t l = 1;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 9, 1)", "h", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 5
    {
        char st[] = "What the heck";
        int s = 9;
        size_t l = 0;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 9, 0)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 6
    {
        char st[] = "What the heck";
        int s = 0;
        size_t l = 0;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 0, 0)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 7
    {
        char st[] = "What the heck";
        int s = 0;
        size_t l = 7;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 0, 7)", "What th", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 8
    {
        char st[] = "What the heck";
        int s = 10;
        size_t l = 7;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 10, 7)", "eck", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 9
    {
        char st[] = "What the heck";
        int s = 13;
        size_t l = 5;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 13, 5)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 10
    {
        char st[] = "What the heck";
        int s = 1;
        size_t l = 15;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 1, 15)", "hat the heck", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    /* // Test 11 - segfault
    {
        char st[] = "null";
        int s = 1;
        size_t l = 15;
        char *resultb = ft_substr(NULL, s, l);
        compare_results("substr(NULL, 1, 15)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    } */

    // Test 12
    {
        char st[] = "What the heck";
        int s = -1;
        size_t l = -2;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', -1, -2)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 13
    {
        char st[] = "What the heck";
        int s = -1;
        size_t l = 2;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', -1, 2)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 14
    {
        char st[] = "\\0";
        int s = 0;
        size_t l = 1;
        char *resultb = ft_substr("\0", s, l);
        compare_results("substr('\\0', 0, 1)", "\0", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 15
    {
        char st[] = "";
        int s = 0;
        size_t l = 5;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('', 0, 5)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 16
    {
        char st[] = "What the heck";
        int s = 20;
        size_t l = 5;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('What the heck', 20, 5)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 17
    {
        char st[] = "Hello\nWorld\t!";
        int s = 6;
        size_t l = 6;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('Hello\\nWorld\\t!', 6, 6)", "World\t", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 18
    {
        char st[] = "Hello\nWorld\t!";
        int s = 400;
        size_t l = 20;
        char *resultb = ft_substr(st, s, l);
        compare_results("substr('Hello\\nWorld\\t!', 400, 20)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    printf("\nFinished test_substr...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[*i].passed = false; 
        *grandpass = false;
    }
    (*i)++;
}

void run_test_strjoin(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_strjoin...\n");

    // Test cases for strjoin function comparison
    printf("expected result vs. ft_strjoin:\n");

    // Test 1
    {
        const char s1[] = "Hello ";
        const char s2[] = "World!";
        char *resultb = ft_strjoin(s1, s2);
        compare_results("strjoin('Hello ', 'World!')", "Hello World!", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 2
    {
        const char s1[] = "Hello ";
        const char s2[] = "";
        char *resultb = ft_strjoin(s1, s2);
        compare_results("strjoin('Hello ', '')", "Hello ", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 3
    {
        const char s1[] = "";
        const char s2[] = "World";
        char *resultb = ft_strjoin(s1, s2);
        compare_results("strjoin('', 'World')", "World", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 4
    {
        const char s1[] = "";
        const char s2[] = "";
        char *resultb = ft_strjoin(s1, s2);
        compare_results("strjoin('', '')", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 5
    {
        const char s1[] = "\0";
        const char s2[] = "\0";
        char *resultb = ft_strjoin(s1, s2);
        compare_results("strjoin('\\0', '\\0')", "\0\0", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    /* // Test 6 - segfault
    {
        const char s1[] = "null";
        const char s2[] = "null";
        char *resultb = ft_strjoin(NULL, NULL);
        compare_results("strjoin(NULL, NULL)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }  */

    // Test 7
    {
        const char s1[] = "Hello\n";
        const char s2[] = "\tWorld!";
        char *resultb = ft_strjoin(s1, s2);
        compare_results("strjoin('Hello\\n', '\\tWorld!')", "Hello\n\tWorld!", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 8
    {
        const char s1[] = "This is a very long string. ";
        const char s2[] = "Another very long string to join with the first one.";
        char *resultb = ft_strjoin(s1, s2);
        compare_results("strjoin('This is a very long string. ', 'Another very long string to join with the first one.')", 
                        "This is a very long string. Another very long string to join with the first one.", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    /* // Test 9 - segfault
    {
        char s1[2147483647]; 
        char s2[2147483647];
        for (unsigned long i = 0; i < 2147483647; i++) {
            s1[i] = 'a'; 
            s2[i] = 'a';
        }
        char *resultb = ft_strjoin((const char *)s1, (const char *)s2);
        compare_results("strjoin(very long strings)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    } */

    /* // Test 10
    {
        char s1[2147483648]; 
        char s2[2147483648];
        for (unsigned long i = 0; i < 2147483648; i++) {
            s1[i] = 'a'; 
            s2[i] = 'a';
        }
        char *resultb = ft_strjoin((const char *)s1, (const char *)s2);
        compare_results("strjoin(very long strings)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    } */

    printf("\nFinished test_strjoin...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_strtrim(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_strtrim...\n");

    // Test cases for strtrim function comparison
    printf("expected result vs. ft_strtrim:\n");

    // Test 1
    {
        const char *s = "abrakadabra";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('abrakadabra', 'abc')", "rakadabr", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 2
    {
        const char *s = "tarakan";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('tarakan', 'abc')", "tarakan", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 3
    {
        const char *s = "cabac";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('cabac', 'abc')", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 4
    {
        const char *s = "cyabac";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('cyabac', 'abc')", "y", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 5
    {
        const char *s = "yabac";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('yabac', 'abc')", "y", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 6
    {
        const char *s = "bbcferro";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('bbcferro', 'abc')", "ferro", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 7
    {
        const char *s = "aaaaaaa";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('aaaaaaa', 'abc')", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 8
    {
        const char *s = "c";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('c', 'abc')", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 9
    {
        const char *s = "$";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('$', 'abc')", "$", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 10
    {
        const char *s = "";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('', 'abc')", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 11
    {
        const char *s = "dog";
        const char *set = "";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('dog', '')", "dog", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 12
    {
        const char *s = "";
        const char *set = "";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('', '')", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 13
    {
        const char *s = "AaAbBcC";
        const char *set = "aAbB";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('AaAbBcC', 'aAbB')", "cC", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 14
    {
        const char *s = "AaAbBcC";
        const char *set = "abc";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('AaAbBcC', 'abc')", "AaAbBcC", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 15
    {
        const char *s = "!@#$%^&*()test!";
        const char *set = "!@#$";
        char *resultb = ft_strtrim(s, set);
        compare_results("strtrim('!@#$%^&*()test!', '!@#$')", "%^&*()test", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    /* // Test 16 - segfault
    {
        const char *s = "null";
        const char *set = "null";
        char *resultb = ft_strtrim(NULL, NULL);
        compare_results("strtrim(NULL, NULL)", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    } */

    printf("\nFinished test_strtrim...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_split(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_split...\n");

    // Test cases for split function comparison
    printf("expected result vs. ft_split:\n");

    // Test 1
    {
        const char *s = "   abc def gh i jk";
        char ch = ' '; int i = 0;
        char *expres[] = {"abc", "def", "gh", "i", "jk", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('   abc def gh i jk')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('   abc def gh i jk')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('   abc def gh i jk') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

    // Test 2
    {
        const char *s = "abc def gh i jk";
        char ch = ' '; int i = 0;
        char *expres[] = {"abc", "def", "gh", "i", "jk", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('abc def gh i jk')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('abc def gh i jk')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('abc def gh i jk') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

    // Test 3
    {
        const char *s = "abc def gh i jk   ";
        char ch = ' '; int i = 0;
        char *expres[] = {"abc", "def", "gh", "i", "jk", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('abc def gh i jk   ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('abc def gh i jk   ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('abc def gh i jk   ') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

    // Test 4
    {
        const char *s = "   abc def gh i jk   ";
        char ch = ' '; int i = 0;
        char *expres[] = {"abc", "def", "gh", "i", "jk", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('   abc def gh i jk   ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('   abc def gh i jk   ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('   abc def gh i jk   ') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

    // Test 5
    {
        const char *s = "   abc   def gh      i jk   ";
        char ch = ' '; int i = 0;
        char *expres[] = {"abc", "def", "gh", "i", "jk", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('   abc   def gh      i jk   ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('   abc   def gh      i jk   ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('   abc   def gh      i jk   ') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

    // Test 6
    {
        const char *s = "abc:def: ghi:jk:l";
        char ch = ':'; int i = 0;
        char *expres[] = {"abc", "def", " ghi", "jk", "l", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('abc:def: ghi:jk:l')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('abc:def: ghi:jk:l')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('abc:def: ghi:jk:l') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

    // Test 7
    {
        const char *s = "abc:def:ghi:jk:l";
        char ch = ' '; int i = 0;
        char *expres[] = {"abc:def:ghi:jk:l", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('abc:def:ghi:jk:l')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('abc:def:ghi:jk:l')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('abc:def:ghi:jk:l') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

    // Test 8
    {
        const char *s = "abc\ndef\nghi";
        char ch = '\n'; int i = 0;
        char *expres[] = {"abc", "def", "ghi", NULL};
        char **resultb = ft_split(s, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('abc\\ndef\\nghi')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('abc\\ndef\\nghi')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('abc\\ndef\\nghi') - memory not allocated", ++test);
            printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
            pass = false;
        }
    }

// Test 9
{
    const char *s = "abc\0def\0ghi";
    char ch = '\0'; int i = 0;
    char *expres[] = {"abc", "def", "ghi", NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split('abc\\0def\\0ghi')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split('abc\\0def\\0ghi')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split('abc\\0def\\0ghi') - memory not allocated", ++test);
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        pass = false;
    }
}

// Test 10
{
    const char *s = "     ";
    char ch = ' '; int i = 0;
    char *expres[] = {NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split('     ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split('     ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split('     ') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

// Test 11
{
    const char *s = "word";
    char ch = ' '; int i = 0;
    char *expres[] = {"word", NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split('word')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split('word')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split('word') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

// Test 12
{
    const char *s = " ";
    char ch = ' '; int i = 0;
    char *expres[] = {NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split(' ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split(' ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split(' ') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

// Test 13
{
    const char *s = "a";
    char ch = ' '; int i = 0;
    char *expres[] = {"a", NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split('a')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split('a')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split('a') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

// Test 14
{
    const char *s = " ";
    char ch = ' '; int i = 0;
    char *expres[] = {NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split(' ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split(' ')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split(' ') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

// Test 15
{
    const char *s = "";
    char ch = ' '; int i = 0;
    char *expres[] = {NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split('')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split('')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split('') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

// Test 16
{
    const char *s = "";
    char ch = '\0'; int i = 0;
    char *expres[] = {NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split('')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split('')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split('') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

// Test 17
{
    const char *s = "a";
    char ch = '\0'; int i = 0;
    char *expres[] = {"a", NULL};
    char **resultb = ft_split(s, ch);
    if (resultb != NULL) {
        for (i = 0; resultb[i] != NULL; i++) {
            compare_results("split('a')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        }
        compare_results("split('a')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
        for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
        free(resultb);
    } else {
        printf("Test %d: split('a') - memory not allocated", ++test);
        printf(" - ");
            printf(RED "FAIL");
            printf(RESET" \n");
        pass = false;
    }
}

    /* // Test 18
    {
        const char *s = "null";
        char ch = ' '; int i = 0;
        char *expres[] = {NULL};
        char **resultb = ft_split(NULL, ch);
        if (resultb != NULL) {
            for (i = 0; resultb[i] != NULL; i++) {
                compare_results("split('null')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            }
            compare_results("split('null')", expres[i], resultb[i], 1, ++test, &pass, 2, 0);
            for (i = 0; resultb[i] != NULL; i++) free(resultb[i]);
            free(resultb);
        } else {
            printf("Test %d: split('null') - memory not allocated - FAIL\n", ++test);
            pass = false;
        }
    } */ //null error

    printf("\nFinished test_split...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }else {
        printf(RED "FAIL");
        printf(RESET" \n");
    }
    (*i)++;
}

void run_test_itoa(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_itoa...\n");

    // Test cases for itoa function comparison
    printf("expected value vs. ft_itoa:\n");

    // Test 1
    {
        int i = 42;
        char *resultb = ft_itoa(i);
        compare_results("itoa(42)", "42", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 2
    {
        int i = 4;
        char *resultb = ft_itoa(i);
        compare_results("itoa(4)", "4", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 3
    {
        int i = +4;
        char *resultb = ft_itoa(i);
        compare_results("itoa(+4)", "4", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 4
    {
        int i = -1;
        char *resultb = ft_itoa(i);
        compare_results("itoa(-1)", "-1", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 5
    {
        int i = 0;
        char *resultb = ft_itoa(i);
        compare_results("itoa(0)", "0", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 6
    {
        int i = -0;
        char *resultb = ft_itoa(i);
        compare_results("itoa(-0)", "0", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 7
    {
        int i = -0;
        char *resultb = ft_itoa(-0);
        compare_results("itoa(-0 manually)", "0", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 8
    {
        int i = +0;
        char *resultb = ft_itoa(i);
        compare_results("itoa(+0)", "0", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 9
    {
        int i = -155;
        char *resultb = ft_itoa(i);
        compare_results("itoa(-155)", "-155", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 10
    {
        int i = -1234567;
        char *resultb = ft_itoa(i);
        compare_results("itoa(-1234567)", "-1234567", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 11
    {
        int i = -2147483647;
        char *resultb = ft_itoa(i);
        compare_results("itoa(-2147483647)", "-2147483647", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 12
    {
        int i = 2147483646;
        char *resultb = ft_itoa(i);
        compare_results("itoa(2147483646)", "2147483646", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 13
    {
        int i = 2147483647;
        char *resultb = ft_itoa(i);
        compare_results("itoa(2147483647)", "2147483647", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 14
    {
        int i = -2147483648;
        char *resultb = ft_itoa(i);
        compare_results("itoa(-2147483648)", "-2147483648", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 15
    {
        int i = -2147483649;
        char *resultb = ft_itoa(i);
        compare_results("itoa(-2147483649)", "2147483647", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 16
    {
        int i = -2147483649;
        char *resultb = ft_itoa(-2147483649);
        compare_results("itoa(-2147483649 manual)", "2147483647", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 17
    {
        int i = 2147483648;
        char *resultb = ft_itoa(2147483648);
        compare_results("itoa(2147483648 manual)", "-2147483648", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 18
    {
        int i = 'a';
        char *resultb = ft_itoa('a');
        compare_results("itoa('a' manual)", "97", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    printf("\nFinished test_itoa...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_strmapi(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_strmapi...\n");

    // Test cases for strmapi function comparison
    printf("expected result vs. ft_strmapi:\n");

    // Test 1
    {
        const char *s = "random text";
        char *resultb = ft_strmapi(s, f);
        compare_results("strmapi('random text')", "sboepn!ufyu", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 2
    {
        const char *s = "";
        char *resultb = ft_strmapi(s, f);
        compare_results("strmapi('')", "", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 3
    {
        const char *s = "a";
        char *resultb = ft_strmapi(s, f);
        compare_results("strmapi('a')", "b", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 4
    {
        const char *s = "\0";
        char *resultb = ft_strmapi(s, f);
        compare_results("strmapi('\\0')", "\0", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    // Test 5
    {
        const char *s = "\200";
        char *resultb = ft_strmapi(s, f);
        compare_results("strmapi('\\200')", "\201", resultb, 1, ++test, &pass, 2, 0);
        if (resultb != NULL) free(resultb);
    }

    printf("\nFinished test_strmapi...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_striteri(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_striteri...\n");

    // Test cases for striteri function comparison
    printf("expected result vs . ft_striteri:\n");

    // Test 1
    {
        char s[] = "random text";
        char t[] = "random text";
        ft_striteri(t, fi);
        compare_results("striteri('random text')", "sboepn!ufyu", t, 1, ++test, &pass, 2, 0);
    }

    // Test 2
    {
        char s[] = "";
        char t[] = "";
        ft_striteri(t, fi);
        compare_results("striteri('')", "", t, 1, ++test, &pass, 2, 0);
    }

    // Test 3
    {
        char s[] = "a";
        char t[] = "a";
        ft_striteri(t, fi);
        compare_results("striteri('a')", "b", t, 1, ++test, &pass, 2, 0);
    }

    // Test 4
    {
        char s[] = "\0";
        char t[] = "\0";
        ft_striteri(t, fi);
        compare_results("striteri('\\0')", "\0", t, 1, ++test, &pass, 2, 0);
    }

    // Test 5
    {
        char s[] = "\200";
        char t[] = "\200";
        ft_striteri(t, fi);
        compare_results("striteri('\\200')", "\201", t, 1, ++test, &pass, 2, 0);
    }

    printf("\nFinished test_striteri...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    }else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_putchar(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_putchar_fd...\n");

    // Test cases for putchar_fd function comparison
    printf("putchar vs. ft_putchar_fd:\n");

    int saved_stdout = dup(STDOUT_FILENO);

    // Test 1: Basic ASCII character
    {
        char ch = 'a';
        int pipefd[2];
        char resulta[2], resultb[2];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar('a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 2: Out-of-range ASCII value (300)
    {
        char ch = 300;
        int pipefd[2];
        char resulta[2], resultb[2];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar(300)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 3: NULL character ('\0')
    {
        char ch = '\0';
        int pipefd[2];
        char resulta[2], resultb[2];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar('\\0')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 4: DEL character (127)
    {
        char ch = 127;
        int pipefd[2];
        char resulta[2], resultb[2];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar(127)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 5: Non-printable character (newline '\n')
    {
        char ch = '\n';
        int pipefd[2];
        char resulta[2], resultb[2];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar('\\n')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 6: Non-printable character (tab '\t')
    {
        char ch = '\t';
        int pipefd[2];
        char resulta[2], resultb[2];
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar('\\t')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 7: Negative value
    {
        char ch = -1;
        int pipefd[2];
        char resulta[2], resultb[2];
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar(-1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 8: Large value
    {
        char ch = 5000;
        int pipefd[2];
        char resulta[2], resultb[2];
        
        // Capture ft_putchar_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putchar_fd(ch, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture putchar output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        putchar(ch);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putchar(5000)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    printf("\nFinished test_putchar_fd...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_putstr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_putstr_fd...\n");

    int saved_stdout = dup(STDOUT_FILENO);

    // Test cases for putstr_fd function comparison
    printf("printf vs. ft_putstr_fd:\n");

    // Test 1: Normal string
    {
        char *str = "Hello, world!";
        int pipefd[2];
        char resulta[50], resultb[50];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putstr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putstr_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, strlen(str));
        resultb[strlen(str)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s", str);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, strlen(str));
        resulta[strlen(str)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putstr_fd('Hello, world!')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 2: Empty string
    {
        char *str = "";
        int pipefd[2];
        char resulta[1], resultb[1];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putstr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putstr_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, strlen(str));
        resultb[strlen(str)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s", str);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, strlen(str));
        resulta[strlen(str)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putstr_fd('')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 3: String with special characters
    {
        char *str = "Line1\nLine2\tTabbed";
        int pipefd[2];
        char resulta[50], resultb[50];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putstr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putstr_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, strlen(str));
        resultb[strlen(str)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s", str);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, strlen(str));
        resulta[strlen(str)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putstr_fd('Line1\\nLine2\\tTabbed')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 4: String with NULL character inside
    {
        char *str = "Before\0After";
        int pipefd[2];
        char resulta[50], resultb[50];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putstr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putstr_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, strlen("Before"));
        resultb[strlen("Before")] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s", "Before");
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, strlen("Before"));
        resulta[strlen("Before")] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putstr_fd('Before\\0After')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    printf("\nFinished test_putstr_fd...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_putendl(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_putendl_fd...\n");

    int saved_stdout = dup(STDOUT_FILENO);

    // Test cases for putendl_fd function comparison
    printf("expected result vs. ft_putendl_fd:\n");

    // Test 1: Normal string
    {
        char *str = "Hello, world!";
        int pipefd[2];
        char resulta[50], resultb[50];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putendl_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putendl_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, strlen(str) + 1);
        resultb[strlen(str) + 1] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s\n", str);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, strlen(str) + 1);
        resulta[strlen(str) + 1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putendl_fd('Hello, world!')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 2: Empty string
    {
        char *str = "";
        int pipefd[2];
        char resulta[2], resultb[2];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putendl_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putendl_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 1);
        resultb[1] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s\n", str);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 1);
        resulta[1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putendl_fd('')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 3: String with special characters
    {
        char *str = "Line1\nLine2\tTabbed";
        int pipefd[2];
        char resulta[50], resultb[50];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putendl_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putendl_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, strlen(str) + 1);
        resultb[strlen(str) + 1] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s\n", str);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, strlen(str) + 1);
        resulta[strlen(str) + 1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putendl_fd('Line1\\nLine2\\tTabbed')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 4: String with NULL character inside
    {
        char *str = "Before\0After";
        int pipefd[2];
        char resulta[50], resultb[50];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putendl_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putendl_fd(str, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, strlen("Before") + 1); // +1 for newline
        resultb[strlen("Before") + 1] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%s\n", "Before");
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, strlen("Before") + 1);
        resulta[strlen("Before") + 1] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putendl_fd('Before\\0After')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    printf("\nFinished test_putendl_fd...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_putnbr(bool *grandpass, struct tests (*t)[43], int *i) {
    bool pass = true;
    int test = 0;
    printf("\nRunning test_putnbr_fd...\n");

    int saved_stdout = dup(STDOUT_FILENO);

    // Test cases for putnbr_fd function comparison
    printf("expected result vs. ft_putnbr_fd:\n");

    // Test 1: Normal number
    {
        int i = 42;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(42)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 2: Small positive number
    {
        int i = 4;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(4)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 3: Small negative number
    {
        int i = -1;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-1)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 4: Zero
    {
        int i = 0;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(0)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 5: Larger negative number
    {
        int i = -155;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-155)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 6: Large negative number
    {
        int i = -1234567;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-1234567)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 7: Maximum integer
    {
        int i = 2147483647;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(2147483647)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 8: Minimum integer
    {
        int i = -2147483648;
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd(-2147483648)", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    // Test 9: Character test (ASCII of 'a' is 97)
    {
        int i = 'a';
        int pipefd[2];
        char resulta[20], resultb[20];
        bzero(resulta, sizeof(resulta));
        bzero(resultb, sizeof(resultb));

        // Capture ft_putnbr_fd output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        ft_putnbr_fd(i, STDOUT_FILENO);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resultb, 20);
        resultb[strlen(resultb)] = '\0';
        close(pipefd[0]);

        // Capture printf output
        pipe(pipefd);
        dup2(pipefd[1], STDOUT_FILENO);
        printf("%d", i);
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
        close(pipefd[1]);
        read(pipefd[0], resulta, 20);
        resulta[strlen(resulta)] = '\0';
        close(pipefd[0]);

        // Compare results
        compare_results("putnbr_fd('a')", resulta, resultb, 1, ++test, &pass, 2, 0);
    }

    printf("\nFinished test_putnbr_fd...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false; (*t)[*i].passed = false; 
    }
    (*i)++;
}

void run_test_bonus(bool *grandpass, struct tests (*t)[43], int *i)
{
    bool pass = true;
    int test = 0;
    int expected_size;
    printf("\nRunning test_bonus...\n");

    // Test cases for putnbr_fd function comparison
    printf("expected result vs. bonus function result:\n");

    int *np = (int*)malloc(sizeof(int));
    if (np == NULL)
    {
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    *np = 10;
    printf("Test 1: Creating a node with ft_lstnew...");
    t_list *node = ft_lstnew(np);
    if (node == NULL)
    {
        free(np);
        pass = false;
        (*t)[34].passed = false;
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        return;
    }
    printf("\n");
    if (compare_results("ft_lstnew(int)", np, node->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[34].passed = false;
    t_list *start = node;

    char *str = (char*)malloc(7 * sizeof(char));
    if (str == NULL)
    {
        free(np);
        free(node);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    strcpy(str, "string");
    printf("Test 2: Creating node #2 with ft_lstnew...");
    t_list *node2 = ft_lstnew(str);
    if (node2 == NULL)
    {
        free(np);
        free(node);
        free(str);
        pass = false;
        (*t)[34].passed = false;
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        return;
    }
    printf("\n");
    if (compare_results("ft_lstnew(str)", str, node2->content, 1, ++test, &pass, 2, 0) == 0)
        (*t)[34].passed = false;  
    
    printf("Adding node2 to the front of the list with ft_lstadd_front...\n");
    ft_lstadd_front(&start, node2);
    if (compare_results("ft_lstadd_front", node2->content, start->content, 1, ++test, &pass, 2, 0) == 0)
        (*t)[35].passed = false;
    
    expected_size = 2;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;
    
    printf("Getting the last node...\n");
    t_list *end = ft_lstlast(start);
    if (compare_results("ft_lstlast", np, end->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[38].passed = false;

    double *dp = (double*)malloc(sizeof(double));
    if (dp == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    *dp = 2.83;
    printf("Test 6: Creating a new node with ft_lstnew...");
    t_list *node3 = ft_lstnew(dp);
    if (node3 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(dp);
        pass = false;
        (*t)[34].passed = false;
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        return;
    }
    printf("\n");
    if (compare_results("ft_lstnew(double)", dp, node3->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[34].passed = false;
    printf("Adding node3 to the back of the list with ft_lstadd_back and getting the last node with ft_lstlast...\n");
    ft_lstadd_back(&start, node3);
    end = ft_lstlast(start);
    if (compare_results("ft_lstadd_back + ft_lstlast", dp, end->content, 1, ++test, &pass, 1, 0) == 0)
    {
        (*t)[36].passed = false;
        (*t)[38].passed = false;
    }
    
    expected_size = 3;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;

    printf("Test 9: Creating a new node (NULL-based) with ft_lstnew...");
    t_list *node4 = ft_lstnew(NULL);
    if (node4 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(dp);
        free(node3);
        pass = false;
        (*t)[34].passed = false;
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        return;
    }
    printf(" - ");
    printf(GREEN "PASS");
    printf(RESET "\n");
    printf("Adding node4 to the back of the list with ft_lstadd_back and getting the last node with ft_lstlast...\n");
    ft_lstadd_back(&start, node4);
    end = ft_lstlast(start);
    test = 9;
    if (compare_results("ft_lstadd_back + ft_lstlast", node4, end, 1, ++test, &pass, 4, 0) == 0)
    {
        (*t)[36].passed = false;
        (*t)[38].passed = false;
    }
    
    expected_size = 4;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;

    printf("Test 12: Deleting node3 with ft_lstdelone...");
    void *check1 = node3->content;
    normal_del_cl(&start, &node3, del, 1);
    if (check1 == node3->content)
    {
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[39].passed = false;
        pass = false;
    }
    printf(" - ");
    printf(GREEN "PASS");
    printf(RESET "\n");
    expected_size = 3;
    test = 12;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;

    int *np2 = (int*)malloc(sizeof(int));
    if (np2 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(node4);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    *np2 = 12;
    printf("Test 14: Creating a new node with ft_lstnew...");
    t_list *node5 = ft_lstnew(np2);
    if (node5 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(node4);
        free(np2);
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[34].passed = false;
        return;
    }
    printf("\n");
    if (compare_results("ft_lstnew(int)", np2, node5->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[34].passed = false;
    printf("Adding node5 to the back of the list with ft_lstadd_back and getting the last node with ft_lstlast...\n");
    ft_lstadd_back(&start, node5);
    end = ft_lstlast(start);
    if (compare_results("ft_lstadd_back + ft_lstlast", np2, end->content, 1, ++test, &pass, 1, 0) == 0)
    {
        (*t)[36].passed = false;
        (*t)[38].passed = false;
    }

    int *np3 = (int*)malloc(sizeof(int));
    if (np3 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(node4);
        free(np2);
        free(node5);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    *np3 = 13;
    printf("Test 16: Creating a new node with ft_lstnew...");
    t_list *node6 = ft_lstnew(np3);
    if (node6 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(node4);
        free(np2);
        free(node5);
        free(np3);
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[34].passed = false;
        return;
    }
    printf("\n");
    test = 15;
    if (compare_results("ft_lstnew(int)", np3, node6->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[34].passed = false;
    printf("Adding node6 to the back of the list with ft_lstadd_back and getting the last node with ft_lstlast...\n");
    ft_lstadd_back(&start, node6);
    end = ft_lstlast(start);
    if (compare_results("ft_lstadd_back + ft_lstlast", np3, end->content, 1, ++test, &pass, 1, 0) == 0)
    {
        (*t)[36].passed = false;
        (*t)[38].passed = false;
    }

    int *np4 = (int*)malloc(sizeof(int));
    if (np4 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(node4);
        free(np2);
        free(node5);
        free(np3);
        free(node6);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    *np4 = 14;
    printf("Test 18: Creating a new node with ft_lstnew...");
    t_list *node7 = ft_lstnew(np4);
    if (node7 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(node4);
        free(np2);
        free(node5);
        free(np3);
        free(node6);
        free(np4);
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[34].passed = false;
        return;
    }
    printf("\n");
    test = 17;
    if (compare_results("ft_lstnew", np4, node7->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[34].passed = false;
    printf("Adding node7 to the back of the list with ft_lstadd_back and getting the last node with ft_lstlast...\n");
    ft_lstadd_back(&start, node7);
    end = ft_lstlast(start);
    if (compare_results("ft_lstadd_back + ft_lstlast", np4, end->content, 1, ++test, &pass, 1, 0) == 0)
    {
        (*t)[36].passed = false;
        (*t)[38].passed = false;
    }
    
    expected_size = 6;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;

    printf("Test 21: Clearing the list from node4 with ft_lstclear...");
    t_list *check2 = node4;
    int *check3 = node7->content;
    normal_del_cl(&start, &node4, del, 2);
    if (check2 == node4 || check3 == node7->content)
    {
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        pass = false;
        (*t)[40].passed = false;
    }
    printf(" - ");
    printf(GREEN "PASS");
    printf(RESET "\n");
    expected_size = 2;
    test = 21;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;

    int *np5 = (int*)malloc(sizeof(int));
    if (np5 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(np2);
        free(node5);
        free(np3);
        free(node6);
        free(np4);
        free(node7);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    *np5 = 15;
    printf("Test 23: Creating a new node with ft_lstnew...");
    t_list *node8 = ft_lstnew(np5);
    if (node8 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(np2);
        free(node5);
        free(np3);
        free(node6);
        free(np4);
        free(node7);
        free(np5);
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[34].passed = false;
        return;
    }
    printf("\n");
    test = 22;
    if (compare_results("ft_lstnew(int)", np5, node8->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[34].passed = false;
    printf("Adding node8 to the back of the list with ft_lstadd_back...\n");
    ft_lstadd_back(&start, node8);

    int *np6 = (int*)malloc(sizeof(int));
    if (np6 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(dp);
        free(node3);
        free(node4);
        free(np2);
        free(node5);
        free(np3);
        free(node6);
        free(np4);
        free(node7);
        free(np5);
        free(node8);
        printf("Error on the side of test code: memory for a value could not be allocated.\n");
        return;
    }
    *np6 = 16;
    printf("Test 24: Creating a new node with ft_lstnew...");
    t_list *node9 = ft_lstnew(np6);
    if (node9 == NULL)
    {
        free(np);
        free(node);
        free(node2);
        free(str);
        free(dp);
        free(node3);
        free(node4);
        free(np2);
        free(node5);
        free(np3);
        free(node6);
        free(np4);
        free(node7);
        free(np5);
        free(node8);
        free(np6);
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[34].passed = false;
        return;
    }
    printf("\n");
    test = 23;
    if (compare_results("ft_lstnew(int)", np6, node9->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[34].passed = false;
    printf("Adding node9 to the back of the list with ft_lstadd_back...\n");
    ft_lstadd_back(&start, node9);

    printf("Iterating through the list with ft_lstiter...\n");
    ft_lstiter(node, fb);
    expected_size = 11;
    if (compare_results("ft_lstiter", &expected_size, node->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[41].passed = false;
    expected_size = 16;
    if (compare_results("ft_lstiter", &expected_size, node8->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[41].passed = false;
    expected_size = 17;
    if (compare_results("ft_lstiter", &expected_size, node9->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[41].passed = false;

    printf("Test 28: Deleting node2 with ft_lstdelone...");
    check1 = node2->content;
    normal_del_cl(&start, &node2, del, 1);
    if (check1 == node2->content)
    {
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        pass = false;
        (*t)[39].passed = false;
    }
    printf(" - ");
    printf(GREEN "PASS");
    printf(RESET "\n");
    
    expected_size = 3;
    test = 28;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;

    printf("Test 30: Mapping the list with ft_lstmap...");
    t_list *newl = ft_lstmap(start, fret, del);
    if (newl == NULL)
    {
        free(np);
        free(node);
        free(np5);
        free(node8);
        free(np6);
        free(node9);
        printf(" - ");
        printf(RED "FAIL");
        printf(RESET" \n");
        (*t)[42].passed = false;
        return;
    }
    printf("\n");
    expected_size = 12;
    test = 29;
    if (compare_results("ft_lstmap", &expected_size, newl->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[42].passed = false;
    newl = newl->next;
    expected_size = 17;
    if (compare_results("ft_lstmap", &expected_size, newl->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[42].passed = false;
    newl = newl->next;
    expected_size = 18;
    if (compare_results("ft_lstmap", &expected_size, newl->content, 1, ++test, &pass, 1, 0) == 0)
        (*t)[42].passed = false;
    
    expected_size = 3;
    if (compare_results("Counting list size with ft_lstsize", &expected_size, &(int){ ft_lstsize(start) }, 1, ++test, &pass, 1, 0) == 0)
        (*t)[37].passed = false;

    free(np);
    free(node);
    free(np5);
    free(node8);
    free(np6);
    free(node9);

    printf("\nFinished test_bonus...\n");
    printf("Overall grade: ");
    if (pass == true) {
        printf(GREEN "PASS");
        printf(RESET "\n");
    } else {
        printf(RED "FAIL");
        printf(RESET" \n");
        *grandpass = false;
    }
}

