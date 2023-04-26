/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** solver
*/
#include "../include/solver.h"

void my_solver (char **map, int i, int j, int *size)
{
    if (i < 0 || j < 0 || i >= size[0] || j >= size[1])
        return;
    if (map[i][j] == '2') {
        map[i][j] = 'o';
        print_array (map);
        free_array (map);
        free (size);
        exit (0);
    }
    if (map[i][j] != '*')
        return;
    map[i][j] = 'o';
    my_solver (map, i, (j + 1), size);
    my_solver (map, (i + 1), j, size);
    my_solver (map, i, (j - 1), size);
    my_solver (map, (i - 1), j, size);
    map[i][j] = '*';
}
