#include "uls.h"

static void push_front(t_li **li, char *argv, int i) {///
    t_li *tmp = mx_create_li(argv, i);
    t_li *nd = *li;
    
    if (!tmp)
        return;
    else if (nd == NULL)
        *li = tmp;
    else if (nd) {
        tmp->next = *li;
        *li = tmp;
    } 
}

t_li *mx_determine_argv(int argc, char *argv[], t_head *head) {
    struct stat buf;
    t_li *node = NULL;

    if (argc == head->count_flags)
        if (lstat(".", &buf) >= 0)
            mx_printstr("REALIZ FLAG D\n"); // реализовать флаг D
    for (; head->count_flags < argc; head->count_flags++) {
       if (lstat(argv[head->count_flags], &buf) < 0) {
            push_front(&node, argv[head->count_flags], 1);
            mx_printstr("ERROR\n");
        }
        else {
             if (MX_IS_DIR(buf.st_mode)) {
                push_front(&node, argv[head->count_flags], 2);
                mx_printstr("DIR\n");
             }
             else {
                 push_front(&node, argv[head->count_flags], 3);
                 mx_printstr(" File \n");
             }
        }
    }
    return node;
 }
