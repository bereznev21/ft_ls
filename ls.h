//
// Created by Redwyn Poetess on 10/25/20.
//
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#ifndef LS_LS_H
#define LS_LS_H
# include "libft/includes/libft.h"

#define FLAG_DEBUG 1

typedef struct s_flags {
    char flag_l;
    char flag_R;
    char flag_a;
    char flag_r;
    char flag_t;
} t_flags;

typedef struct s_paths {
    char            *name;
    struct s_paths  *next;
} t_paths;

void flag_R();
void flag_l();
void flag_a();
void flag_r();
void flag_t();
void flag_no();

#endif //LS_LS_H
