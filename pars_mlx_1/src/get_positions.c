#include "../cub3d.h"

// void get_positions(t_map *map)
// {
//    // int columns = map->max_columns;
//     int i = 0;
//     size_t j = 0;
//     while (map->map[i][j])
//     {
//         printf("%s\n", map->map[i]);
//         while (j < ft_strlen(map->map[i]))
//         {
//             j++;
//         }
//         i++;
//     }
//     map->map[i] =0;
//     map->map[j] = 0;
// }

// int search(int *a, size_t rows, size_t cols, int x)
// {
//   size_t i, j;
//   for (i = 0; i < rows; i++)
//     for (j = 0; j < cols; j++)
//       if (a[i * cols + j] == x)
//         return 1;
//   return 0;
// }