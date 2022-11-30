/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:15:19 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 00:26:48 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab + i);
		i++;
	}
	free(tab);
}

static char	**ft_split2(char *str, size_t cpt)
{
	char	**tab;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	tab = (char **)malloc((cpt + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (c < cpt)
	{
		while (!str[i])
			i++;
		tab[c] = ft_strdup(str + i);
		if (!tab[c])
		{
			ft_free_tab(tab);
			return (NULL);
		}
		while (str[i])
			i++;
		c++;
	}
	tab[c] = 0;
	return (tab);
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	cpt;
	char	*str;
	char	**tab;
	int		test;

	i = 0;
	cpt = 0;
	str = ft_strdup(s);
	while (str[i])
	{
		test = 0;
		while (str[i] == c)
		{
			str[i] = 0;
			i++;
		}
		while (str[i] && str[i] != c)
		{
			i++;
			test = 1;
		}
		if (test)
			cpt++;
	}
	tab = ft_split2(str, cpt);
	ft_strdel(&str);
	return (tab);
}
