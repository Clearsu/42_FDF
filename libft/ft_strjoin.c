/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:51:26 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/16 13:53:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	char	*p;

	if (!s1 || !s2)
		return (0);
	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
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
