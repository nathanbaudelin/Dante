/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** solver
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#ifndef SOLVER_H_
    #define SOLVER_H_

    void print_array (char **array);
    void free_array (char **array);

    char **create_map (char *filepath, int *size);
    int *verif_file (char *filepath);
    void calcul_size (char *filepath, int **size);
    int verif_char (char *buffer);
    FILE *verif_open (char *filepath, int **size);

    void my_solver (char **map, int i, int j, int *size);
    void my_solver_b (char **map, int i, int j, int *size);
    void my_solver_h (char **map, int i, int j, int *size);
    void my_solver_d (char **map, int i, int j, int *size);
    void my_solver_g (char **map, int i, int j, int *size);

    int my_verif_for_back_slash (char ***map, int *size);

#endif /* !SOLVER_H_ */
