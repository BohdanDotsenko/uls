#include "uls.h"
void mx_add_new_dir_array(t_lit **args, t_lit **new_d) {
    int count_new_arg = 0;

    new_d[count_new_arg] = NULL;

    for (int i = 0; args[i] != NULL; i++) {
        if (args[i]->what_is_it == 2) {
            new_d[count_new_arg] = (t_lit *)malloc(sizeof(t_lit));
            new_d[count_new_arg]->name = mx_strdup(args[i]->name);
            new_d[count_new_arg]->fullpath = mx_strdup(args[i]->fullpath);
            new_d[count_new_arg]->open = NULL; //new
            count_new_arg++;
        }
    }
    new_d[count_new_arg] = NULL;
}

void mx_add_new_file_array(t_lit **args, t_lit **new_f) {
    int count_new_arg = 0;

    new_f[count_new_arg] = NULL;
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i]->what_is_it == 1) {
            new_f[count_new_arg] = (t_lit *)malloc(sizeof(t_lit));
            new_f[count_new_arg]->name = mx_strdup(args[i]->name);
            new_f[count_new_arg]->fullpath = mx_strdup(args[i]->fullpath);
            count_new_arg++;
        }
    }
    new_f[count_new_arg] = NULL;
}

int mx_check_file(t_lit ***args) {
    int sum_file = 0;
    t_lit **arg = *args;

    for (int i = 0; arg[i] != NULL; i++)
        if (!MX_IS_DIR(arg[i]->t_st.st_mode)) {
            arg[i]->what_is_it = 1;
            sum_file++;
        }
    return sum_file;
}

int mx_check_dir(t_lit ***args) {
    int sum_dir = 0;
    t_lit **arg = *args;

    for (int i = 0; arg[i] != NULL; i++)
        if (MX_IS_DIR(arg[i]->t_st.st_mode)) {
            arg[i]->what_is_it = 2;
            sum_dir++;
        }
    return sum_dir;
}

void mx_indification_args(t_lit **args, t_head *head) {
    t_lit **new_f = NULL;
    t_lit **new_d = NULL;
    head->sum_dir = mx_check_dir(&args);
    head->sum_file = mx_check_file(&args);

    if (head->sum_file) {
        new_f = (t_lit **)malloc((head->sum_file + 1) * sizeof(t_lit *));
        mx_add_new_file_array(args, new_f);// we need see whats flag we have ----> use this flag ----> print
    }
    if (head->sum_dir) {
        new_d = (t_lit **)malloc((head->sum_dir + 1) * sizeof(t_lit *)); // i need free new_ar[full] == NULL/
        mx_add_new_dir_array(args, new_d);
    }

    // if (we have 1 argument --> uls && new_f) {
    //     //print_multi_colon // Bodya create this function
    //     return;  
    // }
    // if (args[1]->t_st.st_ino != 0) mx_printstr("!!!!!!!!!!!!!!!!!\n");
   mx_logic(new_d, head);



// for (int i = 0; new_f[i] != NULL; i++) {
//         mx_printstr(new_f[i]->name);
//         mx_printstr("FILE \n");
//     }
    // for (int i = 0; new_d[i] != NULL; i++) {
    //     mx_printstr(new_d[i]->name);
    //     mx_printstr("DIR \n");
    // }

// for (int i = 0; args[i] != 0; i++) {
//     mx_printstr(args[i]->name);
//     mx_printstr("\n");

// }

// mx_printint(head->count_flags);
 }
