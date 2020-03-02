#include "uls.h"

static bool sort_by_time(t_lit **new_d, int ind, int i, int j) {
    if (new_d[ind]->open[i]->t_st.st_mtime 
        < new_d[ind]->open[j]->t_st.st_mtime)
    return true;
    else if (new_d[ind]->open[i]->t_st.st_mtimespec.tv_nsec < 
             new_d[ind]->open[j]->t_st.st_mtimespec.tv_nsec && 
             new_d[ind]->open[i]->t_st.st_mtime == 
             new_d[ind]->open[j]->t_st.st_mtime)
        return true;
    else if (mx_strcmp(new_d[ind]->open[j]->name,
                       new_d[ind]->open[i]->name) < 0 && 
                       new_d[ind]->open[i]->t_st.st_mtimespec.tv_nsec == 
                       new_d[ind]->open[j]->t_st.st_mtimespec.tv_nsec &&
                       new_d[ind]->open[i]->t_st.st_mtime == 
                       new_d[ind]->open[j]->t_st.st_mtime)
            return true;
    return false;
}

static bool sort_by_size(t_lit **new_d, int ind, int i, int j) {
    if (new_d[ind]->open[i]->t_st.st_size < 
        new_d[ind]->open[j]->t_st.st_size)
            return true;
    else if (mx_strcmp(new_d[ind]->open[j]->name,
        new_d[ind]->open[i]->name) < 0)
        return true;
    return false;
}

static void swap_li(t_lit **bondOne, t_lit **bondTwo) {
    t_lit *temp = *bondOne;

    *bondOne = *bondTwo;
    *bondTwo = temp;
}

static bool what_sort(t_head *head, t_lit **new_d, int ind, int i, int j) {
    if (head->flags[mx_get_char_index(MY_FLAGS, 't')] == 1)
        return sort_by_time(new_d, ind, i, j);
    if (head->flags[mx_get_char_index(MY_FLAGS, 'S')] == 1) {
        return sort_by_size(new_d, ind, i, j);
    }
    else {
        if (mx_strcmp(new_d[ind]->open[j]->name, 
            new_d[ind]->open[i]->name) < 0)
            return true;
    }
    return false;
}

void mx_sort(t_lit **new_d,t_head *head) {
    int ind = 0;

    for (ind = 0; new_d[ind] != NULL; ind++) {
        for (int i = 0; new_d[ind]->open[i] != NULL; i++) {
            for( int j = i + 1; new_d[ind]->open[j] != NULL; j++) {
                if (what_sort(head, new_d, ind, i, j)) {
                    swap_li(&new_d[ind]->open[i], &new_d[ind]->open[j]);
                }
            }
        }
    }
    for (ind = 0; new_d[ind] != NULL; ind++) {
        if (head->flags[mx_get_char_index(MY_FLAGS, 'r')] == 1) {
            for (int i = 0; new_d[ind]->open[i] != NULL; i++) {
                for( int j = i + 1; new_d[ind]->open[j] != NULL; j++) {
                    swap_li(&new_d[ind]->open[i], &new_d[ind]->open[j]);
                }
            }
        }
    }
}
