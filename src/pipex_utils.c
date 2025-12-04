/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:45:49 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/07/23 17:48:38 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_data(t_data *data)
{
	if (data->in_file >= 0)
		close (data->in_file);
	if (data->out_file >= 0)
		close (data->out_file);
	free(data->path_cmd1);
	free(data->path_cmd2);
	free_array(data->cmd1);
	free_array(data->cmd2);
}

static char	*ft_find_path(t_data *data, char *cmd, char **envp)
{
	data->cmd = ft_strjoin("/", cmd);
	while (envp[data->i])
	{
		if (ft_strncmp(envp[data->i], "PATH=", 5) == 0)
		{
			data->full = envp[data->i] + 5;
			data->array = ft_split(data->full, ':');
			while (data->array[data->index])
			{
				data->test = ft_strjoin(data->array[data->index], data->cmd);
				if (access(data->test, X_OK) == 0)
				{
					free (data->cmd);
					free_array(data->array);
					return (data->test);
				}
				free (data->test);
				data->index++;
			}
			break ;
		}
		data->i++;
	}
	return (free (data->cmd), free_array(data->array), \
		perror("Invalid comand"), NULL);
}

int	get_path(t_data *data, char **argv, char **envp)
{
	if (!argv[2] || !argv[3] || argv[2][0] == '\0' || argv[3][0] == '\0')
		return (perror("Invalid comand"), 1);
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');
	if (!data->cmd1 || !data->cmd2)
		return (perror("Invalid comand"), 1);
	data->path_cmd1 = ft_find_path(data, data->cmd1[0], envp);
	if (!data->path_cmd1)
	{
		free(data->path_cmd1);
		free_array(data->cmd1);
		free_array(data->cmd2);
		return (1);
	}
	data->path_cmd2 = ft_find_path(data, data->cmd2[0], envp);
	if (!data->path_cmd2)
	{
		free(data->path_cmd2);
		free_array(data->cmd1);
		free_array(data->cmd2);
		return (1);
	}
	if (!data->cmd1 || !data->cmd2)
		return (1);
	return (0);
}
