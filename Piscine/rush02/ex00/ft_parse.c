/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:00:19 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/20 23:21:14 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	before_str(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != ' ' && str[i] && str[i] != ':')
		i++;
	res = ft_strndup(str, i);
	i = ft_atoi2(res);
	free(res);
	return (i);
}

char	*after_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != ':' && str[i])
		i++;
	if (!str[i])
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	return (ft_strdup(str + i));
}

int	ft_intab(int len, int *tab, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (i < len)
	{
		if (tab[i] == nb)
		{
			if (j != -1)
				return (-1);
			j = i;
		}
		i++;
	}
	return (j);
}

char	**creat_dic(int	*r_dict, char **numbers, int len)
{
	int		i;
	int		j;
	char	**dic;

	dic = malloc (40 * sizeof(char *));
	i = 0;
	while (i <= 31)
	{
		if (i < 20)
			j = ft_intab(len, r_dict, i);
		else if (i < 29)
			j = ft_intab(len, r_dict, (i - 18) * 10);
		else if (i == 29)
			j = ft_intab(len, r_dict, 1000);
		else if (i == 30)
			j = ft_intab(len, r_dict, 1000000);
		else if (i == 31)
			j = ft_intab(len, r_dict, 1000000000);
		if (j == -1)
			return ((void)ft_error2(5, dic, 0, 0), (char **) 0);
		dic[i] = ft_strdup(numbers[j]);
		i++;
	}
	dic[i] = 0;
	return (dic);
}

char	**ft_parse(char **dic)
{
	char	**numbers;
	int		*r_dict;
	int		i;
	int		len;

	len = ft_tabstr_len(dic);
	i = 0;
	r_dict = malloc(len * 4);
	numbers = malloc((len + 1) * sizeof(char *));
	while (dic[i])
	{
		r_dict[i] = before_str(dic[i]);
		numbers[i] = after_str(dic[i]);
		if (r_dict[i] == -1)
			return ((void)ft_error2(-i, dic, numbers, r_dict), (char **) 0);
		if (numbers[i][0] == 0)
			return ((void)ft_error2(i, dic, numbers, r_dict), (char **) 0);
		i++;
	}
	numbers[i] = 0;
	ft_freetab(dic);
	dic = creat_dic(r_dict, numbers, len);
	free(r_dict);
	ft_freetab(numbers);
	return (dic);
}
