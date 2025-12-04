/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:45:41 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/20 17:50:25 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!src)
		return (NULL);
	i = 0;
	if (start > ft_strlen(src))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	if (len > ft_strlen(src) - start)
		len = ft_strlen(src) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
		str[i++] = src[start++];
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char *src = "lorem ipsum dolor sit amet";

	printf("%s", ft_substr(src, 0, 10));
}*/