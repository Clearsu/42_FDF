/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:51:51 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/13 17:00:12 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_num_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;

	len = get_num_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	if (n == 0)
		*p = '0';
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	p[len--] = '\0';
	while (n > 0)
	{
		p[len--] = n % 10 + '0';
		n /= 10;
	}
	return (p);
}
