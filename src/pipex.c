/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:29:38 by maroy             #+#    #+#             */
/*   Updated: 2023/04/19 16:17:11 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char *findPath(char **envp)
{
	//jassume que PATH est toujours dedans
	//PATH=/usr/local/bin:/usr/bin:/bin
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);//+5 skip le PATH=
	
}

int errorMessage(char *error)
{
    write(2, error, ft_strlen(error));
    return(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex pipex;
	
	if (argc != 5)
		return (errorMessage(ERROR_ARGC));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		return (errorMessage(ERROR_INFILE));
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0664);
	if (pipex.outfile < 0)
		return (errorMessage(ERROR_OUTFILE));
	if (pipe(pipex.end) < 0)
		return (errorMessage(ERROR_PIPE));
	pipex.paths = findPath(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		//first Child
		dup2(pipex.end[1], 1);
		close(pipex.end[0]);
		dup2(pipex.end[0], 0);

		pipex.cmd_args = ft_split(argv[2], ' ');
		pipex.cmd = get_full_command(pipex.cmd_paths, pipex.cmd_args[0]);
		if(!pipex.cmd)
			errorMessage("first child PIPEX.CMD crash\n");
		execve(pipex.cmd, pipex.cmd_args, envp);
	}
		
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
	{
		//second chilrd
		dup2(pipex.end[0], 0);
		close(pipex.end[1]);
		dup2(pipex.outfile, 1);

		pipex.cmd_args = ft_split(argv[3], ' ');
		pipex.cmd = get_full_command(pipex.cmd_paths, pipex.cmd_args[0]);
		if(!pipex.cmd)
			errorMessage("2nd child PIPEX.CMD crash\n");
		execve(pipex.cmd, pipex.cmd_args, envp);
	}
	close(pipex.end[0]);
	close(pipex.end[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0 );
	return (EXIT_SUCCESS);
}