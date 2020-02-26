#include "uls.h"

int main(int argc, char *argv[]) {
    t_head head;

    mx_memset(&head, 0, sizeof(t_head)); // зануляем структуру head
    head.flags = (int *)malloc(sizeof(int) * mx_strlen(MY_FLAGS)); // присваиваем  память масиву int 
    mx_memset(head.flags, 0, mx_strlen(MY_FLAGS) * sizeof(int)); // зануляем масив на наше количество флагов
    head.count_flags = head.count_flags + mx_check_flags(argc, argv, &head); //заполнили масив флагов(0001001), и подсчитали где заканчиваются флаги 

    mx_parse(argc, argv, &head);


// system("leaks uls");
return 0;
}

