/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:17:01 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/29 19:06:48 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**str_split;

	printf("argc: %d %s\n", argc, envp[0]);
	while (argc--)
		printf("%s\n", argv[argc]);
	while (1)
	{
		str = readline("minishel$ ");
		str_split = ft_split(str, ' ');
		add_history(str);
		ft_printstr(str_split);
	}
	return (0);
}

void	ft_printstr(char **str_split)
{
	int	word_count;
	int	index;
	int count;

	word_count = strsplit_count(str_split);
	index = 1;
	while (index <= word_count)
	{
		ft_printf("o------------");
		index++;
	}
	ft_printf("o\n");
	ft_printf("|");
	index = 1;
	while (index <= word_count)
	{
		ft_printf("   PARAM %d  |", index);
		index++;
	}
	ft_printf("\n");
	index = 1;
	while (index <= word_count)
	{
		ft_printf("o------------");
		index++;
	}
	ft_printf("o\n");
	ft_printf("|");
	index = 0;
	while (*str_split)
	{
		ft_printf("%11s |", *str_split);
		index++;
		str_split++;
	}
	while (index < word_count)
	{
		count = 0;
		while (count < 8)
			ft_printf(" ");
		ft_printf("|");
		index++;
	}
	ft_printf("\n");
	index = 1;
	while (index <= word_count)
	{
		ft_printf("o------------", index);
		index++;
	}
	ft_printf("o\n");
}

int	strsplit_count(char **str_split)
{
	int	count;

	count = 0;
	while (*str_split)
	{
		count++;
		str_split++;
	}
	printf("count: %d\n", count);
	return (count);
}
