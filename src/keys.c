#include "sh.h"

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