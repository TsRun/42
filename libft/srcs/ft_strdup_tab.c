/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:37:49 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 12:50:33 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_tab(size_t ac, char **av)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = (char **)malloc((ac) * sizeof(char *));
	while (i < ac)
	{
		tab[i] = ft_strdup(av[i]);
		i++;
	}
	return (tab);
}
