#include "uls.h"

t_li *mx_create_li(char *name, int i) {
    t_li *tmp = (t_li *)malloc(sizeof(t_li));

    tmp->name = name;
    tmp->whats = i;
    tmp->next = NULL;

    return tmp;
}
