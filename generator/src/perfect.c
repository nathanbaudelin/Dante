/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** perfect
*/
#include "../include/generator.h"

int get_dir (int *neighbor, int dir)
{
    int ind = 0;
    int i;
    for (i = 0; ind != dir; i++) {
        if (neighbor[i] == 1)
            ind++;
    }
    return (i - 1);
}

void cond (spaghetti_t *pasta_box, int ind, int i, int j)
{
    if (ind == 0) {
        pasta_box->map[i - 1][j] = '*';
        pasta_box->map[i - 2][j] = '*';
        perfect_maze (pasta_box, (i - 2), j);
    }
    if (ind == 1) {
        pasta_box->map[i][j - 1] = '*';
        pasta_box->map[i][j - 2] = '*';
        perfect_maze (pasta_box, i, (j - 2));
    }
    if (ind == 2) {
        pasta_box->map[i + 1][j] = '*';
        pasta_box->map[i + 2][j] = '*';
        perfect_maze (pasta_box, (i + 2), j);
    }
    if (ind == 3) {
        pasta_box->map[i][j + 1] = '*';
        pasta_box->map[i][j + 2] = '*';
        perfect_maze (pasta_box, i, (j + 2));
    }
}

void perfect_maze (spaghetti_t *pasta_box, int i, int j)
{
    pasta_box->neighbor = create_neighbor (pasta_box, i, j);
    int nb = count_neighbor (pasta_box->neighbor);
    int dir = 0;
    while (nb != 0) {
        if (i >= (pasta_box->info[0] - 2) && j >= (pasta_box->info[1] - 2))
            break;
        dir = rand() % nb + 1;
        int ind = get_dir (pasta_box->neighbor, dir);
        free (pasta_box->neighbor);
        cond (pasta_box, ind, i, j);
        pasta_box->neighbor = create_neighbor (pasta_box, i, j);
        nb = count_neighbor (pasta_box->neighbor);
    }
    free (pasta_box->neighbor);
    return;
}
