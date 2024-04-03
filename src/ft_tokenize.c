/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:14:38 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/03 03:00:43 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_checkoperator(char *c)
{
	int		index;
	size_t	len;
	char	*out;

	len = ft_strlen(c);
	index = 0;
	while (c[index] != '\0')
	{
		if ((c[index] == '<') || (c[index] == '>') || (c[index] == '|'))
		{
			if (ft_checknextchar(c, index))
				index++;
			len += 2;
		}
		index++;
	}
	out = (char *)malloc(sizeof(char) * len);
	if (!out)
		return (NULL);
	out = ft_tokenize(out, c, len);
	return (out);
}

char	*ft_tokenize(char *out, char *c, int len)
{
	int	index;
	int	offset;

	index = 0;
	offset = 0;
	while (index < len)
	{
		if ((c[index - offset] == '<') || (c[index - offset] == '>') \
			|| (c[index - offset] == '|'))
		{
			index = ft_handleredir(out, c, index, offset);
			offset += 2;
		}
		else
			out[index] = c[index - offset];
		index++;
	}
	out[index] = '\0';
	free(c);
	return (out);
}

int	ft_handleredir(char *out, char *c, int index, int offset)
{
	int	redir_type;

	out[index] = ' ';
	offset++;
	index++;
	out[index] = c[index - offset];
	redir_type = ft_checknextchar(c, index - offset);
	if (redir_type > 0)
	{
		index++;
		out[index] = c[index - offset];
	}
	if (redir_type == 2)
	{
		index++;
		out[index] = c[index - offset];
	}
	offset++;
	index++;
	out[index] = ' ';
	return (index);
}

int	ft_checknextchar(char *c, int index)
{
	if (ft_strncmp(&c[index], DLESSDASH, 3) == 0)
		return (2);
	else if (c[index] == c[index + 1])
		return (1);
	else if (ft_strncmp(&c[index], LESSAND, 2) == 0)
		return (1);
	else if (ft_strncmp(&c[index], GREATAND, 2) == 0)
		return (1);
	else if (ft_strncmp(&c[index], LESSGREAT, 2) == 0)
		return (1);
	else if (ft_strncmp(&c[index], CLOBBER, 2) == 0)
		return (1);
	else
		return (ft_checknextcharb(c, index));
}

int	ft_checknextcharb(char *c, int index)
{
	if (ft_strncmp(&c[index], RBRACE, 1) == 0)
		return (1);
	else if (ft_strncmp(&c[index], LBRACE, 1) == 0)
		return (1);
	else if (ft_strncmp(&c[index], LPARAN, 1) == 0)
		return (1);
	else if (ft_strncmp(&c[index], RPARAN, 1) == 0)
		return (1);
	else if (ft_strncmp(&c[index], D_SIGN, 1) == 0)
		return (1);
	else if (ft_strncmp(&c[index], "\'", 1) == 0)
		return (1);
	else if (ft_strncmp(&c[index], "\"", 1) == 0)
		return (1);		
	else
		return (0);
}
