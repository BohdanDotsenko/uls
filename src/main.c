#include "uls.h"

int main(int argc, char *argv[]) {
    t_head head;
    t_li *list = NULL;



    mx_memset(&head, 0, sizeof(t_head)); // зануляем структуру head
    head.flags = (int *)malloc(sizeof(int) * mx_strlen(MY_FLAGS)); // присваиваем  память масиву int 
    mx_memset(head.flags, 0, mx_strlen(MY_FLAGS) * sizeof(int)); // зануляем масив на наше количество флагов
    head.count_flags = head.count_flags + mx_check_flags(argc, argv, &head); //заполнили масив флагов(0001001), и подсчитали где заканчиваются флаги 
    list = mx_determine_argv(argc, argv, &head);
    for (int i = 0; i < mx_strlen(MY_FLAGS, ); i ++) {
        printf("%d", head.flags[i]);
        printf("\n");
    }

    // mx_sort_asci(list); // нужно сделать сортировку 
//system("leaks uls");
return 0;
}

// как все будет работать по итогу :
// void mx_algo(текущей директории) {
//     (функции, которые создают лист по текущей директории)
//     if (head->flags[mx_get_char_index(MY_FLAGS, 't')] = 1) 
//         mx_sortbytime
//     if (head->flags[mx_get_char_index(MY_FLAGS, 'S')] = 1)
//         mx_sortbysize
//     if (head->flags[mx_get_char_index(MY_FLAGS, 'r')] = 1)
//         mx_sortreverse

//     if (head->flags[mx_get_char_index(MY_FLAGS, c)] = '1')
//         mx_output_one
//     if (head->flags[mx_get_char_index(MY_FLAGS, c)] = 'm')
//         mx_output_m
//     if (head->flags[mx_get_char_index(MY_FLAGS, c)] = 'C')
//         mx_output_c
//     if (head->flags[mx_get_char_index(MY_FLAGS, c)] = 'l')
//         mx_output_l
//     ...

//     if (if (head->flags[mx_get_char_index(MY_FLAGS, c)] = 'R') {
//         if (node 1 == папка)
//             mx_algo( от данной папки)
//         next_node;
//     }
// }