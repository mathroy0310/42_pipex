/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:29:38 by maroy             #+#    #+#             */
/*   Updated: 2023/04/18 19:33:12 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[])
{
	int end[2];
	int f1;
	int f2;
	pid_t parent;
	pipe(end);

	if (argc < 5)
	{
		ft_printf("\033[1;31m ERROR 🛑 : Must have more than 5 argc.	\033[0m");
		return (EXIT_FAILURE);
	}
	parent = fork();

	char *infile = argv[1];
	char *cmd1 = argv[2];
	char *cmd2 = argv[3];
	char *outfile = argv[4];

	f1 = open(infile, STDIN_FILENO);
	f2 = open(outfile, STDOUT_FILENO);

	if (parent == -1)
	{
		perror("Fork: ");
		return (EXIT_FAILURE);
	}
	if (!parent) // if fork() returns 0, we are in the child process
	{
		dup2(f1, STDIN_FILENO);
		dup2(end[1], STDOUT_FILENO);

		close(end[1]);
		close(f1);
		return (EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(-1, &status, 0);
		dup2(f2, STDOUT_FILENO);
		dup2(end[0], STDIN_FILENO);
		
		close(end[0]);
		close(f2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}