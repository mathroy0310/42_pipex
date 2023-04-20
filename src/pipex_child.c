/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:17:20 by maroy             #+#    #+#             */
/*   Updated: 2023/04/20 01:27:17 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*getFullCommand(char **paths, char *cmd)
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

void	firstChild(t_pipex pipex, char *argv[], char *envp[])
{
	
	dup2(pipex.end[1], 1);
	close(pipex.end[0]);
	dup2(pipex.infile, 0);

	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = getFullCommand(pipex.cmd_paths, pipex.cmd_args[0]);

	if (!pipex.cmd)
	{
		errorMessage(ERROR_CMD);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		perror("execve");
}

void	secondChild(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.end[0], 0);
	close(pipex.end[1]);
	dup2(pipex.outfile, 1);

	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = getFullCommand(pipex.cmd_paths, pipex.cmd_args[0]);

	if (!pipex.cmd)
	{
		errorMessage(ERROR_CMD);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_args, envp) == -1)
		perror("execve");
}