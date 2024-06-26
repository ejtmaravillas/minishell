/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:14:38 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/11 18:27:33 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

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
			(c[index] == ')'))
			len += 2;
		index++;
	}
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	out = ft_tokenize(out, c, len);
	free(c);
	return (out);
}
/// @brief tokenize the input (detect metacharacters)
/// @param out - output string with metacharacters separated with spaces
/// @param i - index of out
/// @param o - offset of out from c
/// @param c - input string from readline
/// @param len length of output with spaces included (from metacharacters)
/// @return 

char	*ft_tokenize(char *out, char *c, int len)
{
	int	i;
	int	o;

	i = -1;
	o = 0;
	while (++i < len)
	{
		if ((c[i - o] == '<') || (c[i - o] == '>') || \
			((ft_isdigit(c[i - o]) > 0) && (ft_checkpid(c, i, o))))
		{
			i = ft_handleredir(out, c, i, o);
			o += 2;
		}
		else if ((c[i - o] == '|') || (c[i - o] == '(') || (c[i - o] == ')') \
			|| (c[i - o] == '&') || (c[i - o] == ';'))
		{
			i = ft_handleoper(out, c, i, o);
			o += 2;
		}
		else
			out[i] = c[i - o];
	}
	out[i] = '\0';
	return (out);
}

bool	ft_checkpid(char *c, int index, int offset)
{
	if ((index - offset) > 0)
	{
		if (ft_isspace(c[index - offset - 1]) > 0)
		{
			while (ft_isdigit(c[index - offset]) != 0)
			{
				if ((c[index + 1 - offset] == '>') || \
					(c[index + 1 - offset] == '<'))
					return (true);
				index++;
			}
		}
	}
	else
	{
		while (ft_isdigit(c[index - offset]) != 0)
		{
			if ((c[index + 1 - offset] == '>') || \
				(c[index + 1 - offset] == '<'))
				return (true);
			index++;
		}
	}
	return (false);
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
	while (ft_isdigit(c[++index - offset]) != 0)
		out[index] = c[index - offset];
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
