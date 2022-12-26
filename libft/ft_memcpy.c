/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:05:57 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/14 11:26:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_cp;
	const char	*src_cp;

	if (dst == src)
		return (dst);
	dst_cp = dst;
	src_cp = src;
	while (n-- > 0)
		*dst_cp++ = *src_cp++;
	return (dst);
}
