/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:29:38 by maroy             #+#    #+#             */
/*   Updated: 2023/04/28 14:33:34 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static void	close_pipes(t_pipex *pipex)
{
	close(pipex->end[0]);
	close(pipex->end[1]);
}

int	error_message(char *error)
{
	write(2, error, ft_strlen(error));
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_message(ERROR_ARGC));
	pipex.fd_in = open(argv[1], O_RDONLY);
	if (pipex.fd_in < 0)
		return (error_message(ERROR_INFILE));
	pipex.fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex.fd_out < 0)
		return (error_message(ERROR_OUTFILE));
	if (pipe(pipex.end) < 0)
		return (error_message(ERROR_PIPE));
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (EXIT_SUCCESS);
}
