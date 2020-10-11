#include "../cub3d.h"

// объявляем структуру и инициализируем
typedef struct  s_map 
{
    int start_map;
    int end_map;
    int max_str;
    int height_map;
    char **map;
    int direction;
}               t_map;

t_map *create_all_struct()
{
    t_map *map;

    if(!(map = (t_map*)malloc(sizeof(t_map))))
        return (NULL);
    return (map);
}

t_map *initialization_of_structures(t_map *map)
{
    map = create_all_struct();
    map->start_map = -1;
    map->end_map = -1;
    map-> height_map = -1;
    map->direction = -1;
    map->map = NULL;
    return (map);
}
//------------------------------------

int check_cell(t_map *map, char **card, char c, int i, int j)
{
    if(c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0' && c != '2')
    {
        if (c == '1' || c == ' ')
            return (0);
        else
            return (1);
    }
    if(c == 'N' || c == 'S' || c == 'W' || c == 'E')
    {
        if(map->direction > 0)
            return (1);
        map->direction = 1;
    }
    if(card[i][j + 1] == ' ' || card[i][j - 1] == ' ' || card[i + 1][j] == ' ' || card[i - 1][j] == ' ') 
        return (1);
    return(0);
}

int validator_map(t_map *map)
{
    int i;
    size_t j;

    i = 0;
    while(map->map[i])
    {
        if(map->map[i][0] != ' ' && map->map[i][0] != '1')
            return (1);
        if(map->map[i][ft_strlen(map->map[i]) - 1] != ' ' && map->map[i][ft_strlen(map->map[i]) - 1] != '1')
            return (1);
        j = 0;
        printf("%s\n", map->map[i]);
        if(i == 0 || i == map->height_map - 1) 
        {
            while(map->map[i][j])
            {
                if(map->map[i][j] == '1' || map->map[i][j] == ' ')
                    j++;
                else
                    return (1);
            }
        }
        else
        {
            j++;
            while(j < ft_strlen(map->map[i]))
            {
                if(check_cell(map, map->map, map->map[i][j], i, j))
                    return (1);
                j++;
            }
        }
        i++;
    }
    return (0);
}

int parser_map(char *argv)
{
    int i;
    int r;
    int fd;
    char *line;
    t_map *map;
    char **card;

    map = initialization_of_structures(map);
    i = 0;
    line = NULL;
    fd = open(argv, O_RDONLY);
    while((r = get_next_line(fd, &line)) > 0)
    {
        //ft_parser(map, line, i);
        i++;
        free(line);
        line = NULL;
    }
    map->end_map = i;
    close(fd);
    fd = open(argv, O_RDONLY);
    i = 0;
    while(i < map->height_map)
    {
        card[i] = (char *)malloc(sizeof(char) * map->max_str);
        get_next_line(fd, &line);
        card[i] = line;
        i++;
    }
    card[i] = NULL;
    map->map = card;
    if(validator_map(map))
    {
        printf("error map");
        return (1);
    }
    return (0);
}