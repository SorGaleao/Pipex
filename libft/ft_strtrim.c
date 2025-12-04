/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:12:58 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/21 14:32:20 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *src, unsigned int start, size_t len);
static int	ft_start(char const *s1, char const *set);
size_t		ft_strlen(const char *c);
static int	ft_end(const char *s1, char const *set);
char		*ft_strtrim(char const *s1, char const *set);

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] != set[j])
				j++;
			else if (s1[i] == set[j])
				break ;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	i++;
	return (i - 1);
}

static int	ft_end(char const *s1, char const *set)
{
	int		len;
	int		j;

	len = ft_strlen(s1);
	while (len)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[len] != set[j])
				j++;
			else if (s1[len] == set[j])
				break ;
		}
		if (s1[len] != set[j])
			break ;
		len--;
	}
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;

	if (!s1 || !set)
		return (0);
	start = ft_start(s1, set);
	len = ft_end(s1, set) - start;
	return (ft_substr(s1, start, len));
}

/*int	main(void)
{
	printf("%s", ft_strtrim("lorem ipsum dolor sit amet", "te"));
}*/