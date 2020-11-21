#include "sh.h"

struct s_node			*k_left(t_node *list)
{
	tputs(tgetstr("le", NULL), 1, ft_printnbr);
	list = list->back;
	return (list);
}

struct s_node			*k_init(t_node *list, t_node *root)
{
	root = init();
	list = root;
	return (list);
}

struct s_node			*k_right(t_node *list)
{
		tputs(tgetstr("nd", NULL), 1, ft_printnbr);
		list = list->next;
	return (list);
}

int					win_size(void)
{
	struct winsize	w;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &w);
	fprintf(stderr, "%d\n",w.ws_col);
	fprintf(stderr, "%d\n",w.ws_row);
	/*if (win_str(line, argc, w) == -1)
	{
		ft_putstr_fd("Error of size\n", STDERR_FILENO);
		return (-1);
	}*/
	return (0);
}