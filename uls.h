#ifndef PATH_H
#define PATH_H

#include <errno.h>
#include "libmx/inc/libmx.h"
#include "sys/stat.h"
#include <sys/types.h>//opendir
#include <dirent.h> // opendir readdir
#include <limits.h> // limits PATH_MAX

#define MX_IS_BLK(mode) (((mode) & S_IFMT) == S_IFBLK)
#define MX_IS_CHR(mode) (((mode) & S_IFMT) == S_IFCHR)
#define MX_IS_DIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define MX_IS_LNK(mode) (((mode) & S_IFMT) == S_IFLNK)
#define MX_IS_SOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
#define MX_IS_FIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define MX_IS_WHT(mode) (((mode) & S_IFMT) == S_IFWHT)
#define MX_IS_REG(mode) (((mode) & S_IFMT) == S_IFREG)

#define MY_FLAGS "LARarlstucSClm1" //our flags

//typedef struct stat t_st;

typedef struct s_li {
    char *name;
    char *fullpath;
    int whats; // 1 - wrong dir / 2 - dir / 3 - file /
    struct stat t_st;
    struct s_li *next;
} t_li;
 

 typedef struct s_head {
    int *flags;
    int count_flags;

 } t_head;



int mx_check_flags(int argc, char *argv[], t_head *head);
t_li *mx_create_li(char *name, int i);
t_li *mx_determine_argv(int argc, char *argv[], t_head *head);




#endif


