#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void		ft_pivot(int size, int *pivot1, int *pivot2, char stack);
void		ft_qs_stacka_loop_first(t_stacklst **stacklst, \
			int loop_ft_partition, int pivot1, int pivot2);
void		ft_qs_stacka_loop(t_stacklst **stacklst, \
			int loop_ft_partition, int pivot1, int pivot2);
void		ft_qs_stackb_loop(t_stacklst **stacklst, \
			int loop_ft_partition, int pivot1, int pivot2);
void		ft_qs_two_arg(t_stacklst **stacklst, int *right, int pivot2);
void		ft_qs_stacka(t_stacklst **stacklst, int left, int right);
void		ft_qs_stackb(t_stacklst **stacklst, int left, int right);

int			ft_cmp_three_int(int a, int b, int c);
void		ft_print_cmd_two_arg(t_stacklst **stacklst);
void		ft_print_cmd_three_arg(t_stacklst **stacklst);
int			ft_print_cmd_single(t_stacklst **stacklst, int idx);
int			ft_print_cmd_double(t_stacklst **stacklst, int idx);
void		ft_print_cmd(t_stacklst **stacklst);

int			ft_set_chk_argcv(t_stacklst **stacklst, int argc, char **argv);
void		ft_quick_sort(t_stacklst **stacklst, int n);
int			ft_push_swap(int argc, char *argv[]);
int			main(int argc, char *argv[]);

#endif
