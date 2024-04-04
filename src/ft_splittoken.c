/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splittoken.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:18:04 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/04 22:31:18 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_splittoken(char *str)
{
	char	**out;
	char	*str_temp;
	int		token_count;
	int		index;
	int		start;

	index = 0;
	start = 0;
	out = (char **)malloc(sizeof(char *) * 1);
	out[0] = NULL;
	token_count = 0;
	while (str[index] != '\0')
	{
		while (str[index] && (str[index] == ' ' || \
			str[index] == '\t' || str[index] == '\n'))
			index++;
		if (str[index] != '\0')
		{
			token_count++;
			start = index;
		}
		else
			break ;
		while (str[index] != '\0' && (str[index] != ' ' && \
			str[index] != '\t' && str[index] != '\n'))
			index++;
		str_temp = malloc(sizeof(char) * (index - start + 1));
		if (!str_temp)
			return (NULL);
		str_temp = ft_assignstring(str_temp, str, start, index);
		out = ft_realloc_dp(out, str_temp, token_count + 1);
	}
	return (out);
}

char	*ft_assignstring(char *in, char *str, int start, int end)
{
	int		count;
	char	*out;

	count = 0;
	out = in;
	while (start < end)
	{
		out[count] = str[start];
		count++;
		start++;
	}
	out[count] = '\0';
	return (out);
}

char	**ft_realloc_dp(char **s, char *input, int len)
{
	char	**out;
	int		old_size;
	int		count;

	count = 0;
	out = (char **)malloc(sizeof(char *) *(len + 1));
	old_size = ft_strlen_dp(s);
	printf("\nold_size: %d\n", old_size);
	printf("START\n");
	printf("input: %s\n", input);
	while (count < old_size)
	{
		out[count] = s[count];
		printf("out[%d]: %s\n", count, out[count]);
		count++;
	}
	printf("END\n");
	out[count] = input;
	printf("out[%d]: %s\n", count, out[count]);
	count++;
	out[count] = NULL;
	return (out);
}

int	ft_strlen_dp(char **s)
{
	int	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}

void	free_pointer(char *s)
{
	int	count;
	int	len;

	len = ft_strlen(s);
	count = 0;
	while (count < len)
	{
		// free(s[count]);
		count++;
	}
}
