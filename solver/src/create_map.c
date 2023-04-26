/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-dante-pierre.giordano
** File description:
** create_map
*/
#include "../include/solver.h"

int verif_char (char *buffer)
{
    if (buffer == NULL)
        return -1;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != '*' && buffer[i] != 'X' && buffer[i] != '\n') {
            return -1;
        }
    }
    return 0;
}

void calcul_size (char *filepath, int **size)
{
    FILE *fp = fopen (filepath, "r");
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;
    while ((read = getline (&buffer, &len, fp)) != -1) {
        size[0][0] = size[0][0] + 1;
        if (verif_char(buffer) != -1 && (size[0][1] == 0 || size[0][1] == read
            || (size[0][1] == (read + 1) && buffer[read - 1] != '\n')))
            size[0][1] = read;
        else {
            write (2, "solver: Bad map.\n", 17);
            free (size[0]);
            size[0] = NULL;
            break;
        }
    }
    free (buffer);
    fclose (fp);
}

int *verif_file (char *filepath)
{
    int *size = NULL;
    struct stat info;
    if (stat (filepath, &info) != 0) {
        write (2, "solver: No such file.\n", 22);
        return size;
    }
    if (S_ISREG (info.st_mode) == 0) {
        write (2, "solver: Not a file.\n", 20);
        return size;
    }
    if (info.st_size == 0) {
        write (2, "solver: Empty file.\n", 20);
        return size;
    }
    size = malloc (sizeof(int) * 2);
    size[0] = 0;
    size[1] = 0;
    calcul_size (filepath, &size);
    return size;
}

char **create_map (char *filepath, int *size)
{
    char **map = malloc (sizeof(char *) * (size[0] + 1));
    FILE *fp = fopen (filepath, "r");
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int ind = 0;
    while ((read = getline (&buffer, &len, fp)) != -1) {
        map[ind] = malloc (sizeof(char) * (size[1] + 1));
        strncpy (map[ind], buffer, size[1]);
        map[ind][size[1]] = '\0';
        ind++;
    }
    map[ind] = NULL;
    free (buffer);
    fclose (fp);
    if (my_verif_for_back_slash(&map, size) == 1)
        return NULL;
    return map;
}
