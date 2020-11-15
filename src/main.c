#include "ls.h"

int get_flags(char **argv, t_flags* flags) {
	int i;

	i = 0;
	if (argv[1][0] != '-')
		return 0;
    while (argv[1][++i] != '\0') {
        if (argv[1][i] == 'l')
            flags->flag_l = '+';
        if (argv[1][i] == 'R')
            flags->flag_R = '+';
        if (argv[1][i] == 'a')
            flags->flag_a = '+';
        if (argv[1][i] == 'r')
            flags->flag_r = '+';
        if (argv[1][i] == 't')
            flags->flag_t = '+';
    }
	return 1;
}

void run_flags(t_flags flags) {
    if (flags.flag_l == '+')
        flag_l();
    if (flags.flag_R == '+')
        flag_R();
    if (flags.flag_a == '+')
        flag_a();
    if (flags.flag_r == '+')
        flag_r();
    if (flags.flag_t == '+')
        flag_t();
}

t_paths *add_path(char **argv, int num_argv) {
	t_paths *new_path;

	if ((new_path = (t_paths *) malloc(sizeof(*new_path))) == NULL)
		return (NULL);
	if ((new_path->name = malloc(ft_strlen(argv[num_argv]))) == NULL) {
		free(new_path);
		return (NULL);
	}
	ft_memcpy(new_path->name, argv[num_argv], ft_strlen(argv[num_argv]));
	new_path->next = NULL;
	return new_path;
}

t_paths *init_path(int num_argc, char **argv) {
	t_paths *first_patch;

	if ((first_patch = (t_paths *) malloc(sizeof(*first_patch))) == NULL)
		return (NULL);
	if ((first_patch->name = malloc(ft_strlen(argv[num_argc]))) == NULL) {
		free(first_patch);
		return (NULL);
	}
	ft_memcpy(first_patch->name, argv[num_argc], ft_strlen(argv[num_argc]));
	first_patch->next = NULL;
	return first_patch;
}

t_paths *read_argv(int argc, char **argv, t_flags *flags) {
	int i;
	t_paths *new_patch;
	t_paths *paths;

	i = 1;
	paths = NULL;
	get_flags(argv, flags);
	if (get_flags(argv, flags))
		i++;
	if (i < argc) {
		paths = init_path(i, argv);
		i++;
	}
	t_paths *head = paths;
	while (i < argc) {
		if ((new_patch = add_path(argv, i)) == NULL)
			break ;
		paths = paths->next;
		paths = new_patch;
		i++;
	}
	paths = head;
	return paths;
}

void init_flags(t_flags *flags) {
	flags->flag_l = '-';
	flags->flag_R = '-';
	flags->flag_a = '-';
	flags->flag_r = '-';
	flags->flag_t = '-';
}

int main(int argc, char **argv) {
    t_flags flags;
    t_paths *paths;

    init_flags(&flags);
    if (argc == 1)
        flag_no();
    else {
    	paths = read_argv(argc, argv, &flags);
        if (FLAG_DEBUG && argv[1][1] != '\0') {
			print_flags(flags);
			print_paths(paths);
        }
        run_flags(flags);
    }
    return 0;
}
