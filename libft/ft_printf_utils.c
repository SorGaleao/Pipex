/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:47:13 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/07/22 14:31:14 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_is_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_is_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

static int	ft_nbrlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n) 
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_is_int(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}
