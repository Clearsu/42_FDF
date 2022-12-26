/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:41:44 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/19 13:34:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (!s)
		return ((char *)s);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	i = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (p);
	while (i < len)
	{
		*(p + i) = *(s + start);
		i++;
		start++;
	}
	*(p + i) = '\0';
	return (p);
}
