/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:24:18 by hcarrasc          #+#    #+#             */
/*   Updated: 2022/10/07 09:28:58 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	openfile(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, str_ichr(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));
}

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && str_ichr(path, ':') > -1)
	{
		dir = str_ndup(path, str_ichr(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = str_split(argv, ' ');
	if (str_ichr(cmd[0], '/') > -1)
		path = cmd[0];
	else
		path = get_path(cmd[0], env);
	execve(path, cmd, env);
	write(STDERR, "pipex: ", 7);
	write(STDERR, argv, str_ichr(argv, 0));
	write(STDERR, ": command not found\n", 20);
	exit(127);
}

void	redir(char *argv, char **env, t_bonus bonus)
{
	pipe(bonus.fd);
	bonus.pid = fork();
	if (bonus.pid)
	{
		close(bonus.fd[1]);
		dup2(bonus.fd[0], STDIN);
		waitpid(bonus.pid, NULL, 0);
	}
	else
	{
		close(bonus.fd[0]);
		dup2(bonus.fd[1], STDOUT);
		if (bonus.fdin == STDIN)
			exit(1);
		else
			exec(argv, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_bonus	bonus;
	int		i;

	if (argc > 5)
	{
		i = 3;
		bonus.fdin = openfile(argv[1], INFILE);
		bonus.fdout = openfile(argv[argc - 1], OUTFILE);
		dup2(bonus.fdin, STDIN);
		dup2(bonus.fdout, STDOUT);
		redir(argv[2], env, bonus);
		while (i < argc - 2)
		{
			bonus.fdin = 1;
			redir(argv[i++], env, bonus);
		}
		exec(argv[i], env);
	}
	else
		perror("Error");
	return (0);
}
