/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:10:47 by emaravil          #+#    #+#             */
/*   Updated: 2024/03/31 21:38:38 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_astnode	*p_arg(const char **cmnd, char **errmsg)
{
	const char	*start;
	size_t		len;
	char		*value;

	skip_whitespace(cmnd);
	start = *cmnd;
	while (**cmnd && !ft_isspace(**cmnd))
		(*cmnd)++;
	len = *cmnd - start;
	if (len == 0)
	{
		*errmsg = "Expected argument";
		return (NULL);
	}
	value = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(value, start, len);
	return (create_node(argmnt, value));
}

void	skip_whitespace(const char **cmnd)
{
	while (**cmnd && ft_isspace(**cmnd))
		(*cmnd)++;
}
