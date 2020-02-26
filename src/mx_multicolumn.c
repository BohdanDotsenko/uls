#include "uls.h"

int max_len_names(t_lit **names, int ind) {
    int max = 0;
    int temp = 0;

    for (int i = 0; names[ind]->open[i]; i++) {
        temp = mx_strlen(names[0]->open[i]->name);
        if (temp > max)
            max = temp;
    }
    if (max % 8 == 0)
        max += 8;
    else
        max = 8 - (max % 8) + max;
    return max;
}

void mx_print_tab(int len, int maxlen) {
    int count = 0;
    int p;

    p = maxlen - len;
    if (p % 8 != 0)
        count = (p / 8) + 1;
    else
        count = p / 8;
    for (int i = 0; i < count; i++)
        mx_printchar('\t');
}

static void printcols(t_lit **names, int rows, int num, int maxlen, int ind) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; i + j < num; j += rows) {
            mx_printstr(names[ind]->open[i + j]->name);
            if (names[0]->open[i + j + 1] && (i + j + rows < num))
                mx_print_tab(mx_strlen(names[ind]->open[j + i]->name), maxlen);
        }
        if (i != rows - 1)
            mx_printchar('\n');
    }
}

static void print_names(t_lit **names, int maxlen, int wincol, int ind) {
    int rows;
    int cols = (wincol / maxlen) != 0 ? wincol / maxlen : 1;
    int num = 0;

    for(;names[ind]->open[num] != NULL; num++) {
    }
    if (maxlen * cols > wincol && cols != 1)
        cols--;
    if (num * maxlen > wincol) {
        rows = num / cols;
        if (rows == 0 || num % cols != 0)
            rows += 1;
        printcols(names, rows, num, maxlen, ind);
    } else
        for (int i = 0; names[i] != NULL; i++) {
                for (int j = 0; names[i]->open[j] != NULL; j++) {
                mx_printstr(names[i]->open[j]->name);

                if (names[i]->open[j] != NULL && names[i]->open[j + 1]) {
                    mx_print_tab(mx_strlen(names[i]->open[j + 1]->name), maxlen);
                    // mx_printint(mx_strlen(names[i]->open[j]->name));
                    // mx_printchar('\n');
                    }
                }
        }
        // for (int i = 0; names[i]; i++) {
        //     // mx_printstr(names[i]->name);
        //                 mx_printint(0);
        //     if (names[i + 1]) 
        //         mx_print_tab(mx_strlen(names[i]->name), maxlen);
        // }
        mx_printchar('\n');
}

void mx_multi(t_lit **names, int ind) {
    int maxlen;
    struct winsize win;

    if (!names)
        return;
    maxlen = max_len_names(names, ind);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (isatty(1))
        print_names(names, maxlen, win.ws_col, ind);
    else
        print_names(names, maxlen, 80, ind);
}
