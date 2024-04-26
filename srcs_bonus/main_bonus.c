/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:00 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/26 15:59:17 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	get_input(t_input *input)
{
	char	c;
	int		i;

	i = 0;
	input->text = (malloc(10000));
	if (!input->text)
		exit(1);
	while (read(0, &c, 1) != 0)
	{
		if (c == '\n' || c == '\0')
		{
			input->text[i] = c;
			input->text[++i] = '\0';
			return ;
		}
		input->text[i] = c;
		i++;
	}
}

void	here_doc(char *limiter)
{
	int		proc_id;
	int		fd[2];
	t_input	input;

	limiter = ft_strjoin(limiter, "\n");
	if (pipe(fd) == -1)
		error(1);
	proc_id = fork();
	if (proc_id == -1)
		error(1);
	if (proc_id == 0)
		here_doc_child(limiter, &input, fd[0], fd[1]);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(proc_id, NULL, 0);
	}
}

void	init_cmds(t_cmds *cmds)
{
	cmds->cmd = NULL;
	cmds->path = NULL;
	cmds->outfile = -1;
	cmds->i = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	int		infile;
	int		outfile;

	outfile = 0;
	if (argc < 5)
		return (1);
	init_cmds(&cmds);
	if (is_here_doc(argv))
	{
		cmds.outfile = open_outfile(argv[argc - 1]);
		cmds.i = 3;
	}
	else
	{
		infile = open_infile(argv[1], argv);
		cmds.outfile = open_outfile(argv[argc - 1]);
		dup2(infile, STDIN_FILENO);
		cmds.i = 2;
	}
	pipex(argc, argv, env, &cmds);
	return (0);
}

/* int main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	int i;
	
	if (argc < 5)
		return (1);
	i = 2;
	while (i <= argc - 2)
	{
		printf("%d\n", i);
		commands_management(argv[i], env, &cmds);
		printf("%s \n %s \n", cmds.cmd[0], cmds.path);
		if(cmds.cmd && cmds.path)
		do_child_proc(&cmds, env);
		clean_all(&cmds);
		i++;
	}
} */

/* int	main(int argc, char **argv)
{
	
	if (argc < 5)
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", 6))
	{
		here_doc(argv[2]);
	}
} */