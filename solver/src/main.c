/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** main
*/
#include "../include/solver.h"

void my_limit (void)
{
    struct rlimit lim;
    getrlimit (RLIMIT_STACK, &lim);
    lim.rlim_max = 1000000000000;
    lim.rlim_cur = 1000000000000;
    setrlimit (RLIMIT_STACK, &lim);
}

int main(int ac,char **av)
{
    if (ac != 2) {
        write(2, "solver: Bad number of arguments.\n", 33);
        return 84;
    }
    int *size = verif_file (av[1]);
    if (size == NULL)
        return 84;
    char **map = create_map (av[1], size);
    if (map == NULL)
        return 84;
    if (map[0][0] != '*' || map[size[0] - 1][size[1] - 1] != '*') {
        write (1, "no solution file", 16);
        return 84;
    }
    map[size[0] - 1][size[1] - 1] = '2';
    my_limit();
    my_solver (map, 0, 0, size);
    write (1, "no solution found", 17);
    free_array (map);
    free (size);
}
