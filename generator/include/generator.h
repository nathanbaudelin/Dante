/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** generator
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    typedef struct spaghetti {
        char **map;
        int *info;
        int *neighbor;
    } spaghetti_t;

    char **create_map (int *info);
    void fill_line (char *line, int ind, int *info);
    void wall_void (char *line, int *info);

    void create_maze (spaghetti_t *pasta_box);
    void perfect_maze (spaghetti_t *pasta_box, int i, int j);
    void imperfect_maze (spaghetti_t *pasta_box);

    void print_array (char **array);
    void free_array (char **array);
    void free_struct (spaghetti_t *pasta_box);

    void create_neighbor_2(int *neighbor, spaghetti_t *pasta_box, int i, int j);
    int *create_neighbor (spaghetti_t *pasta_box, int i, int j);
    int count_neighbor (int *neighbor);

    void perfect_maze (spaghetti_t *pasta_box, int i, int j);
    void cond (spaghetti_t *pasta_box, int ind, int i, int j);
    int get_dir (int *neighbor, int dir);

#endif /* !GENERATOR_H_ */
