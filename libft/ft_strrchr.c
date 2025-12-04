/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:10:01 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/20 17:56:10 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i != 0)
	{
		if (str[i] == (unsigned char)chr)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == (unsigned char)chr)
		return ((char *)&str[i]);
	return (NULL);
}

/*int	main(void)
{
	char	dest[] = "dezotoitu";
	int	agulha = 'o';

	printf("%s\n", ft_strrchr(dest, agulha));
	printf("%s", strrchr(dest, agulha));
}*/