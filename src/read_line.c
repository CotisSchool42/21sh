#include "sh.h"



struct s_node		*print_list(t_node *temp)
{
//	tputs(tgetstr("nd", NULL), 1, ft_printnbr);
	while (temp->next != NULL)
	{
		tputs(tgetstr("le", NULL), 1, ft_printnbr);
		write(STDIN_FILENO, &temp->data, 1);
		temp = temp->next;
	}
	return (temp);
}

_Noreturn int		read_line(t_node *list, t_node *root)
{
	long c;

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
/*		tputs(tgetstr("ho", NULL), 1, ft_printnbr); НАЧАЛО СТРОКИ */
		if (c == CHAR_RETURN)
		{
		//	clean_window();
			t_node *temp;
			temp = root;
			while (temp->next != NULL)
			{
				write(STDERR_FILENO, &temp->data, 1);
				temp = temp->next;
			}
			while (root->next != NULL) {
				free(root);
				root = root->next;
			}
			write(STDIN_FILENO, "\n", 1);
			list = root;
			list = k_init(list, root);
		}
	}
}

/*
** ТЕСТИРОВАНИЕ ПРАВИЛЬНОСТИ ВЫВОДА ПОДСТАВИТЬ ЗАМЕСТО CHAR-RETURN ПРОЕБЫ НЕДОПУСТИМЫ
** write(STDERR_FILENO, &list->back->data, 1);
**
** ТЕСТИРОВАНИЕ ROOT
** write(STDIN_FILENO, &root->next->data, 1);
** write(STDIN_FILENO, &root->next->next->data, 1);
** write(STDIN_FILENO, &root->next->next->next->data, 1);
** write(STDIN_FILENO, &root->next->next->next->next->data, 1);
** write(STDIN_FILENO, &root->next->next->next->next->next->data, 1);
*/