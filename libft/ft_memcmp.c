/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:49:34 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/15 11:57:03 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned int	i;

	a = (unsigned char *)str1;
	b = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char dst [6] = "oieeoo";
	char src [5] =  "oieeo";
	int size = sizeof(src);

	printf("%d, ", ft_memcmp(dst, src, size));
	printf("%d", memcmp(dst, src, size));
}*/