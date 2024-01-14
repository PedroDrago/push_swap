/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 01:58:34 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/08 19:54:28 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_split_count(char const *str, char sep)
// {
// 	int	index;
// 	int	splits;
//
// 	if (str == 0 || str[0] == 0)
// 		return (0);
// 	index = 1;
// 	splits = 0;
// 	if (str[0] != sep)
// 		splits++;
// 	while (str[index] != '\0')
// 	{
// 		if (str[index] != sep && str[index - 1] == sep)
// 			splits++;
// 		index++;
// 	}
// 	return (splits);
// }
//
// static int	ft_next_split_count(char const *str, char sep, int index)
// {
// 	int	count;
//
// 	count = 0;
// 	while (str[index] == sep && str[index] != '\0')
// 		index++;
// 	while (str[index] != '\0' && str[index] != sep)
// 	{
// 		count++;
// 		index++;
// 	}
// 	return (count);
// }
//
// static char	**ft_free_all(char **str_tab, int max)
// {
// 	int	index;
//
// 	index = 0;
// 	while (index < max && str_tab[index] != 0)
// 	{
// 		free(str_tab[index]);
// 		index++;
// 	}
// 	free(str_tab);
// 	return (0);
// }
//
// static char	**ft_split_split(char const *s, char c, char **tab_str)
// {
// 	int		char_s;
// 	int		tab_count;
// 	int		char_tab;
//
// 	char_s = 0;
// 	tab_count = -1;
// 	while (++tab_count < ft_split_count(s, c))
// 	{
// 		char_tab = 0;
// 		tab_str[tab_count] = (char *) malloc(sizeof(char)
// 				* ft_next_split_count(s, c, char_s) + 1);
// 		if (!(tab_str[tab_count]))
// 			return (ft_free_all(tab_str, tab_count));
// 		while (s[char_s] != '\0' && s[char_s] == c)
// 			char_s++;
// 		while (s[char_s] != '\0' && s[char_s] != c)
// 			tab_str[tab_count][char_tab++] = s[char_s++];
// 		tab_str[tab_count][char_tab] = '\0';
// 	}
// 	tab_str[tab_count] = 0;
// 	return (tab_str);
// }
//
// char	**ft_split(char const *s, char c)
// {
// 	char	**tab_str;
//
// 	if (s == 0)
// 		return (0);
// 	tab_str = (char **) malloc(sizeof(*tab_str) * (ft_split_count(s, c) + 1));
// 	if (!(tab_str))
// 		return (0);
// 	tab_str = ft_split_split(s, c, tab_str);
// 	return (tab_str);
// }
static int	count_words(char const *str, char c)
{
	int	count;
	int	flag;
	int	str_count;

	count = 0;
	flag = 1;
	str_count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
	{
		if (str[count] == c)
			flag = 1;
		else if (str[count] && flag == 1 && ++str_count)
			flag = 0;
		count++;
	}
	return (str_count);
}

static char	*ft_newstring(char const *str, int count, int start, char c)
{
	char		*temp_string;
	int			count2;

	count2 = 0;
	temp_string = (char *)malloc(sizeof(char) * (count - start + 1));
	if (!temp_string)
		return (NULL);
	while (str[start] != c && str[start])
		temp_string[count2++] = str[start++];
	temp_string[count2] = '\0';
	return (temp_string);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		array_count;
	int		start;

	if (!s)
		return (NULL);
	count = 0;
	array_count = 0;
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	while (array_count < count_words(s, c))
	{
		if (s[count] != c && s[count])
		{
			start = count;
			while (s[count] != c && s[count])
				count++;
			array[array_count++] = ft_newstring(s, count, start, c);
		}
		count++;
	}
	array[array_count] = NULL;
	return (array);
}
