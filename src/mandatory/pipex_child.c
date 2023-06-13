/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:17:20 by maroy             #+#    #+#             */
/*   Updated: 2023/06/13 17:03:31 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*get_full_command(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (paths)
	{
		if (cmd[0] == '/' )
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (cmd);
			return (NULL);
		}
		while (*paths)
		{
			tmp = ft_strjoin(*paths, "/");
			command = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(command, F_OK | X_OK) == 0)
				return (command);
			free(command);
			paths++;
		}
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	pipex.fd_in = open(argv[1], O_RDONLY);
	if (pipex.fd_in < 0)
		error_message(ERROR_INFILE);
	dup2(pipex.fd_in, STDIN_FILENO);
	close(pipex.end[0]);
	dup2(pipex.end[1], STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_full_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		ft_child_free(&pipex);
		error_message(ERROR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char *argv[], char *envp[], int argc)
{
	pipex.fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex.fd_out < 0)
		error_message(ERROR_OUTFILE);
	dup2(pipex.end[0], STDIN_FILENO);
	close(pipex.end[1]);
	dup2(pipex.fd_out, STDOUT_FILENO);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_full_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		ft_child_free(&pipex);
		error_message(ERROR_CMD);
		exit(EXIT_FAILURE);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
