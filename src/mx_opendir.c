#include "uls.h"

static int count_inside_dir(t_lit **new_d) {
    int count = 0;
    t_lit *tmp = *new_d;
    DIR *dtr;
    struct dirent *ds;


    lstat(tmp->fullpath, &(tmp->t_st));
    if (MX_IS_DIR(tmp->t_st.st_mode) || MX_IS_LNK(tmp->t_st.st_mode)) {
        if ((dtr = opendir(tmp->fullpath)) != NULL) {
            while ((ds = readdir(dtr)) != NULL)
                if (ds->d_name[0] != '.') {// need make checkA
                    count++;
                }
                closedir(dtr);
        }
        else {
            (*new_d)->error = mx_strdup(strerror(errno));
            return -1;
        }
    }
    return count;
}

static t_lit *createnode(char *name, char *path) {
    t_lit *node = (t_lit *)malloc(1 * sizeof(t_lit));

    node->name = mx_strdup(name);
    node->fullpath = mx_strdup(path);
    mx_join(&node->fullpath, "/");
    mx_join(&node->fullpath, name);
    node->error = NULL;
    if (lstat(node->fullpath, &(node->t_st)) == -1)
        node->error = mx_strdup(strerror(errno));
    node->open = NULL;
    return node;
}

void mx_opendir(t_lit **new_d, t_head *head) {
    DIR *dtr;
    struct dirent *ds;
    int count_dir = 0;

    if (!new_d)
        return;

        for (int i = 0; new_d[i] != NULL; i++) { // open -> make array
        if (new_d[i] != 0) {
            count_dir = count_inside_dir(&(new_d[i])); // head for check flag A);
            if (count_dir > 0) {
                new_d[i]->open = malloc((count_dir + 1) * sizeof(t_lit *));
                if ((dtr = opendir(new_d[i]->fullpath)) != NULL) {
                    for (count_dir = 0; (ds = readdir(dtr)) != NULL ; ) {
                        if (ds->d_name[0] != '.') // need make checkA
                            new_d[i]->open[count_dir++] = createnode(ds->d_name, new_d[i]->fullpath);
                        new_d[i]->open[count_dir] = NULL;
                    }
                closedir(dtr);
                }
            }
        }
        }
        // int x = 0;
        //     int r = 1;
        //     if (new_d[x]){
        //       for (int x = 0; new_d[x] != NULL; x++)   {
        //         if (new_d[x]->open != NULL) {
        //             for (int j = 0; new_d[x]->open[j] != NULL; j++) {
        //             mx_printstr(new_d[x]->open[j]->fullpath);
        //             mx_printstr("\n");
                   
        //         }
        //         mx_printstr("\n");
        //         if (r) {
        //             mx_del_fils(&new_d[x]->open, head);
        //             if (new_d[x]->open != NULL)
        //                 mx_opendir(new_d[x]->open, head);
        //         }
        //     }
            // if (new_d[x]){
            //     for (int j = 0; new_d[x]->open[j] != NULL; j++) {
            //         if (new_d[x]->open[j]->what_is_it == 2) {
            //         mx_printstr(new_d[x]->open[j]->fullpath);
            //         mx_printstr("\n");
            //         }
            //     }
            // }
             //  нужно сделать вивод (сверху) --> если есть флаг -R ---> удалить все файли --->визвать заново mx_opendir
             if (head) {
                 
             }
}
// }
// }

