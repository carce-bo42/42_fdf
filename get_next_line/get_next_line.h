#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
int		get_next_line(int fd, char **line);
char	*ft_read_line(int fd, char *read_line);
char	*ft_write_line(ssize_t len_read, char *read_line, char **line_out);
char	*ft_strjoin_n_free(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
#endif
