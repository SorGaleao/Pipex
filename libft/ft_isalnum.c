/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:54:02 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/15 15:16:29 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*int	main (void)
{
	printf("%d", ft_isalnum('c'));
	printf("%d", ft_isalnum('8'));
	printf("%d", ft_isalnum('_'));
}*/