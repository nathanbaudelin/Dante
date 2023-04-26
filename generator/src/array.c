/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** array
*/
#include "../include/generator.h"

void free_array (char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free (array[i]);
    }
    free (array);
}

void print_array (char **array)
{
    if (array == NULL)
        return;
    int i = 0;
    for (; array[i + 1] != NULL; i++) {
        write (1, array[i], strlen (array[i]));
        write (1, "\n", 1);
    }
    write (1, array[i], strlen (array[i]));
}

void free_struct (spaghetti_t *pasta_box)
{
    free_array (pasta_box->map);
    free (pasta_box->info);
    free (pasta_box);
}
