/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:29:38 by maroy             #+#    #+#             */
/*   Updated: 2023/04/20 01:26:32 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


static char *findPath(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);//+5 skip le PATH=
	
}

static void closePipes(t_pipex *pipex)
{
	close(pipex->end[0]);
	close(pipex->end[1]);
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
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		return (errorMessage(ERROR_OUTFILE));
	if (pipe(pipex.end) < 0)
		return (errorMessage(ERROR_PIPE));
	pipex.paths = findPath(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		firstChild(pipex, argv, envp);	
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		secondChild(pipex, argv, envp);
	closePipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0 );
	return (EXIT_SUCCESS);
}