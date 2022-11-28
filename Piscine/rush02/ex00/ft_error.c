/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:48:05 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/20 23:23:25 by maserrie         ###   ########.fr       */
/*   Updated: 2022/11/19 18:50:47 by clemoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_error(int n, char *file_name)
{
	if (n == 1)
		ft_puterror("Life is always positive.\n");
	if (n == 2)
		ft_puterror("Error, at least put numbers here.\n");
	if (n == 3)
	{
		ft_puterror("Error, \'");
		ft_puterror(file_name);
		ft_puterror("\' not readable.\n");
	}
	if (n == 4)
		ft_puterror("Error, u asked too much here.\n");
	if (n == 5)
		ft_puterror("Error, bro u know what a dico is ?\n");
	return (-1);
}

void	ft_error2(int n, char **dic, char **numbers, int *a)
{
	int	i;
	int	k;

	i = 0;
	k = n;
	if (n < 0)
	{
		ft_puterror("Error, bro u know what a dico is ?\n");
		n *= -1;
	}
	else if (n > 0)
		ft_puterror("Error, void is not that cool.\n");
	if (a)
		free(a);
	ft_freetab(dic);
	if (!numbers)
		return ;
	while (i <= n)
	{
		free(numbers[i]);
		i++;
	}
	if (k > 0)
		free(numbers[i]);
	free(numbers);
}
