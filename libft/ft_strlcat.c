/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:56:22 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/19 13:35:35 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long int	i;
	unsigned long int	j;	
	unsigned long int	strl;

	j = 0;
	strl = ft_strlen(dst);
	i = strl;
	if (size > 0)
	{
		while (src[j] != '\0' && j + i < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	if (size <= strl)
		return (size + ft_strlen(src));
	else
		return (strl + ft_strlen(src));
}

/*int	main (void)
{
	char dest[14] = "a";

	printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
	printf("%s\n", dest);
	printf("%zu", strlcat(dest, "lorem ipsum dolor sit amet", 15));
	printf("%s", dest);
}*/
