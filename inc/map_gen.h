#ifndef HEAD_DATA
# define HEAD_DATA
#include "../libft/include/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

struct s_info
{
	char	*name;
	int		height;
	int		width;
	int		collectibles;
	int		exits;
};


void			write2file(struct s_info *main);
void			add_name_of_file(struct s_info *ret);
struct s_info	*info_init(int ac, char **av);
void			free_map(struct s_info *main, char **map);

int				give_random_no(void);
int				find_min(int i, int j);
int				find_max(int i, int j);
char			**mapgen(struct s_info *main);
#endif