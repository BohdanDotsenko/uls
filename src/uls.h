#ifndef PATH_H
#define PATH_H

#include <string.h>
#include <errno.h>
#include "libmx.h"
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

#define MY_FLAGS "LARarls" //our flags

//typedef struct stat t_st;
struct stat *buf;

typedef struct s_lit {
    char *name;
    char *fullpath;
    char *error;// write mistake errno
    int what_is_it;
    struct stat t_st;
    struct s_lit **open;
} t_lit;
 
 typedef struct s_head {
    int *flags;
    int count_flags;
    int sum_dir;
    int sum_file; // for print!! have or not file//
 } t_head;


int mx_check_flags(int argc, char *argv[], t_head *head);
t_lit **mx_getname(int argc, char **argv, int i);
void mx_parse(int argc, char **argv, t_head *head);
void mx_sort_asci(t_lit ***arg);
t_lit **mx_make_new_list(t_lit **args, int valid_node);
void mx_del_list(t_lit **args);
void mx_indification_args(t_lit **args, t_head *head);
int mx_check_dir(t_lit ***args);
int mx_check_file(t_lit ***args);
t_lit **mx_createlist(char **name, int count); // after open dir we have array ---> new_list ----> and working with him
void mx_opendir(t_lit **new_d, t_head * head);
void mx_join(char **res, char *s2);
void mx_add_new_dir_array(t_lit **args, t_lit **new_d);
void mx_add_new_file_array(t_lit **args, t_lit **new_f);
t_lit** mx_arg(t_lit **args);
void mx_del_fils(t_lit ***args, t_head *head);
void mx_del_litarr(t_lit ***args, t_lit **dir);

#endif


