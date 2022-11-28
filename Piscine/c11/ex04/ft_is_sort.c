/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:29:22 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/15 00:39:31 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	test;

	test = 1;
	i = 0;
	while (i < length - 1 && test)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			test = 0;
		i++;
	}
	if (test)
		return (1);
	test = 1;
	i = 0;
	while (i < length - 1 && test)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			test = 0;
		i++;
	}
	return (test);
}
