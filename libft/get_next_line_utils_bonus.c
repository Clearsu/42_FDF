/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:36:33 by jincpark          #+#    #+#             */
/*   Updated: 2022/10/06 16:19:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	char	*p;

	if (!s1 || !s2)
		return (0);
	i = 0;
	total_len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	p = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!p)
		return (p);
	while (*s1 != '\0')
		*(p + i++) = *s1++;
	while (*s2 != '\0')
		*(p + i++) = *s2++;
	*(p + i) = '\0';
	return (p);
}

char	*ft_strdup_gnl(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen_gnl(s1);
	i = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (p);
	while (i < len)
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
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
