/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:46:21 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/21 14:33:16 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n);
char		*ft_itoa(int n);

static int	ft_nbrlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n) 
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	int			len;
	long int	nb;

	nb = n;
	len = ft_nbrlen(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (nb == 0)
		nbr[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		nbr[0] = '-';
	}
	while (len-- && nb > 0)
	{
		nbr[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (nbr);
}

/*int	main(void)
{
	printf("%s", ft_itoa(21));
}*/