#include "vm.h"

t_player    *fill_player(char **argv, int argc)
{
    int sum;
    t_player *player;

    if (argc < 2)
        show_usage();
    sum = ft_count_champs(argv, 0, argc);
	if (sum > 4 || sum == 0)
		show_usage();
    player = (t_player*)malloc(sizeof(t_player) * sum);
    player[0].players = sum;
    ft_division(argv, player);
    return (player);
}

void     show_usage()
{
    ft_printf("Usage: ...\n");
    exit(-1);
}

void     find_flag(char **argv, int argc)
{
    int i;

    i = 0;
    g_graphic_flag = 0;
    g_show_map_flag = 0;
	g_debug_flag = 0;
    while (++i < argc)
        if (!ft_strcmp(argv[i], "-g"))
            g_graphic_flag = 1;
    i = 0;
    while (++i < argc)
        if (!ft_strcmp(argv[i], "-d"))
        {
            if (i != argc -1)
                g_show_map_flag = atoi(argv[i + 1]);
            else
                show_usage();
            if (g_show_map_flag <= 0)
                show_usage();
        }
	i = 0;
	while (++i < argc)
		if (!ft_strcmp(argv[i], "-v"))
			g_debug_flag = 1;
}