/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:52:23 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/10/07 08:54:45 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_path	man;

	pipe(man.fd);
	man.pid = fork();
	if (man.pid == -1)
		perror("error");
	if (argc == 5)
	{
		man.paths = get_path(env);
		man.cmd = get_cmd(&argv[2]);
		man.path = cmd_path(man.paths, man.cmd);
		if (man.pid == 0)
			child_proces(argv, env, man);
		else
		{
			waitpid(man.pid, NULL, 0);
			man.paths = get_path(env);
			man.cmd = get_cmd(&argv[3]);
			man.path = cmd_path(man.paths, man.cmd);
			parent_proces(argv, env, man);
		}
	}
	else
		perror("Error");
	return (0);
}
