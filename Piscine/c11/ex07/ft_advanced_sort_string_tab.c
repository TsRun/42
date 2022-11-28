/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:33:14 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/15 02:31:05 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapstr(char **s1, char **s2)
{
	char	*str;

	str = *s1;
	*s1 = *s2;
	*s2 = str;
}

void	ft_sort_int_str(char **tab, int size, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swapstr(tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	ft_sort_int_str(tab, i, cmp);
}
