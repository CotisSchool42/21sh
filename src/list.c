/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cotis <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 03:44:27 by cotis             #+#    #+#             */
/*   Updated: 2020/10/23 05:55:51 by cotis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** INIT INITIALIZE FIRST LIST
** HERE CAN BE PATH TO DIRECTORY IN FIRST LIST temp->data
*/

struct	s_node					*init(void)
{
	t_node		*temp;
	int			i;

	temp = (t_node *)ft_memalloc(sizeof(t_node));
	temp->path = "LoveYou:";
	i = ft_strlen(temp->path);
	temp->next = NULL;
	temp->back = NULL;
	write(STDERR_FILENO, temp->path, i);
	return (temp);
}

int								checkout(long c)
{
	if (c == DOWN_KEY || c == UP_KEY || c == LEFT_KEY || c == RIGHT_KEY)
		return (0);
	return (1);
}

struct	s_node					*endpoint(t_node *list, t_node *root)
{
	t_node		*tail;

	list = root;
	while (list != NULL)
	{
		if (list->next == NULL)
			tail = list;
		list = list->next;
	}
	return (tail);
}

struct	s_node					*deletelem(t_node *list)
{
	t_node		*back;
	t_node		*next;

	if (list->back != NULL && list->next != NULL)
	{
		back = list->back;
		next = list->next;
		tputs(tgetstr("le", NULL), 1, ft_printnbr);
		tputs(tgetstr("dc", NULL), 1, ft_printnbr);
		back->next = list->next;
		next->back = list->back;
		free(list);
		return (back);
	}
	else if (list->back != NULL)
	{
		back = list->back;
		tputs(tgetstr("le", NULL), 1, ft_printnbr);
		tputs(tgetstr("dc", NULL), 1, ft_printnbr);
		back->next = NULL;
		free(list);
		return (back);
	}
	return (list);
}

/*
** ADD ELEMENTS TO LIST, INIT ROOT AND DELETE ELEMENTS
*/

struct	s_node					*addelem(t_node *list, t_node *root, long c)
{
	t_node		*temp;
	t_node		*p;
	char		buf;

	if (c == BSP_KEY)
		return (deletelem(list));
	if (list->next != NULL && list->back != root)
	{
		//	temp = addelem_center(list, root, c);
		(void) root;
		temp = (t_node *) ft_memalloc(sizeof(t_node));
		buf = (char)c;
		p = list->next;
		list->next = temp;
		temp->next = p;
		temp->data = buf;
		temp->back = list;
		if (p != NULL)
			p->back = temp;
	//	tputs(tgetstr("nd", NULL), 1, ft_printnbr);
		write(STDERR_FILENO, &list->data, 1);
		//print_list(temp);
		return (list);
	}
	else {
		(void) root;
		buf = (char) c;
		temp = (t_node *) ft_memalloc(sizeof(t_node));
		p = list->next;
		list->next = temp;
		temp->next = p;
		temp->data = buf;
		temp->back = list;
		if (p != NULL)
			p->back = temp;
	//	write(STDERR_FILENO, &temp->data, 1);
		return (temp);
	}
	return (list);
}

struct	s_node					*addelem_center(t_node *list, t_node *root, long c)
{
	t_node		*temp;
	t_node		*p;
	char		buf;

	(void)root;
	if (list->back != NULL && list->next != NULL)
	{
		temp = (t_node *)ft_memalloc(sizeof(t_node));
		buf = (char)c;
		p = list->next;
		list->next = temp;
		temp->next = p;
		tputs(tgetstr("im", NULL), 1, ft_printnbr);
		tputs(tgetstr("ic", NULL), 1, ft_printnbr);
		tputs(tgetstr("nd", NULL), 1, ft_printnbr);

		temp->data = buf;
		temp->back = list;
		return (temp);
	}
/*	else if (list->back != NULL)
	{
		temp = (t_node *)ft_memalloc(sizeof(t_node));
		buf = (char)c;
		p = list->back;
		tputs(tgetstr("nd", NULL), 1, ft_printnbr);
		tputs(tgetstr("ic", NULL), 1, ft_printnbr);
		return (temp);
	}*/
return (list);
}
