/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <agabrie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:04:37 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/27 11:00:45 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int negative;
	int number;
	int index;

	negative = 1;
	number = 0;
	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		negative = ft_isneg(str[index]);
		index++;
	}
	while (str[index])
	{
		if (ft_isdigit(str[index]))
		{
			number += str[index++] - '0';
			if (ft_isdigit(str[index]))
				number *= 10;
		}
		else
			break ;
	}
	return (number * negative);
}
