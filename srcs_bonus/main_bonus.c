/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:00 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/25 17:01:00 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	get_input(t_input *input)
{
	char	c;
	int	i;
	
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

void here_doc(char *limiter)
{
	int proc_id;
	int fd[2];
	t_input input;
	
	limiter = ft_strjoin(limiter, "\n");
	if(pipe(fd) == -1)
		error(1);
	proc_id = fork();
	if (proc_id == -1)
		error(1);
	if (proc_id == 0)
	{
		close(fd[0]);
		while (1)
		{
			get_input(&input);
			if(!ft_strncmp(input.text, limiter, ft_strlen(input.text)))
			{
				free(limiter);
				free(input.text);
				close(fd[1]);
				exit(0);
			}
			write(fd[1], input.text, (ft_strlen(input.text)));
			free(input.text);
		}
	}
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
}

int	main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	int i;
	int infile;
	int outfile;
	
	if (argc < 5)
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		outfile = open_outfile(argv[argc - 1]);
		here_doc(argv[2]);
		i = 3;
	}
	else
	{
		infile = open_infile(argv[1], argv);
		outfile = open_outfile(argv[argc - 1]);
		dup2(infile, STDIN_FILENO);
		i = 2;
	}
	init_cmds(&cmds);
	while (i < argc - 2)
	{
		commands_management(argv[i], env, &cmds);
		do_child_proc(&cmds, env);
		i++;
	}
	make_free(&cmds);
	commands_management(argv[i], env, &cmds);
	dup2(outfile, STDOUT_FILENO);
	execute(&cmds, env);
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