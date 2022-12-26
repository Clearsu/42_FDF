/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:27:00 by jincpark          #+#    #+#             */
/*   Updated: 2022/07/14 13:06:36 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_rev(char *str, int i, int fd)
{
	while (i >= 0)
		ft_putchar_fd(*(str + i--), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	char	nums[11];

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (n > 0)
	{
		nums[i++] = n % 10 + '0';
		n /= 10;
	}
	print_rev(nums, i - 1, fd);
}
