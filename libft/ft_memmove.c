/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:03:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/19 16:24:25 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	if (dest > src)
	{
		while (n--)
			a[n] = b[n];
	}
	return (dest);
}

/*int	main(void)
{
	printf("%s", ft_memmove("oie", "lorem ipum dolor sit a", 22));
	printf("%s", memmove("oie", "lorem ipum dolor sit a", 22));
}*/