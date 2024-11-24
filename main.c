#include "libft.h"

void	debug(void *content)
{
	printf("%s, ", (char *)content);
}

void prehash(void *content)
{
	if (content && *((char *)content))
		*((char *)content) = '#';
}

void	*posthash(void *content)
{
	char	*newstr;

	newstr = ft_strdup(content);
	for (int i = 0; newstr && newstr[i]; i++)
		if (i % 2 == 0)
			newstr[i] = '#';
	return (newstr);
}

int	main(int argc, const char **argv)
{
	size_t	i = 0;
	t_list	*list_argv = NULL;

	while (i < argc)
		ft_lstadd_back(&list_argv, ft_lstnew(ft_strdup(argv[i++])));
	ft_lstiter(list_argv, prehash);
	printf("prehash: "); ft_lstiter(list_argv, debug); printf("\n");
	t_list	*list_posthash = ft_lstmap(list_argv, posthash, free);
	printf("posthash: "); ft_lstiter(list_posthash, debug); printf("\n");
	ft_lstclear(&list_argv, free);	ft_lstclear(&list_posthash, free);
	return (0);
}
