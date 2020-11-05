//
// Created by Redwyn Poetess on 10/25/20.
//

#ifndef LS_LS_H
#define LS_LS_H
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

#endif //LS_LS_H
