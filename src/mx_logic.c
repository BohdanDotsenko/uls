#include "uls.h"

void mx_logic(t_lit **new_d, t_head *head) {
    mx_opendir(new_d, head);
        // mx_sort_asci(new_d);
//     if (head->flags[mx_get_char_index(MY_FLAGS, 't')] == 1) 
// //         mx_sortbytime
//     if (head->flags[mx_get_char_index(MY_FLAGS, 'S')] == 1)
// //         mx_sortbysize
//     if (head->flags[mx_get_char_index(MY_FLAGS, 'r')] == 1) {
// //         mx_sortreverse

    

    if (head->flags[mx_get_char_index(MY_FLAGS, '1')] == 1) {
        // mx_output_one
    }
    if (head->flags[mx_get_char_index(MY_FLAGS, 'm')] == 1) {
        // mx_output_m
    }
    if (head->flags[mx_get_char_index(MY_FLAGS, 'C')] == 1) {
        mx_multi(new_d, 0);
    }
    if (head->flags[mx_get_char_index(MY_FLAGS, 'l')] == 1) {
        // mx_output_l
    }

//     if (if (head->flags[mx_get_char_index(MY_FLAGS, c)] = 'R') {
//         if (node 1 == папка)
//             mx_algo( от данной папки)
//         next_node;
//     }


// del_files

}
