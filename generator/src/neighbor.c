/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** neighbor
*/
#include "../include/generator.h"

void create_neighbor_2 (int *neighbor, spaghetti_t *pasta_box, int i, int j)
{
    if (i >= (pasta_box->info[0] - 1) || (i + 1) >= (pasta_box->info[0] - 1))
        neighbor[2] = 0;
    else {
        if (pasta_box->map[i + 2][j] == '0')
            neighbor[2] = 1;
        else
            neighbor[2] = 0;
    }
    if (j >= (pasta_box->info[1] - 1) || (j + 1) >= (pasta_box->info[1] - 1))
        neighbor[3] = 0;
    else {
        if (pasta_box->map[i][j + 2] == '0')
            neighbor[3] = 1;
        else
            neighbor[3] = 0;
    }
}

int *create_neighbor (spaghetti_t *pasta_box, int i, int j)
{
    int *neighbor = malloc (sizeof(int) * 4);
    if (i <= 0 || (i - 1) <= 0)
        neighbor[0] = 0;
    else {
        if (pasta_box->map[i - 2][j] == '0')
            neighbor[0] = 1;
        else
            neighbor[0] = 0;
    }
    if (j <= 0 || (j - 1) <= 0)
        neighbor[1] = 0;
    else {
        if (pasta_box->map[i][j - 2] == '0')
            neighbor[1] = 1;
        else
            neighbor[1] = 0;
    }
    create_neighbor_2 (neighbor, pasta_box, i, j);
    return neighbor;
}

int count_neighbor (int *neighbor)
{
    int cmpt = 0;
    for (int i = 0; i < 4; i++)
        if (neighbor[i] == 1)
            cmpt++;
    return cmpt;
}
