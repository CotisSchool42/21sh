#include "sh.h"



void		print_list(t_node *root)
{
	t_node *temp;

	temp = root;
	write(STDIN_FILENO, "LINE:", 30);
	while (temp != NULL)
	{
		write(STDIN_FILENO, temp->data, 1);
		temp = temp->next;
	}
	exit (0);
}

_Noreturn int		read_line(t_node *list, t_node *root)
{
	long	c;

	while (1)
	{
		c = 0;
		read(STDOUT_FILENO, &c, 8);
		if (checkout(c) == 0 && list->next == NULL && list == root)         /* Если мы хотим автокомплит, то меняем checkout */
			continue;
		if (list->back != NULL && c == LEFT_KEY)
			list = k_left(list);
		if (list->next != NULL && c == RIGHT_KEY)
			list = k_right(list);
		if (checkout(c) != 0)
			list = addelem(list, root, c);
		if (c == CHAR_RETURN)
			list = k_init(list, root);
	}
/*		if (c == DOWN_KEY || c == UP_KEY)
			continue;
		if (c == LEFT_KEY && list->back != NULL && list->next != NULL)
		{
			tputs(tgetstr("le", NULL), 1, ft_printnbr);
			list = list->back;
		}
		if (c == RIGHT_KEY && list->back == NULL)
		{
			if (list->next != NULL)
			{
				tputs(tgetstr("nd", NULL), 1, ft_printnbr);
				list = list->next;
			}
		}
		if (BSP_KEY == c)
		{
			list = deletelem(list, root);
		}
		if (CHAR_RETURN == c)
		{
			clean_window();
			write(STDERR_FILENO, list->data, 1);
		}
		list = addelem(list, c);*/
}
/*if (c == CHAR_RETURN) {
clean_window();
write(STDIN_FILENO, root->data, 9);
if (root->next == NULL)
exit(0);
root = root->next;
}*/
struct s_node 	*escape(t_node *list, t_node *root,  long c)
{
	if (c == DOWN_KEY || c == UP_KEY)
		return (list);
	if (c == LEFT_KEY && list->back != NULL)
	{
		tputs(tgetstr("le", NULL), 1, ft_printnbr);
		list = list->back;
	}
	if (c == RIGHT_KEY)
	{
		if (list->next != NULL) {
			tputs(tgetstr("nd", NULL), 1, ft_printnbr);
			list = list->next;
		}
		if (list->next == root) {
			tputs(tgetstr("nd", NULL), 1, ft_printnbr);
			list = list->next;
		}
	}
	return (list);
}