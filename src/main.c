#include "ls.h"

void get_flags(char **argv, t_flags* flags) {
	int i;

	i = 0;
	if (argv[1][0] != '-')
		return;
    while (argv[1][++i] != '\0') {
        if (argv[1][i] == 'l')
            flags->flag_l = 1;
        if (argv[1][i] == 'R')
            flags->flag_R = 1;
        if (argv[1][i] == 'a')
            flags->flag_a = 1;
        if (argv[1][i] == 'r')
            flags->flag_r = 1;
        if (argv[1][i] == 't')
            flags->flag_t = 1;
    }
}

void print_flags(t_flags flags) {
    printf("l R a r t\n");
    printf("%d ", flags.flag_l);
    printf("%d ", flags.flag_R);
    printf("%d ", flags.flag_a);
    printf("%d ", flags.flag_r);
    printf("%d\n", flags.flag_t);
}

void run_flags(t_flags flags) {
    if (flags.flag_l)
        flag_l();
    if (flags.flag_R)
        flag_R();
    if (flags.flag_a)
        flag_a();
    if (flags.flag_r)
        flag_r();
    if (flags.flag_t)
        flag_t();
}

t_paths *get_paths(int argc, char **argv) {
/*
    int     argc_index;
    paths = (t_paths*)malloc(sizeof(t_paths));
    t_paths *head = paths;

    argc_index = 2;
    if (argc > 2) {
        while (argc_index < argc) {
            paths = (t_paths*)malloc(sizeof(t_paths));
            paths->name = malloc(sizeof(char*));
            paths->name = argv[argc - 1];
            printf("%s ", paths->name);
            paths = paths->next;
		argc_index++;
        }
        paths = head;
        puts(paths->name);
    }
*/
	t_paths *new_path;
	int i;
	(void) argc;
	i = argc - 1;

	if ((new_path = (t_paths *)malloc(sizeof(*new_path))) == NULL)
		return (NULL);
	if((new_path->name) == malloc(ft_strlen(argv[i]))) {
		free(new_path);
		return (NULL);
	}
	ft_memcpy(new_path->name, argv[i], ft_strlen(argv[i]));
	new_path->next = NULL;
	return new_path;
}

int main(int argc, char **argv) {
    t_flags flags = {'-', '-', '-', '-', '-'};
    t_paths *paths;

    if (argc == 1)
        flag_no();
    else {
		get_flags(argv, &flags);
        paths = get_paths(argc, argv);
        //printf("%s\n", argv[1]);
        if (FLAG_DEBUG && argv[1][1] != '\0')
            print_flags(flags);
        run_flags(flags);
    }
    return 0;
}
