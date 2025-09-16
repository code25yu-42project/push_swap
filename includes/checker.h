#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

void		ft_free_str(char **str);
int			ft_set_chk_argcv(t_stacklst **stacklst, int argc, char **argv);

char		*get_next_line(int fd);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

int			ft_center_stack_sort_cmd(t_stacklst **stacklst, char *cmd_gnl);
void		ft_ok_ko(t_stacklst **stacklst);

int			ft_is_stack_sort_cmd(t_stacklst **stacklst, char *cmd);
int			ft_cmd_sort_twochr(t_stacklst **stacklst, \
								char *cmd_gnl, int cmd_idx, int cmd_size);
int			ft_cmd_sort_threechr(t_stacklst **stacklst, \
						char *cmd_gnl, int cmd_idx, int cmd_size);

#endif
