/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** my_verif_for_back_slash
*/
#include "../include/solver.h"

int my_verif_for_back_slash (char ***map, int *size)
{
    if ((*map)[size[0] - 1][size[1] - 1] == '\n') {
        write(2, "solver: No '\\n' at the end.\n", 28);
        free_array (*map);
        *map = NULL;
        free (size);
        size = NULL;
        return 1;
    }
    return 0;
}
