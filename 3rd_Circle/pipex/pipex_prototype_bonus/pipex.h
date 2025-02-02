#ifndef PIPEX_H

# define PIPEX_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <wait.h>

typedef struct s_pipex
{
	int		heredoc;
	int		cmdnum;
	int		infilefd;
	int		outfilefd;
	char	*currcmd;
	char	*fullpathstr;
	char	**envp;
	char	**paths;
	char	**currcmdargs;
}			t_pipex;

void	manage_child(t_pipex pipex, char **argv, int out, int index);

void	run_next_cmd(t_pipex pipex, char **argv, int i);

//command path locating
char	*get_path_envp(char **envp);
char	**get_cmd_path(char **envp);
char	*trim_path(char *path);
void	append_slash(char **paths);
void	append_cmd(char **paths, char *cmd);

//heredoc
int		heredoc(t_pipex *pipex, char **argv, int argc, int pipe[2]);

//errors
int		error(void);

// gnl
char	*get_next_line(int fd);

//utils
size_t	ft_strlen(char *str);
int		ft_strcmp(char *line, char *limiter);
char	*ft_strdup(char *s);
char	*ft_append(char *s1, char *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif