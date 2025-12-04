/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:46:25 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/23 12:38:55 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	ptr = malloc((num * size));
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * num);
	return (ptr);
}

/*int	main(void)
{
	int	*array;
	int	size;
	int	i;

	size = 5;
	i = 0;
	array = (int *)ft_calloc(size, sizeof(int));
		return (0);
	while (i < size)
	{
		printf("array[%d] = %d\n", i, array[i]);
		i++;
	}
	free(array);
	return (0);
}*/