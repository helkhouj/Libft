#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper to print test results
void	print_test(const char *func_name, int passed)
{
	if (passed)
		printf("[PASS] %s\n", func_name);
	else
		printf("[FAIL] %s\n", func_name);
}

// Test for memory leaks (manually check with valgrind)
void	test_leaks(void)
{
	printf("==== MEMORY LEAK CHECK ====\n");
	// Test ft_calloc
	char *leak_test = ft_calloc(10, sizeof(char));
	free(leak_test);

	// Test ft_strdup
	leak_test = ft_strdup("Memory Leak Test");
	free(leak_test);

	// Test ft_substr
	leak_test = ft_substr("Test for Leaks", 5, 10);
	free(leak_test);

	// Test ft_split
	char **split_test = ft_split("Test for memory leaks", ' ');
	for (int i = 0; split_test[i]; i++)
		free(split_test[i]);
	free(split_test);

	printf("[CHECK MANUALLY WITH VALGRIND]\n");
}

// Basic test cases for ft_strlen
void	test_strlen(void)
{
	int result = 1;

	if (ft_strlen("") != strlen(""))
		result = 0;
	if (ft_strlen("Hello") != strlen("Hello"))
		result = 0;
	if (ft_strlen("This is a longer string.") != strlen("This is a longer string."))
		result = 0;

	print_test("ft_strlen", result);
}

// Basic test cases for ft_atoi
void	test_atoi(void)
{
	int result = 1;

	if (ft_atoi("1234") != atoi("1234"))
		result = 0;
	if (ft_atoi("-1234") != atoi("-1234"))
		result = 0;
	if (ft_atoi("   42") != atoi("   42"))
		result = 0;
	if (ft_atoi("0") != atoi("0"))
		result = 0;

	print_test("ft_atoi", result);
}

// Basic test cases for ft_split
void	test_split(void)
{
	char **result = ft_split("Hello world libft split", ' ');
	int passed = 1;

	if (!result || strcmp(result[0], "Hello") || strcmp(result[1], "world") || strcmp(result[2], "libft") || strcmp(result[3], "split"))
		passed = 0;

	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	print_test("ft_split", passed);
}

// Basic test cases for ft_substr
void	test_substr(void)
{
	char *result = ft_substr("Hello, world!", 7, 5);
	int passed = result && strcmp(result, "world") == 0;

	free(result);
	print_test("ft_substr", passed);
}

// Basic test cases for ft_strjoin
void	test_strjoin(void)
{
	char *result = ft_strjoin("Hello, ", "world!");
	int passed = result && strcmp(result, "Hello, world!") == 0;

	free(result);
	print_test("ft_strjoin", passed);
}

// Run all tests
int	main(void)
{
	printf("==== LIBFT TESTING ====\n");

	// Basic tests
	test_strlen();
	test_atoi();
	test_split();
	test_substr();
	test_strjoin();

	// Memory leak checks
	test_leaks();

	return (0);
}