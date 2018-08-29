/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:51:22 by agabrie           #+#    #+#             */
/*   Updated: 2018/05/28 14:50:27 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char *str;

	str = (char *)(s);
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
	return (str);
}