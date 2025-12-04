/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:51:12 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/19 16:23:41 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	int str [4] = {1, 2, 3, 4};
	int src [4] =  {4, 1, 2, 3};
	int size = sizeof(src);

	printf("%d, ", ft_memcpy(str, src, size));
	printf("%d, ", memcpy(str, src, size));
	printf("%d", memmove(str, src, size));
}
*/