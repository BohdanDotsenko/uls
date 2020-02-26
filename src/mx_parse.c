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
    t_lit **new_args = mx_make_new_list(args, valid_node);     //(t_lit **)malloc((valid_node + 1) * sizeof(t_lit *));
    return new_args;
}

static void print_err(t_lit **arg) {
    for (int i = 0; arg[i] != NULL; i++) {
        if (arg[i]->error) {
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
    t_lit **args = mx_getname(argc, argv, count);// after use we need free name and path (in struct)
//     free(args);
    mx_sort_asci(&args); // sort argument of ASCI
    print_err(args); // print error
    args = arg(args); // array without errors

    mx_indification_args(args, head);// indification argc (exemple: file and dir)

//  system("leaks uls");




    
    // for (int i = 0; args[i] != NULL; i++) { // check **args // i need make sort after make this functions.
    //     // mx_printerr("ls: ");
    //     mx_printstr(args[i]->name);
    //     mx_printstr("\n");
    // }
    // mx_del_list(args);
    return;
}
