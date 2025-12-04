/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:55:57 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/19 11:25:57 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long int	i;
	unsigned long int	strl;

	i = 0;
	strl = 0;
	while (src[strl] != '\0')
		strl++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (strl);
}

/*int	main (void)
{
	char dst [7] = "Gabriel";
	char src [5] = "souza";
	int size = 5;
	
	printf("%zu", ft_strlcpy(dst, src, size));
	printf("%s", dst);
}*/
