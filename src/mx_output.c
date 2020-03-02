#include "uls.h"

static void all_output(t_lit **new_d, t_head *head) {
    if ((*new_d)->open != NULL) {
        mx_out_menu((*new_d)->open, head, 1);  //check flags  

        // if ((*new_d)->open != NULL) { // for output files
        //     for (int j = 0; (*new_d)->open[j] != NULL; j++) {
        //         mx_printstr((*new_d)->open[j]->name);
        //         mx_printstr("\n");
        //     }
            if (head->flags[mx_get_char_index(MY_FLAGS, 'R')] == 1) {//check flag -R) 
                head->output = 1;
                mx_del_fils(&(*new_d)->open, head);
                if ((*new_d)->open) {
                    mx_printchar('\n');
                    mx_opendir((*new_d)->open, head);
                }
            }
        // }
    }
    else if ((*new_d)->error != NULL) {
            mx_printerr("uls: ");
            char *str = mx_memrchr((*new_d)->name, '/', mx_strlen((*new_d)->name));
            if (!str)
                mx_printerr((*new_d)->name);
            else
                mx_printerr(str + 1);
            mx_printerr(": ");
            mx_printerr((*new_d)->error);
            mx_printerr("\n");
    }

}

void mx_output(t_lit **new_d, t_head *head) {
    if (new_d) {
        for (int i = 0; new_d[i] != NULL; i++) {
            if (head->output == 1) {
                if (new_d[i]->fullpath[0] == '/' && new_d[i]->fullpath[1] == '/')
                    mx_printstr(&new_d[i]->fullpath[1]);
                else
                    mx_printstr(new_d[i]->fullpath);
                mx_printchar(':');
                mx_printchar('\n');
            }
            all_output(&new_d[i], head);
            if (new_d[i + 1] != NULL)
                mx_printchar('\n');
        }
    }
}
