#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# ifndef INT_MIN
#  define INT_MIN -2147483648
#  define INT_MAX 2147483647

#  define SA 1
#  define SB 2
#  define SS 3
#  define PA 4
#  define PB 5
#  define RA 6
#  define RB 7
#  define RR 8
#  define RRA 9
#  define RRB 10
#  define RRR 11

#  define TRUE 1
#  define FALSE 0
#  define PRINT_ERROR -1
#  define PRINT_NOTHING 0
#  define MALLOC_ERROR -2
# endif

typedef struct s_stack
{
	int				idx;
	int				data;
	struct s_stack	*pre;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacklst
{
	t_stack			*free_head;
	t_stack			*head_a;
	t_stack			*head_b;
	int				size_a;
	int				size_b;
	int				size_data;
	char			*cmd;
	int				cmd_idx;
	char			print_set;
}					t_stacklst;

void		*ft_memset(void *ptr, int c, size_t len);
long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *str, int fd);
int			ft_malloc_str(char **str, long long malloc_size);
void		ft_swap(int *a, int *b);
char		**ft_split(char const *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);

int			ft_malloc_intptr(int **intptr, int intptr_size);

void		ft_qs_stacka(t_stacklst **stacklst, int n, int depth);
void		ft_qs_stackb(t_stacklst **stacklst, int n, int depth);

int			ft_isempty(t_stack *head);
int			ft_isfull(int data_size, int stack_size);
int			ft_push_deq(t_stack **push_stack, t_stack **pop, int *push_size);
int			ft_push_head(t_stacklst **stacklst, t_stack **pop, \
						char push_stackname);
void		ft_pop_deq(t_stack **pop_stack, t_stack **pop, int *pop_size);
int			ft_pop_head(t_stack **pop_stack, t_stack **pop, int *pop_size);
void		ft_swap_head(t_stack **head);
void		ft_rotate_head(t_stack **head);
void		ft_rotate_tail(t_stack **head);
int			ft_sa(t_stacklst **stacklst);
int			ft_sb(t_stacklst **stacklst);
int			ft_ss(t_stacklst **stacklst);
int			ft_pa(t_stacklst **stacklst, t_stack **pop);
int			ft_pb(t_stacklst **stacklst, t_stack **pop);
void		ft_ra(t_stacklst **stacklst);
void		ft_rb(t_stacklst **stacklst);
void		ft_rr(t_stacklst **stacklst);
void		ft_rra(t_stacklst **stacklst);
void		ft_rrb(t_stacklst **stacklst);
void		ft_rrr(t_stacklst **stacklst);

int			ft_is_str_digit(char **ptr_str, int len);
int			ft_is_int(long long str_int);
int			ft_is_int_unique(t_stack *stack, int stack_size);
int			ft_is_int_sorted(t_stack *now, int stack_size);

int			ft_malloc_stacklst(t_stacklst **stacklst, int size);
int			ft_set_stack_a(t_stacklst **stacklst, t_stack *now, \
							int data_size, char **str);

void		ft_bubble_sort(t_stacklst **stacklst, t_stack *now, \
							int loop, char data_idx);
void		ft_indexing_stack(t_stack *stack, int stack_size);

void		ft_index_sort(t_stacklst **stacklst);
int			ft_chk_argv_unique(t_stacklst **stacklst);
int			ft_chk_argv_not_sorted(t_stacklst **stacklst);
int			ft_chk_argv_digit(int argc, char **argv);

int			ft_is_strptr_space(char **str);
char		*ft_join_argv(char **argv, char	**join_argv);
void		ft_free_str(char **str);
char		**ft_set_argcv(int *argc, char **argv);

void		ft_free_new_argv(char **new_argv);
int			ft_free_new_argv_error(char **new_argv);
int			ft_free_new_argv_nothing(char **new_argv);
int			ft_free_new_argv_malloc(char **new_argv);
void		ft_free_stacklst(t_stacklst **stacklst);

#endif
