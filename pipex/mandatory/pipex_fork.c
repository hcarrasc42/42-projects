/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:00:08 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/10/04 10:19:06 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_proces(char **argv, char **env, t_path man)
{
	int	infile;

	close(man.fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		perror("Error");
	dup2(man.fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(man.fd[1]);
	execve(man.path, man.cmd, env);
}

void	parent_proces(char **argv, char **env, t_path man)
{
	int	outfile;

	close(man.fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (outfile == -1)
		perror("Error");
	dup2(outfile, STDOUT_FILENO);
	dup2(man.fd[0], STDIN_FILENO);
	close(man.fd[0]);
	execve(man.path, man.cmd, env);
}
