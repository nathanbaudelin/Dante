/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** create_maze
*/
#include "../include/generator.h"

int imperfect_maze_2 (spaghetti_t *p, int i, int j)
{
    if (p->map[i][j] == 'X') {
        if (p->map[i - 1][j] == '*' && p->map[i + 1][j] == '*') {
            p->map[i][j] = '*';
            return -1;
        }
        if (p->map[i][j + 1] == '*' && p->map[i][j - 1] == '*') {
            p->map[i][j] = '*';
            return -1;
        }
    }
    return 0;
}

void imperfect_maze (spaghetti_t *pasta_box)
{
    perfect_maze (pasta_box, 0, 0);
    int stop = 0;
    int i = 1;
    int j = 1;
    for (; i < (pasta_box->info[0] - 2) && stop == 0; i++)
        for (; j < (pasta_box->info[1] - 2) && stop == 0; j++)
            stop = imperfect_maze_2 (pasta_box, i, j);
    return;
}

void add_final (spaghetti_t *pasta)
{
    if ((pasta->info[0] % 2) == 0 && (pasta->info[1] % 2) == 0) {
        int nb = rand () % 2;
        if (nb == 0){
            pasta->map[pasta->info[0] - 1][pasta->info[1] - 1] = '*';
            pasta->map[pasta->info[0] - 1][pasta->info[1] - 2] = '*';
        } else {
            pasta->map[pasta->info[0] - 1][pasta->info[1] - 1] = '*';
            pasta->map[pasta->info[0] - 2][pasta->info[1] - 1] = '*';
        }
    }
    if ((pasta->info[0] % 2) == 0 || (pasta->info[1] % 2) == 0)
        pasta->map[pasta->info[0] - 1][pasta->info[1] - 1] = '*';
}

void create_maze (spaghetti_t *pasta_box)
{
    if (pasta_box->info[2] == -1)
        imperfect_maze (pasta_box);
    else
        perfect_maze (pasta_box, 0, 0);
    add_final (pasta_box);
}
