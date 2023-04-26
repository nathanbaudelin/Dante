/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** create_map
*/
#include "../include/generator.h"

void wall_void (char *line, int *info)
{
    char c = '0';
    int stop = 0;
    for (int i = 0; i < info[1]; i++) {
        stop = 0;
        if (c == '0') {
            line[i] = c;
            c = c + 40;
            stop = 1;
        }
        if (c == 'X' && stop == 0) {
            line[i] = c;
            c = c - 40;
        }
    }
}

void fill_line (char *line, int ind, int *info)
{
    if ((ind % 2) == 0) {
        wall_void (line, info);
    } else
        for (int i = 0; i < info[1]; i++)
            line[i] = 'X';
    line[info[1]] = '\0';
}

char **create_map (int *info)
{
    char **map = malloc (sizeof(char *) * (info[0] + 1));
    for (int i = 0; i < info[0]; i++) {
        map[i] = malloc (sizeof(char) * (info[1] + 1));
        fill_line(map[i], i, info);
    }
    map[info[0]] = NULL;
    map[0][0] = '*';
    return map;
}
