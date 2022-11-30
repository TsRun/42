/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:02:54 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/29 19:14:04 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*res;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	res = ft_strnew(j - i + 1);
	if (!res)
		return (NULL);
	while (i < j)
	{
		res[k] = s[i];
		i++;
		k++;
	}
	res[k] = '\0';
	return (res);
}
