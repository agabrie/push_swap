/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:22:33 by agabrie           #+#    #+#             */
/*   Updated: 2018/06/03 15:22:38 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**stra;
	int		i;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_wcount(s, c, 0);
	len = 0;
	stra = (char **)ft_memalloc((wc + 1) * sizeof(char *));
	if (!stra)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_find_word(s, c, stra, i++);
		s += len;
	}
	stra[wc] = 0;
	return (stra);
}
