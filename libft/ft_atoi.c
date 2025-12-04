/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:28:06 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/15 14:39:03 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	signal;

	i = 0;
	number = 0;
	signal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			signal = -1;
		i++;
	}
	if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = (number * 10 + (str[i] - '0'));
		i++;
	}
	return (number * signal);
}

/*int main(void)
{
	printf("%d, ", ft_atoi("     o1khg"));
	printf("%d, ", ft_atoi("   		+123"));
	printf("%d, ", ft_atoi("   		++123"));
	printf("%d, ", ft_atoi("   		-123"));
	printf("%d, ", ft_atoi("   		123"));
	printf("%d, ", ft_atoi("123a1"));
}
*/