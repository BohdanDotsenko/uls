#include "uls.h"

void mx_one(t_lit **new_d) {
    for (int i = 0; new_d[i]; i ++) {
        mx_printstr(new_d[i]->name);
        if (new_d[i]) 
            mx_printchar('\n');
    }
}
