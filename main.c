#include "uls.h"

int main(int argc, char *argv[]) {
    t_head head;
    t_li *list = NULL;



    mx_memset(&head, 0, sizeof(t_head)); // зануляем структуру head
    head.flags = (int *)malloc(sizeof(int) * mx_strlen(MY_FLAGS)); // присваиваем  память масиву int 
    mx_memset(head.flags, 0, mx_strlen(MY_FLAGS) * sizeof(int)); // зануляем масив на наше количество флагов
    head.count_flags = head.count_flags + mx_check_flags(argc, argv, &head); //заполнили масив флагов(0001001), и подсчитали где заканчиваются флаги 
    list = mx_determine_argv(argc, argv, &head);
    for (int i = 0; i < mx_strlen(MY_FLAGS); i ++) {
        printf("%d", head.flags[i]);
        printf("\n");
    }

    // mx_sort_asci(list); // нужно сделать сортировку 
//system("leaks uls");
return 0;
}

