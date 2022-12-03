/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:50:19 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 20:32:26 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	llen;

	if (!s)
		return (NULL);
	if (len < start || start >= ft_strlen(s))
		return (ft_strdup(""));
	llen = 0;
	while (llen < len && s[llen + start])
		llen++;
	str = (char *) ft_calloc(llen + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < llen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
