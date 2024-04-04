/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:14:38 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/04 21:43:12 by emaravil         ###   ########.fr       */
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
		if ((c[index] == '<') || (c[index] == '>'))
		{
			index += ft_checknextchar(c, index);
			len += 2;
		}
		else if ((c[index] == '|') || (c[index] == '(') || \
			(c[index] == ')') || (c[index] == '(') || (c[index] == '&') || \
			(c[index] == ';'))
			len += 2;
		index++;
	}
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	printf("len: %lu\n", len);
	out = ft_tokenize(out, c, len);
	printf("out: %s\n", out);
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
		if ((c[index - offset] == '<') || (c[index - offset] == '>'))
		{
			index = ft_handleredir(out, c, index, offset);
			offset += 2;
		}
		else if ((c[index - offset] == '|') || (c[index - offset] == '(') || \
			(c[index - offset] == ')') || (c[index - offset] == '&') || \
			(c[index - offset] == ';'))
		{
			index = ft_handleoper(out, c, index, offset);
			offset += 2;
		}
		else
			out[index] = c[index - offset];
		index++;
	}
	printf("index: %d\n", index);
	out[index] = '\0';
	free(c);
	return (out);
}

int	ft_handleoper(char *out, char *c, int index, int offset)
{
	out[index] = ' ';
	offset++;
	index++;
	out[index] = c[index - offset];
	offset++;
	index++;
	out[index] = ' ';
	return (index);
}

int	ft_handleredir(char *out, char *c, int index, int offset)
{
	int	redir_type;

	out[index] = ' ';
	offset++;
	index++;
	out[index] = c[index - offset];
	redir_type = ft_checknextchar(c, index - offset);
	if (redir_type == 1)
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
