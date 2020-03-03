#include "uls.h"

static int check_valid_nd(t_lit **args) {
    int count = 0 ;

    for (int i = 0; args[i] != NULL; i++) {
        if (!args[i]->error)
            count++;
    }
    return count;
}

static t_lit** arg(t_lit **args) {
    int valid_node = check_valid_nd(args);
    t_lit **new_args = mx_make_new_list(args, valid_node);
    return new_args;
}

static void print_err(t_lit **arg, t_head *head) {
    for (int i = 0; arg[i] != NULL; i++) {
        if (arg[i]->error) {
            head->sum_err = head->sum_err + 1;//NEW
            mx_printerr("uls: ");
            mx_printerr(arg[i]->name);
            mx_printerr(": ");
            mx_printerr(arg[i]->error);
            mx_printerr("\n");
        }
    }
}

void mx_parse(int argc, char **argv, t_head *head) {
    int count = head->count_flags;
    t_lit **args = mx_getname(argc, argv, count);

    mx_sort_asci(&args); // sort argument of ASCI
    print_err(args, head); // print error
    args = arg(args); // array without errors
    mx_indification_args(args, head);
    mx_del_list(&args);
    return;
}
