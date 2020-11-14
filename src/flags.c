#include "ls.h"


void flag_l() {
    struct dirent *readdir(DIR *dir);
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
        	//ft_putstr(entry->d_name);
        	//ft_putstr("\n");
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
    int i;

    i = 0;
    if ((dir = opendir(".")) == NULL)
        perror("opendir() error");
    else {
        //puts("contents of root:");
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.') {
				i++;
				ft_putstr(entry->d_name);
				if (i % 4 == 0)
					ft_putstr("\n");
				else
					ft_putstr("\t\t");
            }
        }
        closedir(dir);
    }
}
