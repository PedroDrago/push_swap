/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:17:57 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/10 00:24:26 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*joined;
	char	*start;

	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *) malloc (sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	start = joined;
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	*joined = '\0';
	return (start);
}
