/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:10:01 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/20 17:55:58 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)chr)
			return (&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)chr)
		return (&str[i]);
	return (NULL);
}

/*int	main(void)
{
	char	dest[] = "bonjour";
	int	agulha = 'b';

	printf("%s\n", ft_strchr(dest, agulha));
	printf("%s", strchr(dest, agulha));
}*/