/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:28:10 by maroy             #+#    #+#             */
/*   Updated: 2023/04/19 15:31:27 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <unistd.h>

# define ERROR_ARGC "\033[1;31m ERROR 🛑 : Must have 5 arguments.	\033[0m"
# define ERROR_INFILE "\033[1;31m ERROR 🛑 : Infile Open Crashed.	\033[0m"
# define ERROR_OUTFILE "\033[1;31m ERROR 🛑 : Outfile Open Crashed.	\033[0m"
# define ERROR_PIPE "\033[1;31m ERROR 🛑 : Pipe Crashed.	\033[0m"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		end[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char 	**cmd_args;
	char	*cmd;
}			t_pipex;

char *get_full_command(char **paths, char *cmd);

#endif