/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:42:21 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/19 17:16:50 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int chr, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == (unsigned char)chr)
			return (&a[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const void	*dest = "dezotoito";
	int	agulha = 'o';

	printf("%s\n", ft_memchr(dest, agulha, 3));
	printf("%s", memchr(dest, agulha, 3));
}//*/
