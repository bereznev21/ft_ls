#include "ls.h"


void print_paths(t_paths *paths) {
	while (paths) {
		ft_putstr(paths->name);
		ft_putchar('\n');
		paths = paths->next;
	}
}

void print_flags(t_flags flags) {
	printf("l R a r t\n");
	ft_putchar(flags.flag_l);
	ft_putchar(' ');
	ft_putchar(flags.flag_R);
	ft_putchar(' ');
	ft_putchar(flags.flag_a);
	ft_putchar(' ');
	ft_putchar(flags.flag_r);
	ft_putchar(' ');
	ft_putchar(flags.flag_t);
	ft_putchar('\n');
}
