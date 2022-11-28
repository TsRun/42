/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:21:05 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/10 18:14:18 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = min;
	if (min >= max)
		return (0);
	tab = malloc ((max - min + 1) * sizeof(int));
	while (i < max)
	{
		tab[i - min] = i;
		i++;
	}
	return (tab);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		range = 0;
		return (0);
	}
	*range = ft_range(min, max);
	return (max - min);
}
