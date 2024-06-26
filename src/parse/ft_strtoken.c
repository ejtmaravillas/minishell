/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoken.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:12:36 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/11 18:28:55 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

char	**str_token(char **str_input)
{
	int				len;
	char			**out;
	int				count;

	out = (char **)malloc(sizeof(char *) * 1);
	out[0] = NULL;
	len = ft_strlen_dp(str_input);
	count = 0;
	while (str_input[count] != NULL)
	{
		if (str_input[count][0] != '\"' && str_input[count][0] != '\'')
		{
			out = ft_handletokens(out, ft_checkoperator(str_input[count]));
		}
		else
			out = ft_realloc_dp(out, str_input[count], ft_strlen_dp(out) + 1);
		count++;
	}
	free(str_input);
	return (out);
}

char	**ft_handletokens(char **outdp, char *str)
{
	char	**str_split;
	int		token_count;
	int		count;

	str_split = ft_split(str, ' ');
	token_count = ft_strlen_dp(str_split);
	count = 0;
	while (count < token_count)
	{
		outdp = ft_realloc_dp(outdp, str_split[count], ft_strlen_dp(outdp) + 1);
		count++;
	}
	return (outdp);
}

t_tokens	*tokenize_input(char **str_token)
{
	t_tokens	*head;
	t_tokens	*tail;
	t_tokens	*token;

	head = NULL;
	tail = NULL;
	token = NULL;
	while (*str_token != NULL)
	{
		token = (t_tokens *)malloc(sizeof(t_tokens));
		if (!token)
			handle_errors("Memory allocation of tokens failed\n");
		token->type = WORD;
		if (ft_strncmp(*str_token, "|", 1) == 0)
			token->type = PIPE;
		else if ((ft_strchr(*str_token, '>') > 0) || \
			(ft_strchr(*str_token, '<') > 0))
			token->type = REDIR;
		token->value = ft_token_value(*str_token);
		head = ft_sethead_token(head, tail, token);
		str_token++;
	}
	return (head);
}

char	*ft_token_value(char *str_token)
{
	char	*token_val;

	token_val = malloc(sizeof(char) * (ft_strlen(str_token)) + 1);
	ft_strlcpy(token_val, str_token, ft_strlen(str_token) + 1);
	return (token_val);
}

t_tokens	*ft_sethead_token(t_tokens *head, t_tokens *tail, t_tokens *token)
{
	t_tokens	*s;

	s = head;
	token->next = NULL;
	if (!head)
	{
		head = token;
		tail = token;
		return (head);
	}
	while (s != NULL)
	{
		if (s->next == NULL)
			break ;
		s = s->next;
	}
	s->next = token;
	return (head);
}
