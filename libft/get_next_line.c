/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:36:12 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/07/22 15:09:47 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	read(int fd, void *buf, size_t count);

static int	ft_find_index(char *str, int chr)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)chr)
			return (i);
		i++;
	}
	if (str[i] == (unsigned char)chr)
		return (i);
	return (-1);
}

static char	*to_read(int fd, char *text)
{
	int		count;
	char	*temp;
	char	*test;

	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, temp, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count == -1)
			return (free (temp), NULL);
		temp[count] = '\0';
		test = gnl_strjoin(text, temp);
		free(text);
		text = test;
		if (!text)
			return (NULL);
		if (ft_find_index(text, '\n') >= 0)
			break ;
	}
	return (free(temp), text);
}

static char	*liner_cutter(char *line)
{
	int		i;
	char	*text;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	text = gnl_substr(line, i + 1, gnl_strlen(line) - i);
	if (!text || *text == '\0')
		return (free(text), text = NULL, NULL);
	if (line[i] == '\n')
		line[i + 1] = '\0';
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*temp_text;
	char		*line;
	int			len;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(text), text = NULL, NULL);
	if (!text)
		text = gnl_strdup("");
	text = to_read(fd, text);
	if (!text)
		return (NULL);
	len = gnl_strlen(text);
	if (len == 0)
		return (free (text), text = NULL, NULL);
	line = gnl_substr(text, 0, len);
	if (!line)
		return (free (text), text = NULL, NULL);
	temp_text = liner_cutter(line);
	free(text);
	text = temp_text;
	return (line);
}

/*int main(int argc, char *argv[])
{
    int     fd;
    char    *line;
    int     line_num;
    argc = 0;
    line_num = 1;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Failed to open file");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("Line %d: \"%s\"\n", line_num++, line);
        free(line);
    }
    close(fd);
    return (0);
}*/
