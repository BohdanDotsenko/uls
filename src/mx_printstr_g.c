#include "uls.h"

static void printstr(const char *s) {
	write(1, s, mx_strlen(s));
}

static void print_name(t_lit *args) {
    mx_new_pstr(args->name);
    printstr(LS_COLOR_RESET);
}

static int print_frst(t_lit *args) {
    if (MX_IS_DIR(args->t_st.st_mode)) {
        printstr("\033[34m");
        print_name(args);
        return 1;
    }
    else if (MX_IS_LNK(args->t_st.st_mode)) {
        printstr("\033[35m");
        print_name(args);
        return 1;
    }
    else if (args->t_st.st_mode & S_IXOTH) {
        printstr(LS_COLOR_RED);
        print_name(args);
        return 1;
    }
    return 0;
}

static int print_sec(t_lit *args) {
    if (MX_IS_BLK(args->t_st.st_mode)) {
        printstr("\033[34;46m");
        print_name(args);
        return 1;
    }
    else if (MX_IS_CHR(args->t_st.st_mode)) {
        printstr("\033[34;43m");
        print_name(args);
        return 1;
    }
    else if (MX_IS_SOCK(args->t_st.st_mode)) {
        printstr("\033[32m");
        print_name(args);
        return 1;
    }
    return 0;
}

void mx_printstr_g(t_lit *args) {
    if (print_frst(args) == 1) {
    }
    else if (print_sec(args) == 1) {
    }
    else if (MX_IS_FIFO(args->t_st.st_mode)) {
        printstr("\033[33m");
        print_name(args);
    }
    else if (MX_IS_WHT(args->t_st.st_mode)) {
        printstr("\033[36m");
        print_name(args);
    }
    else if (MX_IS_EXEC(args->t_st.st_mode)) {
        printstr("\033[31m");
        print_name(args);
    }
    else
        mx_printstr(args->name);
}
