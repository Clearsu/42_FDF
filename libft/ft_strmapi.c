/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:23:00 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/16 13:53:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	i = 0;
	if (s == NULL)
		return (ft_calloc(1, 1));
	if (f == NULL)
		return (ft_strdup(s));
	p = ft_strdup(s);
	if (!p)
		return (p);
	while (*(p + i) != '\0')
	{
		*(p + i) = f(i, *(p + i));
		i++;
	}
	return (p);
}
