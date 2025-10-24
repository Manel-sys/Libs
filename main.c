/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manferre <manferre@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:31:24 by manferre          #+#    #+#             */
/*   Updated: 2025/10/23 18:14:40 by manferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include <signal.h>
#include <setjmp.h>
#include <limits.h>

#define TEST_SEP "---------------------------------------------\n"
#define TEST_HEADER "#############################################\n"

static sigjmp_buf jump_buffer;
void segfault_handler(int sig)
{
    (void) sig;
    siglongjmp(jump_buffer, 1);
}

static void	print_node_str(void *content)
{	
	printf("Node->content = %s\n", (char *)content);	
}

/* static void	print_node_int(t_list *node)
{
	printf("Node->content = %d", *(int *)(node->content));
} */

static void	print_int_arr(int *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (i == 0)
			printf("{ %d, ", tab[i]);
		else if (i < size -1)
			printf("%d, ", tab[i]);
		else
			printf("%d }\n", tab[i]);
		i++;
	}
}

static	void	print_word_tab(char **word_tab, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		printf("{ [%s] }\n", word_tab[0]);
		return ;
	}		
	while(i < size + 1)
	{
		if (i == 0)
			printf("{ [%s], ", word_tab[i]);
		else if (i < size)
			printf("[%s], ", word_tab[i]);
		else
			printf("[%s] }\n", word_tab[i]);
		i++;
	}
}

static	int	arr_strcmp(char **arr1, char **arr2)
{
	size_t	i;
	
	i = 0;
	while (arr1[i] && arr2[i])
	{
		if (ft_strncmp(arr1[i], arr2[i], ft_strlen(arr2[i])))
			return (0);
		i++;
	}
	if (arr1[i] != NULL || arr2[i] != NULL)
		return (0);
	return (1);
}

static	void	free_str_tab(char **to_free, size_t size)
{
	size_t	i;
	
	i = 0;
	while (i < size)
	{
		if (to_free[i])
			free(to_free[i]);
		i++;
	}
	free(to_free);
}

static char	tester_1(unsigned int index, char c)
{
	if (ft_isprint(c + index))
		c += index;
	else if (ft_isprint(c - index))
		c -= index;
	return (c); 
}

static void	tester_2(void *s1)
{
	char	*s = (char *)s1;
	
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}



int	main(void)
{
	signal(SIGSEGV, segfault_handler);
	//Tests for ft_isalpha
	printf(TEST_HEADER);
	printf("Testing ft_isalpha... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	int	a;

	a = 'c';
	printf("Original: %d\nMy own  : %d\n", isalpha(a), ft_isalpha(a));
	if (isalpha(a) - ft_isalpha(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	a = '0';
	printf("Original: %d\nMy own  : %d\n", isalpha(a), ft_isalpha(a));
	if (isalpha(a) - ft_isalpha(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//---------------------------------------------------------------
	//Tests for ft_isdigit
	printf(TEST_HEADER);
	printf("Testing ft_isdigit... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");	
	a = '5';
	printf("Original: %d\nMy own  : %d\n", isdigit(a), ft_isdigit(a));
	if (isdigit(a) - ft_isdigit(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	a = 'c';
	printf("Original: %d\nMy own  : %d\n", isdigit(a), ft_isdigit(a));
	if (isdigit(a) - ft_isdigit(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);	
	//----------------------------------------------------------------
	//Tests for ft_isalnum
	printf(TEST_HEADER);
	printf("Testing ft_isalnum... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");	
	a = '5';
	printf("Original: %d\nMy own  : %d\n", isalnum(a), ft_isalnum(a));
	if (isalnum(a) - ft_isalnum(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	a = 'c';
	printf("Original: %d\nMy own  : %d\n", isalnum(a), ft_isalnum(a));
	if (isalnum(a) - ft_isalnum(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");	
	a = '-';
	printf("Original: %d\nMy own  : %d\n", isalnum(a), ft_isalnum(a));
	if (isalnum(a) - ft_isalnum(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_isascii
	printf(TEST_HEADER);
	printf("Testing ft_isascii... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");	
	a = '5';
	printf("Original: %d\nMy own  : %d\n", __isascii(a), ft_isascii(a));
	if (__isascii(a) - ft_isascii(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	a = 128;
	printf("Original: %d\nMy own  : %d\n", __isascii(a), ft_isascii(a));
	if (__isascii(a) - ft_isascii(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_isprint
	printf(TEST_HEADER);
	printf("Testing ft_isprint... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");	
	a = '5';
	printf("Original: %d\nMy own  : %d\n", isprint(a), ft_isprint(a));
	if (isprint(a) - ft_isprint(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	a = 128;
	printf("Original: %d\nMy own  : %d\n", isprint(a), ft_isprint(a));
	if (isprint(a) - ft_isprint(a) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strlen
	printf(TEST_HEADER);
	printf("Testing ft_strlen... \n");
	printf(TEST_HEADER);
	const char *s1;
	//Test 1
	s1 = "Hello World";
	printf("\nTest 1:\n");	
	printf("Original: %zu\nMy own  : %zu\n", strlen(s1), ft_strlen(s1));
	if (strlen(s1) - ft_strlen(s1) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	s1 = "";
	printf("Original: %zu\nMy own  : %zu\n", strlen(s1), ft_strlen(s1));
	if (strlen(s1) - ft_strlen(s1) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
    s1 = NULL;
    printf("\nTest 3:\n");
    if (sigsetjmp(jump_buffer, 1) == 0)
    {
        ft_strlen(NULL);
        printf("Original: segmentation fault (core dumped)\nMy own  : %zu\n", ft_strlen(NULL));
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_memset
	printf(TEST_HEADER);
	printf("Testing ft_memset... \n");
	printf(TEST_HEADER);
	//Test 1
	int	b;
	a = 258;
	b = a;
	printf("\nTest 1:\n");
	memset(&a, 2, 2);
	ft_memset(&b, 2, 2);	
	printf("Original: %d\nMy own  : %d\n", a, b);
	if (a - b == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	int	arr_a[5] = {1, 257, 3, 8, 0};
	int	arr_b[5] = {1, 257, 3, 8, 0};
	printf("\nTest 2:\n");
	memset(arr_a, 0, 5);
	ft_memset(arr_b, 0, 5);
	printf("Original: ");
	print_int_arr(arr_a, sizeof(arr_a)/sizeof(int));
	printf("My own  : ");
	print_int_arr(arr_b, sizeof(arr_b)/sizeof(int));
	if (!memcmp(arr_a, arr_b, 20))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	s1_memset[] = "Hello World";
	char	s2_memset[] = "Hello World";
	memset(s1_memset, 90, ft_strlen(s1_memset));
	ft_memset(s2_memset, 90, ft_strlen(s2_memset));
	printf("Original: %s\nMy own  : %s\n", s1_memset, s2_memset);
	if (!memcmp(s1_memset, s2_memset, ft_strlen(s1_memset) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_bzero
	printf(TEST_HEADER);
	printf("Testing ft_bzero... \n");
	printf(TEST_HEADER);
	//Test 1
	a = 258;
	b = a;
	printf("\nTest 1:\n");
	bzero(&a, 4);
	ft_bzero(&b, 4);	
	printf("Original: %d\nMy own  : %d\n", a, b);
	if (a - b == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	int	arr_c[5] = {1, 257, 3, 8, 0};
	int	arr_d[5] = {1, 257, 3, 8, 0};
	printf("\nTest 2:\n");
	bzero(arr_c, 20);
	ft_bzero(arr_d, 20);
	printf("Original: ");
	print_int_arr(arr_c, sizeof(arr_c)/sizeof(int));
	printf("My own  : ");
	print_int_arr(arr_d, sizeof(arr_d)/sizeof(int));
	if (!memcmp(arr_c, arr_d, 20))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	s1_bzero[] = "Hello World";
	char	s2_bzero[] = "Hello World";
	bzero(s1_bzero, ft_strlen(s1_bzero));
	ft_bzero(s2_bzero, ft_strlen(s2_bzero));
	printf("Original: %s\nMy own  : %s\n", s1_bzero, s2_bzero);
	if (!memcmp(s1_bzero, s2_bzero, ft_strlen(s1_bzero) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_memcpy
	printf(TEST_HEADER);
	printf("Testing ft_memcpy... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	t1_memcpy[20] = "This is a test";
	char	*t2_memcpy = strdup(t1_memcpy);
	memcpy(t1_memcpy, "That", 4);
	ft_memcpy(t2_memcpy, "That", 4);
	printf("Original: %s\nMy own  : %s\n", t1_memcpy, t2_memcpy);
	if (!memcmp(t1_memcpy, t2_memcpy, ft_strlen(t1_memcpy) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	free(t2_memcpy);
	//Test 2
	int	arr_e[5] = {1, 257, 3, 8, 0};
	int	arr_f[5] = {1, 257, 3, 8, 0};
	printf("\nTest 2:\n");
	memcpy(arr_e + 2, arr_e, 12);
	ft_memcpy(arr_f + 2, arr_f, 12);
	printf("Original: ");
	print_int_arr(arr_e, sizeof(arr_e)/sizeof(int));
	printf("My own  : ");
	print_int_arr(arr_f, sizeof(arr_f)/sizeof(int));
	if (!memcmp(arr_e, arr_f, 20))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	t3_memcpy[] = "123456789";
	char	t3_ft_memcpy[] = "123456789";
	memcpy(t3_memcpy + 2, t3_memcpy, 5);
	ft_memcpy(t3_ft_memcpy + 2, t3_ft_memcpy, 5);
	printf("Original: %s\nMy own  : %s\n", t3_memcpy, t3_ft_memcpy);
	if (!memcmp(t3_memcpy, t3_ft_memcpy, ft_strlen(t3_memcpy) + 1))
		printf("OK :D\n");
	else
		printf("OK -.-\" It has undefined behaviour\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        ft_memcpy(NULL, t3_ft_memcpy, 5);
        printf("Original: Does not compile\nMy own  : %s\n", t3_ft_memcpy);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: Does not compile\nMy own  : segmentation fault (core dumped)\n");
        printf("OK -.-\" It has undefined behaviour\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_memmove
	printf(TEST_HEADER);
	printf("Testing ft_memmove... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	t1_memmove[20] = "This is a test";
	char	*t2_memmove = strdup(t1_memmove);
	memmove(t1_memmove, "That", 4);
	ft_memmove(t2_memmove, "That", 4);
	printf("Original: %s\nMy own  : %s\n", t1_memmove, t2_memmove);
	if (!memcmp(t1_memmove, t2_memmove, ft_strlen(t1_memmove) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	free(t2_memmove);
	//Test 2
	int	arr_memmove[5] = {1, 257, 3, 8, 0};
	int	arr_ft_memmove[5] = {1, 257, 3, 8, 0};
	printf("\nTest 2:\n");
	memmove(arr_memmove + 2, arr_memmove, 12);
	ft_memmove(arr_ft_memmove + 2, arr_ft_memmove, 12);
	printf("Original: ");
	print_int_arr(arr_memmove, 5);
	printf("My own  : ");
	print_int_arr(arr_ft_memmove, 5);
	if (!memcmp(arr_memmove, arr_ft_memmove, 20))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	t3_memmove[] = "123456789";
	char	t3_ft_memmove[] = "123456789";
	memmove(t3_memmove + 2, t3_memmove, 5);
	ft_memmove(t3_ft_memmove + 2, t3_ft_memmove, 5);
	printf("Original: %s\nMy own  : %s\n", t3_memmove, t3_ft_memmove);
	if (!memcmp(t3_memmove, t3_ft_memmove, ft_strlen(t3_memmove) + 1))
		printf("OK :D\n");
	else
		printf("OK -.-\" It has undefined behaviour\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        ft_memmove(NULL, t3_ft_memmove, 5);
        printf("Original: Does not compile\nMy own  : %s\n", t3_ft_memmove);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: Does not compile\nMy own  : segmentation fault (core dumped)\n");
        printf("OK -.-\" It has undefined behaviour\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strlcpy
	printf(TEST_HEADER);
	printf("Testing ft_strlcpy... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	s1_strlcpy[20] = "This is a test";
	char	s1_ft_strlcpy[20] = "This is a test";
	size_t	res_strlcpy = strlcpy(s1_strlcpy, "Hello World", 20);
	size_t	res_ft_strlcpy = ft_strlcpy(s1_ft_strlcpy, "Hello World", 20);
	printf("Original: %s ---> Length = %zu\nMy own  : %s ---> Length = %zu\n", s1_strlcpy, res_strlcpy, s1_ft_strlcpy, res_ft_strlcpy);
	if (!memcmp(s1_strlcpy, s1_ft_strlcpy, 20) && res_strlcpy == res_ft_strlcpy)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	s2_ft_strlcpy[20] = "This is a test";
	
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        res_ft_strlcpy = ft_strlcpy(s2_ft_strlcpy, NULL, 20);
        printf("Original: segmentation fault (core dumped)\nMy own  : %s\n", s2_ft_strlcpy);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	s3_strlcpy[20] = "This is a test";
	char	s3_ft_strlcpy[20] = "This is a test";
	res_strlcpy = strlcpy(s3_strlcpy, "", 20);
	res_ft_strlcpy = ft_strlcpy(s3_ft_strlcpy, "", 20);
	printf("Original: %s ---> Length = %zu\nMy own  : %s ---> Length = %zu\n", s3_strlcpy, res_strlcpy, s3_ft_strlcpy, res_ft_strlcpy);
	if (!memcmp(s3_strlcpy, s3_ft_strlcpy, 20) && res_strlcpy == res_ft_strlcpy)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	s4_strlcpy[20] = "This is a test";
	char	s4_ft_strlcpy[20] = "This is a test";
	char	*s4_src = "This is a testTESTtestTestandAnotherTest";
	res_strlcpy = strlcpy(s4_strlcpy, s4_src, 23);
	res_ft_strlcpy = ft_strlcpy(s4_ft_strlcpy, s4_src, 23);
	printf("Original: %s ---> Length = %zu\nMy own  : %s ---> Length = %zu\n", s4_strlcpy, res_strlcpy, s4_ft_strlcpy, res_ft_strlcpy);
	if (!memcmp(s4_strlcpy, s4_ft_strlcpy, 23) && res_strlcpy == res_ft_strlcpy)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strlcat
	printf(TEST_HEADER);
	printf("Testing ft_strlcat... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	s1_strlcat[20] = "This is a test";
	char	s1_ft_strlcat[20] = "This is a test";
	size_t	res_strlcat = strlcat(s1_strlcat, "Hello World", 20);
	size_t	res_ft_strlcat = ft_strlcat(s1_ft_strlcat, "Hello World", 20);
	printf("Original: %s ---> Length = %zu\nMy own  : %s ---> Length = %zu\n", s1_strlcat, res_strlcat, s1_ft_strlcat, res_ft_strlcat);
	if (!memcmp(s1_strlcat, s1_ft_strlcat, 20) && res_strlcat == res_ft_strlcat)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	s2_strlcat[20] = "This is a test";
	char	s2_ft_strlcat[20] = "This is a test";
	res_strlcat = strlcat(s2_strlcat, "Hello World", 26);
	res_ft_strlcat = ft_strlcat(s2_ft_strlcat, "Hello World", 26);
	printf("Original: %s ---> Length = %zu\nMy own  : %s ---> Length = %zu\n", s2_strlcat, res_strlcat, s2_ft_strlcat, res_ft_strlcat);
	if (!memcmp(s2_strlcat, s2_ft_strlcat, 26) && res_strlcat == res_ft_strlcat)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	s3_strlcat[20] = "This is a test";
	char	s3_ft_strlcat[20] = "This is a test";
	res_strlcat = strlcat(s3_strlcat, "Hello World", 5);
	res_ft_strlcat = ft_strlcat(s3_ft_strlcat, "Hello World", 5);
	printf("Original: %s ---> Length = %zu\nMy own  : %s ---> Length = %zu\n", s3_strlcat, res_strlcat, s3_ft_strlcat, res_ft_strlcat);
	if (!memcmp(s3_strlcat, s3_ft_strlcat, 20) && res_strlcat == res_ft_strlcat)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	s4_ft_strlcat[20] = "This is a test";
	
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        res_ft_strlcat = ft_strlcat(s4_ft_strlcat, NULL, 20);
        printf("Original: segmentation fault (core dumped)\nMy own  : %s\n", s4_ft_strlcat);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_toupper
	printf(TEST_HEADER);
	printf("Testing ft_toupper... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	s1_toupper[] = "aloha";
	char	s1_ft_toupper[] = "aloha";
	s1_toupper[0] = toupper(s1_toupper[0]);
	s1_ft_toupper[0] = ft_toupper(s1_ft_toupper[0]);
	printf("Original: %s\nMy own  : %s\n", s1_toupper, s1_ft_toupper);
	if (!memcmp(s1_toupper, s1_ft_toupper, ft_strlen(s1_toupper) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_tolower
	printf(TEST_HEADER);
	printf("Testing ft_tolower... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	s1_tolower[] = "Aloha";
	char	s1_ft_tolower[] = "Aloha";
	s1_tolower[0] = tolower(s1_tolower[0]);
	s1_ft_tolower[0] = ft_tolower(s1_ft_tolower[0]);
	printf("Original: %s\nMy own  : %s\n", s1_tolower, s1_ft_tolower);
	if (!memcmp(s1_tolower, s1_ft_tolower, ft_strlen(s1_tolower) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strchr
	printf(TEST_HEADER);
	printf("Testing ft_strchr... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strchr = strchr("Hello World", 'e');
	char	*s1_ft_strchr = ft_strchr("Hello World", 'e');
	printf("Original: %s\nMy own  : %s\n", s1_strchr, s1_ft_strchr);
	if (!memcmp(s1_strchr, s1_ft_strchr, ft_strlen(s1_strchr) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_strchr = strchr("", 'e');
	char	*s2_ft_strchr = ft_strchr("", 'e');
	printf("Original: %s\nMy own  : %s\n", s2_strchr, s2_ft_strchr);
	if (!s2_strchr && !s2_ft_strchr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        char *s3_ft_strchr = ft_strchr(NULL, 'a');
        printf("Original: segmentation fault (core dumped)\nMy own  : %s\n", s3_ft_strchr);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK -.-\" It has undefined behaviour\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strrchr
	printf(TEST_HEADER);
	printf("Testing ft_strrchr... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strrchr = strrchr("Hello World", 'l');
	char	*s1_ft_strrchr = ft_strrchr("Hello World", 'l');
	printf("Original: %s\nMy own  : %s\n", s1_strrchr, s1_ft_strrchr);
	if (!memcmp(s1_strrchr, s1_ft_strrchr, ft_strlen(s1_strrchr) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_strrchr = strrchr("Hello World", 'a');
	char	*s2_ft_strrchr = ft_strrchr("Hello World", 'a');
	printf("Original: %s\nMy own  : %s\n", s2_strrchr, s2_ft_strrchr);
	if (!s2_strrchr && !s2_ft_strrchr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        char *s3_ft_strrchr = ft_strrchr(NULL, 'a');
        printf("Original: segmentation fault (core dumped)\nMy own  : %s\n", s3_ft_strrchr);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK -.-\" It has undefined behaviour\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strncmp
	printf(TEST_HEADER);
	printf("Testing ft_strncmp... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strncmp = "This is a test!";
	char	*s1_tocomp = "This is a test!";
	printf("Original: %d\nMy own  : %d\n", strncmp(s1_strncmp, s1_tocomp, 15), ft_strncmp(s1_strncmp, s1_tocomp, 15));
	if (strncmp(s1_strncmp, s1_tocomp, 15) == ft_strncmp(s1_strncmp, s1_tocomp, 15))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_strncmp = "This is a test!";
	char	*s2_tocomp = "This";
	printf("Original: %d\nMy own  : %d\n", strncmp(s2_strncmp, s2_tocomp, 15), ft_strncmp(s2_strncmp, s2_tocomp, 15));
	if (strncmp(s2_strncmp, s2_tocomp, 15) == ft_strncmp(s2_strncmp, s2_tocomp, 15))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        ft_strncmp("This is a test!", NULL, 15);
        printf("Original: segmentation fault (core dumped)\nMy own  : %d\n", ft_strncmp("This is a test!", NULL, 15));
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	*s4_strncmp = "This is a test!";
	char	*s4_tocomp = "This is a test!";
	printf("Original: %d\nMy own  : %d\n", strncmp(s4_strncmp, s4_tocomp, 0), ft_strncmp(s4_strncmp, s4_tocomp, 0));
	if (strncmp(s4_strncmp, s4_tocomp, 0) == ft_strncmp(s4_strncmp, s4_tocomp, 0))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_memchr
	printf(TEST_HEADER);
	printf("Testing ft_memchr... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_memchr = memchr("Hello World", 'e', 12);
	char	*s1_ft_memchr = ft_memchr("Hello World", 'e', 12);
	printf("Original: %s\nMy own  : %s\n", s1_memchr, s1_ft_memchr);
	if (s1_memchr == s1_ft_memchr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	int	arr_memchr[5] = {1, 255, 3, 8, 0};
	int	*arr1_memchr;
	int	*arr1_ft_memchr;
	arr1_memchr = memchr(arr_memchr, 255, 20);
	arr1_ft_memchr = ft_memchr(arr_memchr, 255, 20);
	printf("Original: ");
	print_int_arr(arr1_memchr, 3);
	printf("My own  : ");
	print_int_arr(arr1_ft_memchr, 3);
	if (arr1_memchr == arr1_ft_memchr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	//Test 3
	printf("\nTest 3:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        char	*s3_ft_memchr = ft_memchr(NULL, 'a', 4);
        printf("Original: segmentation fault (core dumped)\nMy own  : %p\n", s3_ft_memchr);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	*s4_memchr = memchr("This is a test", 'z', 15);
	char	*s4_ft_memchr = ft_memchr("This is a test", 'z', 15);
	printf("Original: %s\nMy own  : %s\n", s4_memchr, s4_ft_memchr);
	if (s4_memchr == s4_ft_memchr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 5
	printf("\nTest 5:\n");
	char	*s5_memchr = memchr("This is a test", 'a', 0);
	char	*s5_ft_memchr = ft_memchr("This is a test", 'a', 0);
	printf("Original: %s\nMy own  : %s\n", s5_memchr, s5_ft_memchr);
	if (s5_memchr == s5_ft_memchr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 6
	printf("\nTest 6:\n");
	int	i5 = 511;
	int	*i5_memchr = memchr(&i5, 1, 4);
	int	*i5_ft_memchr = ft_memchr(&i5, 1, 4);
	printf("Original: %p\nMy own  : %p\n", i5_memchr, i5_ft_memchr);
	if (i5_memchr == i5_ft_memchr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_memcmp
	printf(TEST_HEADER);
	printf("Testing ft_memcmp... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	s1_memcmp[] = "This is a test!";
	printf("Original: %d\nMy own  : %d\n", memcmp(s1_memcmp, "This is", 16), ft_memcmp(s1_memcmp, "This is", 16));
	if (memcmp(s1_memcmp, "This is", 16) == ft_memcmp(s1_memcmp, "This is", 16))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	printf("Original: %d\nMy own  : %d\n", memcmp(s1_memcmp, "This is", 0), ft_memcmp(s1_memcmp, "This is", 0));
	if (memcmp(s1_memcmp, "This is", 15) == ft_memcmp(s1_memcmp, "This is", 15))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
	printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        ft_memcmp("This is a test!", NULL, 16);
        printf("Original: segmentation fault (core dumped)\nMy own  : %d\n", ft_memcmp("This is a test!", NULL, 16));
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strnstr
	printf(TEST_HEADER);
	printf("Testing ft_strnstr... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strnstr = strnstr("Hello World Hello", "World", 17);
	char	*s1_ft_strnstr = ft_strnstr("Hello World Hello", "World", 17);
	printf("Original: %s\nMy own  : %s\n", s1_strnstr, s1_ft_strnstr);
	if (s1_strnstr == s1_ft_strnstr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	s1_strnstr = strnstr("Hello World Hello", "ola", 17);
	s1_ft_strnstr = ft_strnstr("Hello World Hello", "ola", 17);
	printf("Original: %s\nMy own  : %s\n", s1_strnstr, s1_ft_strnstr);
	if (s1_strnstr == s1_ft_strnstr)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        s1_ft_strnstr = ft_strnstr("Hello World Hello", NULL, 17);
        printf("Original: segmentation fault (core dumped)\nMy own  : %p\n", s1_ft_strnstr);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_atoi
	printf(TEST_HEADER);
	printf("Testing ft_atoi... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	printf("Original: %d\nMy own  : %d\n", atoi("     -255abcde"), ft_atoi("     -255abcde"));
	if (atoi("     -255abcde") == ft_atoi("     -255abcde"))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	printf("Original: %d\nMy own  : %d\n", atoi("     -+255abcde"), ft_atoi("     -+255abcde"));
	if (atoi("     -255abcde") == ft_atoi("     -255abcde"))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : %d\n", ft_atoi(NULL));
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
    printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_calloc
	printf(TEST_HEADER);
	printf("Testing ft_calloc... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_calloc = calloc(20, sizeof(char));
	char	*s1_ft_calloc = calloc(20, sizeof(char));
	printf("Original: %s\nMy own  : %s\n", s1_calloc, s1_ft_calloc);
	if (!memcmp(s1_calloc, s1_ft_calloc, 20))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_calloc);
	free(s1_ft_calloc);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	int	*tab1_calloc = calloc(5, sizeof(int));
	int	*tab1_ft_calloc = calloc(5, sizeof(int));
	printf("Original: ");
	print_int_arr(tab1_calloc, 5);
	printf("My own  : ");
	print_int_arr(tab1_ft_calloc, 5);
	if (!memcmp(tab1_calloc, tab1_ft_calloc, 20))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(tab1_calloc);
	free(tab1_ft_calloc);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	*s3_calloc = calloc(0, sizeof(char));
	char	*s3_ft_calloc = calloc(0, sizeof(char));
	printf("Original: %s\nMy own  : %s\n", s3_calloc, s3_ft_calloc);
	if (s3_ft_calloc)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s3_calloc);
	free(s3_ft_calloc);
	printf("\n");
    printf(TEST_SEP);	
	//Test 4
	printf("\nTest 4:\n");
	char	*s4_calloc = calloc(20, 0);
	char	*s4_ft_calloc = calloc(20, 0);
	printf("Original: %s\nMy own  : %s\n", s4_calloc, s4_ft_calloc);
	if (s4_ft_calloc)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s4_calloc);
	free(s4_ft_calloc);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strdup
	printf(TEST_HEADER);
	printf("Testing ft_strdup... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strdup = strdup("This is a test!!!");
	char	*s1_ft_strdup = ft_strdup("This is a test!!!");
	printf("Original: %s\nMy own  : %s\n", s1_strdup, s1_ft_strdup);
	if (!memcmp(s1_strdup, s1_ft_strdup, 18))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_strdup);
	free(s1_ft_strdup);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	s1_strdup = strdup("");
	s1_ft_strdup = ft_strdup("");
	printf("Original: %s\nMy own  : %s\n", s1_strdup, s1_ft_strdup);
	if (!memcmp(s1_strdup, s1_ft_strdup, 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_strdup);
	free(s1_ft_strdup);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
		s1_ft_strdup = ft_strdup(NULL);
        printf("Original: segmentation fault (core dumped)\nMy own  : %s\n", s1_ft_strdup);
        printf("KO :(\n");
    }
    else
    {
        printf("Original: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
	
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_substr
	printf(TEST_HEADER);
	printf("Testing ft_substr... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_substr = ft_substr("Hello World Hello", 6, 4);
	printf("Expected: Worl\nMy own  : %s\n", s1_substr);
	if (!memcmp("Worl", s1_substr, ft_strlen(s1_substr) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_substr);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_substr = ft_substr("Hello World Hello", 17, 4);
	printf("Expected: \nMy own  : %s\n", s2_substr);
	if (!memcmp("", s2_substr, ft_strlen(s2_substr) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s2_substr);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	*s3_substr = ft_substr(NULL, 17, 4);
	printf("Expected: (null)\nMy own  : %s\n", s3_substr);
	if (s3_substr == NULL)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strjoin
	printf(TEST_HEADER);
	printf("Testing ft_strjoin... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strjoin = ft_strjoin("Conc", "atenation");
	printf("Expected: Concatenation\nMy own  : %s\n", s1_strjoin);
	if (!memcmp("Concatenation", s1_strjoin, ft_strlen(s1_strjoin) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_strjoin);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_strjoin = ft_strjoin("", "atenation");
	printf("Expected: atenation\nMy own  : %s\n", s2_strjoin);
	if (!memcmp("atenation", s2_strjoin, ft_strlen(s2_strjoin) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s2_strjoin);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	*s3_strjoin = ft_strjoin(NULL, "atenation");
	printf("Expected: atenation\nMy own  : %s\n", s3_strjoin);
	if (!memcmp("atenation", s3_strjoin, 10))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	*s4_strjoin = ft_strjoin("", "");
	printf("Expected: \nMy own  : %s\n", s4_strjoin);
	if (!memcmp("", s4_strjoin, ft_strlen(s4_strjoin) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s4_strjoin);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strtrim
	printf(TEST_HEADER);
	printf("Testing ft_strtrim... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strtrim = ft_strtrim("     Hello World    ", " ");
	printf("Expected: Hello World\nMy own  : %s\n", s1_strtrim);
	if (!memcmp("Hello World", s1_strtrim, ft_strlen(s1_strtrim) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_strtrim);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_strtrim = ft_strtrim("     Hello World////+-", "-/+");
	printf("Expected:      Hello World\nMy own  : %s\n", s2_strtrim);
	if (!memcmp("     Hello World", s2_strtrim, ft_strlen(s2_strtrim) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s2_strtrim);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	*s3_strtrim = ft_strtrim("This is a test!", "");
	printf("Expected: This is a test!\nMy own  : %s\n", s3_strtrim);
	if (!memcmp("This is a test!", s3_strtrim, ft_strlen(s3_strtrim) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s3_strtrim);
	printf("\n");
    printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	*s4_strtrim = ft_strtrim("", "+-");
	printf("Expected: \nMy own  : %s\n", s4_strtrim);
	if (!memcmp("", s4_strtrim, ft_strlen(s4_strtrim) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s4_strtrim);
	printf("\n");
    printf(TEST_SEP);
	//Test 5
	printf("\nTest 5:\n");
	char	*s5_strtrim = ft_strtrim(NULL, " ");
	printf("Expected: (null)\nMy own  : %s\n", s5_strtrim);
	if (s5_strtrim == NULL)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 6
	printf("\nTest 6:\n");
	char	*s6_strtrim = ft_strtrim("This is a test", NULL);
	printf("Expected: (null) || This is a test\nMy own  : %s\n", s6_strtrim);
	if (s6_strtrim == NULL || !memcmp("This is a test", s6_strtrim, 15))
		printf("OK :D It has undefined behaviour\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//Test 7
	printf("\nTest 7:\n");
	char	*s7_strtrim = ft_strtrim("c", "c");
	printf("Expected: \nMy own  : %s\n", s7_strtrim);
	if (!memcmp("", s7_strtrim, ft_strlen(s7_strtrim) + 1))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s7_strtrim);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_split
	printf(TEST_HEADER);
	printf("Testing ft_split... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*expected_1split[5] = {"This", "is", "a", "test!", NULL};
	char	**s1_split = ft_split("This is a test!", ' ');
	printf("Expected: ");
	print_word_tab(expected_1split, 4);
	printf("My own  : ");
	print_word_tab(s1_split, 4);
	if (arr_strcmp(expected_1split, s1_split))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free_str_tab(s1_split, 5);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*expected_2split[2] = {"This is a test!", NULL};
	char	**s2_split = ft_split("This is a test!", '\0');
	printf("Expected: ");
	print_word_tab(expected_2split, 1);
	printf("My own  : ");
	print_word_tab(s2_split, 1);
	if (arr_strcmp(expected_2split, s2_split))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free_str_tab(s2_split, 2);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	**s3_split = ft_split(NULL, ' ');
	if (sigsetjmp(jump_buffer, 1) == 0)
    {
        printf("Expected: segmentation fault (core dumped)\nMy own  : %s\n", s3_split[0]);
        printf("KO :(\n");
    }
    else
    {
        printf("Expected: segmentation fault (core dumped)\nMy own  : segmentation fault (core dumped)\n");
        printf("OK :D\n");
    }
	printf("\n");
    printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	*expected_4split[1] = {NULL};
	char	**s4_split = ft_split("", ' ');
	printf("Expected: ");
	print_word_tab(expected_4split, 0);
	printf("My own  : ");
	print_word_tab(s4_split, 0);
	if (arr_strcmp(expected_4split, s4_split))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free_str_tab(s4_split, 1);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_itoa
	printf(TEST_HEADER);
	printf("Testing ft_itoa... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_itoa = ft_itoa(-255);
	printf("Expected: -255\nMy own  : %s\n", s1_itoa);
	if (!memcmp("-255", s1_itoa, 5))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_itoa);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_itoa = ft_itoa(15978);
	printf("Expected: 15978\nMy own  : %s\n", s2_itoa);
	if (!memcmp("15978", s2_itoa, 6))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s2_itoa);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	char	*s3_itoa = ft_itoa(0);
	printf("Expected: 0\nMy own  : %s\n", s3_itoa);
	if (!memcmp("0", s3_itoa, 2))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s3_itoa);
	printf("\n");
    printf(TEST_SEP);
	//Test 4
	printf("\nTest 4:\n");
	char	*s4_itoa = ft_itoa(INT_MIN);
	printf("Expected: -2147483648\nMy own  : %s\n", s4_itoa);
	if (!memcmp("-2147483648", s4_itoa, 12))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s4_itoa);
	printf("\n");
    printf(TEST_SEP);
	//Test 5
	printf("\nTest 5:\n");
	char	*s5_itoa = ft_itoa(0255);
	printf("Expected: 173\nMy own  : %s\n", s5_itoa);
	if (!memcmp("173", s5_itoa, 4))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s5_itoa);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_strmapi
	printf(TEST_HEADER);
	printf("Testing ft_strmapi... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	char	*s1_strmapi = ft_strmapi("12aBc83", &tester_1);
	printf("Expected: 13cEg=9\nMy own  : %s\n", s1_strmapi);
	if (!memcmp("13cEg=9", s1_strmapi, 8))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(s1_strmapi);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*s2_strmapi = ft_strmapi(NULL, &tester_1);
	printf("Expected: (null)\nMy own  : %s\n", s2_strmapi);
	if (s2_strmapi == NULL)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_putchar_fd
	printf(TEST_HEADER);
	printf("Testing ft_putchar_fd... \n");
	printf(TEST_HEADER);
	//Test 1
	char	buff[1024];
	int		sz_read;
	printf("\nTest 1:\n");
	int	fd = open("example_t1", O_CREAT | O_WRONLY | O_APPEND, 0644);
	ft_putchar_fd('H', fd);
	ft_putchar_fd('e', fd);
	ft_putchar_fd('l', fd);
	ft_putchar_fd('l', fd);
	ft_putchar_fd('o', fd);
	close(fd);
	fd = open("example_t1", O_RDONLY);
	sz_read = read(fd, buff, 1024);
	buff[sz_read] = '\0';
	printf("Expected: Hello\nMy own  : %s\n", buff);
	if (!memcmp("Hello", buff, 6))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	close(fd);
	unlink("example_t1");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_putstr_fd
	printf(TEST_HEADER);
	printf("Testing ft_putstr_fd... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	fd = open("example_t2", O_CREAT | O_WRONLY | O_APPEND, 0644);	
	ft_putstr_fd("Hello World!", fd);
	close(fd);
	fd = open("example_t2", O_RDONLY);
	sz_read = read(fd, buff, 1024);
	buff[sz_read] = '\0';
	printf("Expected: Hello World!\nMy own  : %s\n", buff);
	if (!memcmp("Hello World!", buff, 13))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	close(fd);
	unlink("example_t2");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_putendl_fd
	printf(TEST_HEADER);
	printf("Testing ft_putendl_fd... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	fd = open("example_t3", O_CREAT | O_WRONLY | O_APPEND, 0644);	
	ft_putendl_fd("Hello World!", fd);
	close(fd);
	fd = open("example_t3", O_RDONLY);
	sz_read = read(fd, buff, 1024);
	buff[sz_read] = '\0';
	printf("Expected: Hello World!\nMy own  : %s\n", buff);
	if (!memcmp("Hello World!\n", buff, 14))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	close(fd);
	unlink("example_t3");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_putnbr_fd
	printf(TEST_HEADER);
	printf("Testing ft_putnbr_fd... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	fd = open("example_t4", O_CREAT | O_WRONLY | O_APPEND, 0644);	
	ft_putnbr_fd(INT_MIN, fd);
	close(fd);
	fd = open("example_t4", O_RDONLY);
	sz_read = read(fd, buff, 1024);
	buff[sz_read] = '\0';
	printf("Expected: -2147483648\nMy own  : %s\n", buff);
	if (!memcmp("-2147483648", buff, 12))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	close(fd);
	unlink("example_t4");
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	fd = open("example_t5", O_CREAT | O_WRONLY | O_APPEND, 0644);	
	ft_putnbr_fd(0, fd);
	close(fd);
	fd = open("example_t5", O_RDONLY);
	sz_read = read(fd, buff, 1024);
	buff[sz_read] = '\0';
	printf("Expected: 0\nMy own  : %s\n", buff);
	if (!memcmp("0", buff, 2))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	close(fd);
	unlink("example_t5");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstnew
	printf(TEST_HEADER);
	printf("Testing ft_lstnew... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	int	i_lstnew = 255;
	t_list	*node_lstnew_1 = ft_lstnew(&i_lstnew);
	printf("Expected: %d\nMy own  : %d\n", i_lstnew, *((int *)(node_lstnew_1->content)));
	if (!memcmp(&i_lstnew, node_lstnew_1->content, sizeof(int)))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(node_lstnew_1);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	t_list	*node_lstnew_2 = ft_lstnew("This is a test!");
	printf("Expected: This is a test!\nMy own  : %s\n", (char *)(node_lstnew_2->content));
	if (!memcmp("This is a test!", node_lstnew_2->content, 16))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(node_lstnew_2);
	printf("\n");
    printf(TEST_SEP);
	//Test 3
	printf("\nTest 3:\n");
	t_list	*node_lstnew_3 = ft_lstnew(NULL);
	printf("Expected: (null)\nMy own  : %s\n", (char *)(node_lstnew_3->content));
	if (node_lstnew_3->content == NULL)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	free(node_lstnew_3);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstadd_front
	printf(TEST_HEADER);
	printf("Testing ft_lstadd_front... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	int		*i_lstnew_2 = malloc(sizeof(int));
	char	*str_test1 = malloc(sizeof(char) * 16);
	*i_lstnew_2 = 255;
	ft_strlcpy(str_test1, "This is a test!", 16);
	t_list	*head = NULL;
	t_list *node_1 = ft_lstnew(i_lstnew_2);
	t_list *node_2 = ft_lstnew(str_test1);
	ft_lstadd_front(&head, node_1);
	ft_lstadd_front(&head, node_2);
	printf("Expected: Node 1 -> This is a test! | Node 2 -> 255\nMy own  : Node 1 -> %s | Node 2 -> %d\n", (char *)(head->content), *(int *)(head->next->content));
	if (!memcmp("This is a test!", head->content, 16) && !memcmp(i_lstnew_2, head->next->content, sizeof(int)))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	char	*str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	char	*str_test2 = malloc(sizeof(char) * 16);
	char	*str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	ft_lstadd_front(&head, ft_lstnew(str_test2));
	ft_lstadd_front(&head, ft_lstnew(str_test3));
	ft_lstadd_front(&head, ft_lstnew(str_test4));
	printf("Expected:\n");
	printf("Node->content = World\n");
	printf("Node->content = Hello\n");
	printf("Node->content = This is a test!\n");
	printf("My own:\n");
	ft_lstiter(head, print_node_str);
	printf("\n");
	if (!memcmp("World", head->content, 6) && !memcmp(head->next->content, "Hello", 6) && !memcmp(head->next->next->content, "This is a test!", 16))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstsize
	printf(TEST_HEADER);
	printf("Testing ft_lstadd_front... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	str_test2 = malloc(sizeof(char) * 16);
	str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	ft_lstadd_front(&head, ft_lstnew(str_test2));
	ft_lstadd_front(&head, ft_lstnew(str_test3));
	ft_lstadd_front(&head, ft_lstnew(str_test4));
	printf("Expected: 3\nMy own  : %d\n", ft_lstsize(head));
	if (ft_lstsize(head) == 3)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	head = NULL;
	printf("Expected: 0\nMy own  : %d\n", ft_lstsize(head));
	if (ft_lstsize(head) == 0)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstlast
	printf(TEST_HEADER);
	printf("Testing ft_lstlast... \n");
	printf(TEST_HEADER);
	//Test 1
	str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	str_test2 = malloc(sizeof(char) * 16);
	str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	ft_lstadd_front(&head, ft_lstnew(str_test2));
	ft_lstadd_front(&head, ft_lstnew(str_test3));
	ft_lstadd_front(&head, ft_lstnew(str_test4));
	printf("Expected: Node->content = This is a test!\nMy own  : ");
	print_node_str(ft_lstlast(head)->content);
	printf("\n");
	if (!memcmp("This is a test!", ft_lstlast(head)->content, 16))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstadd_back
	printf(TEST_HEADER);
	printf("Testing ft_lstadd_back... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	str_test2 = malloc(sizeof(char) * 16);
	str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(str_test2));
	ft_lstadd_back(&head, ft_lstnew(str_test3));
	ft_lstadd_back(&head, ft_lstnew(str_test4));
	printf("Expected:\n");
	printf("Node->content = This is a test!\n");
	printf("Node->content = Hello\n");
	printf("Node->content = World\n");
	printf("My own:\n");
	ft_lstiter(head, print_node_str);
	printf("\n");
	if (!memcmp("This is a test!", head->content, 16) && !memcmp(head->next->content, "Hello", 6) && !memcmp(head->next->next->content, "World", 6))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//Test 2
	printf("\nTest 2:\n");
	str_test2 = malloc(sizeof(char) * 16);
	ft_strlcpy(str_test2, "This is a test!", 16);
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(str_test2));
	printf("Expected:\n");
	printf("Node->content = This is a test!\n");
	printf("My own:\n");
	ft_lstiter(head, print_node_str);
	printf("\n");
	if (!memcmp("This is a test!", head->content, 16))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstdelone
	printf(TEST_HEADER);
	printf("Testing ft_lstadd_back... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	str_test2 = malloc(sizeof(char) * 16);
	str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(str_test2));
	ft_lstadd_back(&head, ft_lstnew(str_test3));
	ft_lstadd_back(&head, ft_lstnew(str_test4));
	t_list	*aux = head->next->next;	
	ft_lstdelone(head->next, free);
	head->next = aux;
	printf("Expected:\n");
	printf("Node->content = This is a test!\n");
	printf("Node->content = World\n");
	printf("My own:\n");
	ft_lstiter(head, print_node_str);
	printf("\n");
	if (!memcmp("This is a test!", head->content, 16) && !memcmp(head->next->content, "World", 6))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstclear
	printf(TEST_HEADER);
	printf("Testing ft_lstclear... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	str_test2 = malloc(sizeof(char) * 16);
	str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	t_list	*node_3;
	node_1 = ft_lstnew(str_test2);
	node_2 = ft_lstnew(str_test3);
	node_3 = ft_lstnew(str_test4);
	ft_lstadd_back(&head, node_1);
	ft_lstadd_back(&head, node_2);
	ft_lstadd_back(&head, node_3);
	ft_lstclear(&head, free);
	printf("Expected: (null)\n");
	printf("My own  : %s\n", (char *)head);
	if (head == NULL)
		printf("OK :D\n");
	else
		printf("KO :(\n");
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstiter
	printf(TEST_HEADER);
	printf("Testing ft_lstiter... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	str_test2 = malloc(sizeof(char) * 16);
	str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(str_test2));
	ft_lstadd_back(&head, ft_lstnew(str_test3));
	ft_lstadd_back(&head, ft_lstnew(str_test4));
	ft_lstiter(head, tester_2);
	printf("Expected:\n");
	printf("Node->content = THIS IS A TEST!\n");
	printf("Node->content = HELLO\n");
	printf("Node->content = WORLD\n");
	printf("My own:\n");
	ft_lstiter(head, print_node_str);
	printf("\n");
	if (!memcmp("THIS IS A TEST!", head->content, 16) && !memcmp(head->next->content, "HELLO", 6) && !memcmp(head->next->next->content, "WORLD", 6))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	printf("\n");
    printf(TEST_SEP);
	//----------------------------------------------------------------
	//Tests for ft_lstmap
	printf(TEST_HEADER);
	printf("Testing ft_lstmap... \n");
	printf(TEST_HEADER);
	//Test 1
	printf("\nTest 1:\n");
	t_list	*dup_list;
	str_test3 = malloc(sizeof(char) * (ft_strlen("Hello") + 1));
	str_test2 = malloc(sizeof(char) * 16);
	str_test4 = malloc(sizeof(char) * (ft_strlen("World") + 1));
	ft_strlcpy(str_test2, "This is a test!", 16);
	ft_strlcpy(str_test3, "Hello", 6);
	ft_strlcpy(str_test4, "World", 6);
	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(str_test2));
	ft_lstadd_back(&head, ft_lstnew(str_test3));
	ft_lstadd_back(&head, ft_lstnew(str_test4));
	dup_list = ft_lstmap(head, (void *(*)(void *))ft_strdup, free);
	printf("Expected:\n");
	ft_lstiter(head, print_node_str);
	printf("\n");
	printf("My own:\n");
	ft_lstiter(dup_list, print_node_str);
	printf("\n");
	if (!memcmp("This is a test!", dup_list->content, 16) && !memcmp(dup_list->next->content, "Hello", 6) && !memcmp(dup_list->next->next->content, "World", 6))
		printf("OK :D\n");
	else
		printf("KO :(\n");
	ft_lstclear(&head, free);
	ft_lstclear(&dup_list, free);
	printf("\n");
    printf(TEST_SEP);
	
	return (0);
}
