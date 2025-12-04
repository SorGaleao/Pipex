/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:29:32 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/07/23 17:48:59 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static int	init_var(t_data *data, char **argv)
{
	data->in_file = -1;
	data->out_file = -1;
	data->in_file = open(argv[1], O_RDONLY);
	if (data->in_file < 0)
		return (perror("Not possible to open file"), 1);
	data->out_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->out_file < 0)
		return (perror("Not possible to open file"), 1);
	data->i = 0;
	data->index = 0;
	return (0);
}

static int	ft_child1(t_data *data, char **envp)
{
	close(data->fd[0]);
	dup2(data->in_file, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	if (execve(data->path_cmd1, data->cmd1, envp) == -1)
		return (perror("problema com execve"), 1);
	return (0);
}

static int	ft_child2(t_data *data, char **envp)
{
	close(data->fd[1]);
	dup2(data->fd[0], STDIN_FILENO);
	dup2(data->out_file, STDOUT_FILENO);
	if (execve(data->path_cmd2, data->cmd2, envp) == -1)
		return (perror("problema com execve"), 1);
	return (0);
}

static int	child_handling(t_data *data, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), 1);
	if (pid1 == 0)
		ft_child1(data, envp);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), 1);
	if (pid2 == 0)
		ft_child2(data, envp);
	close(data->fd[0]);
	close(data->fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5)
		return (0);
	if (pipe(data.fd) == -1)
		return (1);
	if (init_var(&data, argv) == 1)
		return (1);
	if (get_path(&data, argv, envp) == 1)
		return (1);
	if (child_handling(&data, envp))
		return (1);
	free_data(&data);
}
