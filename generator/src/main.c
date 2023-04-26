/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** main
*/
#include "../include/generator.h"

void my_limit (void)
{
    struct rlimit lim;
    getrlimit (RLIMIT_STACK, &lim);
    lim.rlim_max = 1000000000000;
    lim.rlim_cur = 1000000000000;
    setrlimit (RLIMIT_STACK, &lim);
}

int *error (char **arg)
{
    int *info = malloc (sizeof (int) * 3);
    info[1] = atoi (arg[1]);
    info[0] = atoi (arg[2]);
    if (arg[3] == NULL)
        info[2] = -1;
    else if (strcmp (arg[3], "perfect") == 0)
        info[2] = 1;
    else
        info[2] = 0;
    for (int i = 0; i < 3; i++)
        if (info[i] == 0) {
            free (info);
            return NULL;
        }
    return info;
}

int main(int ac,char **av)
{
    if (ac != 3 && ac != 4) {
        write(2, "generator: Bad number of arguments.\n", 36);
        return 84;
    }
    int *info = error (av);
    if (info == NULL) {
        write (2, "generator: Bad arguments.\n", 26);
    }
    srand (time (NULL));
    char **map = create_map (info);
    spaghetti_t *pasta_box = malloc (sizeof(spaghetti_t));
    pasta_box->map = map;
    pasta_box->info = info;
    pasta_box->neighbor = NULL;
    my_limit();
    create_maze (pasta_box);
    print_array (pasta_box->map);
    free_struct (pasta_box);
    return 0;
}
