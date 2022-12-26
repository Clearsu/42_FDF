/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:15:04 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/14 11:29:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_cp;
	const char	*src_cp;
	size_t		i;

	dst_cp = (char *)dst;
	src_cp = (const char *)src;
	i = 0;
	if (dst_cp < src_cp)
	{
		while (i < len)
		{
			*(dst_cp + i) = *(src_cp + i);
			i++;
		}
	}
	else if (src_cp < dst_cp)
	{
		while (i < len)
		{
			*(dst_cp + len - i - 1) = *(src_cp + len - i - 1);
			i++;
		}
	}
	return (dst);
}
