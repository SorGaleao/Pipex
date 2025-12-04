/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:45:18 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/07/22 14:32:41 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen(unsigned long n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n) 
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void	ft_convert_hex(unsigned long dec, const char type)
{
	char	*hexstr;

	if (type == 'x' || type == 'p')
		hexstr = "0123456789abcdef";
	else if (type == 'X')
		hexstr = "0123456789ABCDEF";
	else
		return ;
	if (dec >= 16)
		ft_convert_hex (dec / 16, type);
	ft_putchar_fd((hexstr[dec % 16]), 1);
}

int	ft_is_hex(unsigned long dec, const char type)
{
	if (type == 'p')
	{
		if (!dec)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		ft_convert_hex (dec, type);
		return (ft_hexlen(dec) + 2);
	}
	ft_convert_hex (dec, type);
	return (ft_hexlen(dec));
}

static int	ft_len_args(va_list args, char type)
{
	if (type == 'c')
		return (ft_is_char((char)va_arg(args, int)));
	else if (type == 's')
		return (ft_is_str(va_arg(args, char *)));
	else if (type == 'i' || type == 'd')
		return (ft_is_int(va_arg(args, int)));
	else if (type == 'u')
		return (ft_is_unsigned_int(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_is_hex(va_arg(args, unsigned int), type));
	else if (type == 'p')
		return (ft_is_hex((unsigned long)va_arg(args, void *), type));
	else if (type == '%')
		return (ft_is_percent());
	else
		return (-1);
}

int	ft_printf(const char *type, ...)
{
	int	i;
	int	len;

	len = 0;
	va_list (args);
	i = 0;
	va_start(args, type);
	while (type[i])
	{
		if (type[i] == '%')
		{
			i++;
			len += ft_len_args(args, type[i]);
			i++;
		}
		else 
		{
			write (1, &type[i], 1);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
