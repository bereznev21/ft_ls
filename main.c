#include <stdio.h>
#include <dirent.h>
#include "ls.h"


void flag_l() {struct dirent *readdir(DIR *dir);

    printf("flag l\n");
}


void flag_R() {
    printf("flag R\n");
}


void flag_a() {
    printf("flag a\n");
}


void flag_r() {
    //printf("flag r\n");
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(".")) == NULL)
        perror("opendir() error");
    else {
        puts("contents of root:");
        while ((entry = readdir(dir)) != NULL) {
            printf("%s  %hu  %hhu  %llu  %hu  %llu\n", entry->d_name, entry->d_namlen, entry->d_type, entry->d_ino, entry->d_reclen, entry->d_seekoff);
        }
        closedir(dir);
    }
}


void flag_t() {
    printf("flag t\n");
}


void flag_no() {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(".")) == NULL)
        perror("opendir() error");
    else {
        puts("contents of root:");
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.')
                printf("%s", entry->d_name);
        }
        closedir(dir);
    }
}

void get_flags(int argc, char **argv, t_flags* flags) {
    int i;

    i = 0;
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
    printf("%c ", flags.flag_l);
    printf("%c ", flags.flag_R);
    printf("%c ", flags.flag_a);
    printf("%c ", flags.flag_r);
    printf("%c\n", flags.flag_t);
}

void run_program(t_flags flags) {
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

int main(int argc, char **argv) {

    t_flags flags;
    if (argc == 1)
        flag_no();
    if (argc == 2) {
        if (argv[1][1] == '\0')
            printf("%s: -: No such file or directory\n", argv[0]);
        else {
            get_flags(argc, argv, &flags);
            printf("%s\n", argv[1]);
        }
        if (FLAG_DEBUG && argv[1][1] != '\0')
            print_flags(flags);
        run_program(flags);
    }
    return 0;
}