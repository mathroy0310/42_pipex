/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:17:20 by maroy             #+#    #+#             */
/*   Updated: 2023/04/28 14:39:55 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*get_full_command(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.fd_in, STDIN_FILENO);
	dup2(pipex.end[1], STDOUT_FILENO);
	close(pipex.fd_in);
	close(pipex.fd_out);
	close(pipex.end[0]);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_full_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		error_message(ERROR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	perror("execve");
}

void	second_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.end[0], STDIN_FILENO);
	dup2(pipex.fd_out, STDOUT_FILENO);
	close(pipex.fd_in);
	close(pipex.fd_out);
	close(pipex.end[1]);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_full_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		error_message(ERROR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	perror("execve");
}
