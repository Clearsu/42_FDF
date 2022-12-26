/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:57:19 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/19 13:34:18 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	is_in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	size_t			start;
	size_t			end;
	size_t			i;

	if (!s1)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (is_in_set(*(s1 + start), set) && start < end)
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (is_in_set(*(s1 + end), set) && end >= 0)
		end--;
	res = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (res);
	while (start <= end)
		*(res + i++) = *(s1 + start++);
	*(res + i) = '\0';
	return (res);
}
