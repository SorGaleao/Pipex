/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:30:02 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/20 18:25:26 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!*to_find || to_find[i] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] != '\0' && i + j < n)
		{
			if (str[i + j] == to_find[j])
				j++;
			else if (str[i] != to_find[j])
				break ;
		}
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	dest[] = "dezotoito";
	char	agulha[] = "oi";
	int		size = 7;

	printf("%s\n", ft_strnstr(dest, agulha, size));
	//printf("%d", strnstr(dest, agulha, size));
}*/
