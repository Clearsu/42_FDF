/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:14:16 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/16 14:10:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

size_t	word_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			cnt++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (cnt);
}

char	*put_word(char const *s, char c)
{
	char	*word;
	size_t	i;
	size_t	len;

	i = 0;
	len = word_len(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (word);
	while (i < len)
		*(word + i++) = *s++;
	*(word + i) = '\0';
	return (word);
}

void	*ft_free(int i, char **p)
{
	while (i > 0)
		free(*(p + i--));
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	p = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (!p)
		return (p);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			*(p + i) = put_word(s, c);
			if (!(*(p + i)))
				return (ft_free(i, p));
			i++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	*(p + i) = NULL;
	return (p);
}
