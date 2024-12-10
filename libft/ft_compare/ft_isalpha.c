/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:13:44 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/25 16:00:07 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
// returns char is alpha, 0 if not
int	ft_isalpha(int arg)
{
	if ((arg >= 'A' && arg <= 'Z') || (arg >= 'a' && arg <= 'z'))
		return (arg);
	return (0);
}
