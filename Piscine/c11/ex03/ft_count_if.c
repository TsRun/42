/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:18:45 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/15 00:31:16 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	if (length <= 0)
		return (0);
	if (f(tab[0]))
		return (1 + ft_count_if(tab + 1, length - 1, f));
	return (ft_count_if(tab + 1, length - 1, f));
}
