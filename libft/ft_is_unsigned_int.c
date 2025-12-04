/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:06:42 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/06/10 17:24:24 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unisgnednbr_fd(unsigned int n)
{
	char	number;

	if (n > 9)
		ft_put_unisgnednbr_fd(n / 10);
	number = n % 10 + '0';
	write(1, &number, 1);
}

static int	ft_nbrlen(unsigned int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n) 
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_is_unsigned_int(int n)
{
	ft_put_unisgnednbr_fd(n);
	return (ft_nbrlen(n));
}
