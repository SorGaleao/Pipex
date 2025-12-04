/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:56:51 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/15 20:52:51 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char str [4] = "Gabs";
	int num = 'H';
	int size = sizeof(str);

	printf("%s", ft_memset(str, num, size));
}
	//*/