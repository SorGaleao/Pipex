/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:43:58 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/05/21 15:52:48 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(const char *src, unsigned int start, size_t len);
static int	ft_nwords(const char *s, char c);
size_t		ft_strlen(const char *c);
char		**ft_split(const char *s, char c);
static void	*free_all(char **arr, int j);

static int	ft_nwords(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && i == 0)
			n = 1;
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			n++;
		i++;
	}
	return (n);
}

static void	*free_all(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		words;
	int		id_array;
	char	**array;
	int		start;

	i = 0;
	words = ft_nwords(s, c);
	array = (char **)malloc(sizeof (char *) * (words + 1));
	if (!array)
		return (NULL);
	id_array = 0;
	while (s[i] != '\0' && id_array < words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		array[id_array] = ft_substr(s, start, i - start);
		if (!array[id_array++])
			return (free_all(array, id_array - 1));
	}
	array[id_array] = NULL;
	return (array);
}

/*int main()
{
    char **result;
    int i;
    result = ft_split("Ana Paula ", (char)' ');
    if (!result)
        return (1);
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}*/

/*int	main(void)
{
	ft_split("adipiscing elit", 'i');
}*/
