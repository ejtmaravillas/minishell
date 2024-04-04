/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:17:01 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/04 20:28:47 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*str;
	char	**str_split;

	while (1)
	{
		str = readline("minishell$ ");
		add_history(str);
		if (ft_checksyntax(str))
		{
			str = ft_checkoperator(str);
			str_split = ft_splittoken(str);
			free(str);
			ft_printstr(str_split);
			ft_freesplit(str_split);
		}
	}
	return (0);
}

void	ft_freesplit(char **str)
{
	int	len;
	int	index;

	len = strsplit_size(str);
	index = 0;
	while (index < len)
	{
		free(str[index]);
		index++;
	}
	free(str);
}

int	strsplit_size(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
