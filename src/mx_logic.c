#include "uls.h"


void mx_logic(t_lit **new_d, t_head *head) {
    mx_opendir(new_d, head);
    int flag = 0;
        // mx_sort_asci(new_d);
//     if (head->flags[mx_get_char_index(MY_FLAGS, 't')] == 1) 
// //         mx_sortbytime
//     if (head->flags[mx_get_char_index(MY_FLAGS, 'S')] == 1)
// //         mx_sortbysize
//     if (head->flags[mx_get_char_index(MY_FLAGS, 'r')] == 1) {
// //         mx_sortreverse

    
if (new_d[1] != NULL)
    flag = 1;
 for (int i = 0; new_d[i] != NULL; i++) {
        if (flag == 1) {
            mx_printstr(new_d[i] ->fullpath);
            mx_printstr(":\n");
        }
        if (head->flags[mx_get_char_index(MY_FLAGS, '1')] == 1) {
            // mx_output_one
        }
        if (head->flags[mx_get_char_index(MY_FLAGS, 'm')] == 1) {
            // mx_output_m
        }
        if (head->flags[mx_get_char_index(MY_FLAGS, 'C')] == 1) {
            mx_multi(new_d, i);
        }
        if (head->flags[mx_get_char_index(MY_FLAGS, 'l')] == 1) {
            // mx_output_l
        }
        if (new_d[i + 1] != NULL) {
            mx_printstr("\n");
        }
    }

//     if (if (head->flags[mx_get_char_index(MY_FLAGS, c)] = 'R') {
//         if (node 1 == папка)
//             mx_algo( от данной папки)
//         next_node;
//     }


// del_files

}
