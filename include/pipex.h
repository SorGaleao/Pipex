/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:30:11 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/07/23 17:58:39 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		i;
	int		index;
	char	*cmd;
	char	*path_cmd1;
	char	*path_cmd2;
	char	*full;
	char	*test;
	char	**array;
	char	**cmd1;
	char	**cmd2;
	int		in_file;
	int		out_file;
	int		fd[2];
}	t_data;

void	free_array(char **array);
void	free_data(t_data *data);
int		get_path(t_data *data, char **argv, char **envp);

#endif