/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksyntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:52:38 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/05 03:59:00 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_checksyntax(char *str)
{
	return (ft_checksquotes(str));
}

int	ft_checksquotes(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == '\'')
			count++;
		index++;
	}
	if (count % 2 != 0)
	{
		ft_printf("bash: syntex error, uneven number of single quotes\n");
		return (0);
	}
	else
		return (ft_checkdquotes(str));
}

int	ft_checkdquotes(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == '\"')
			count++;
		index++;
	}
	if (count % 2 != 0)
	{
		ft_printf("bash: syntex error, uneven number of double quotes\n");
		return (0);
	}
	else
		return (ft_checkparenthesis(str));
}

int	ft_checkparenthesis(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == '(')
			count++;
		if (str[index] == ')')
			count--;
		index++;
	}
	if (count != 0)
	{
		ft_printf("bash: syntex error, uneven number of parenthesis\n");
		return (0);
	}
	else
		return (ft_checkcbrackets(str));
}

int	ft_checkcbrackets(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] == '{')
			count++;
		if (str[index] == '}')
			count--;
		index++;
	}
	if (count != 0)
	{
		ft_printf("bash: syntex error, uneven number of brackets\n");
		return (0);
	}
	else
		return (1);
}
