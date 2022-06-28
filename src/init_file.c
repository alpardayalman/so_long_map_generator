/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardayalman <ardayalman@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:32:44 by ardayalman        #+#    #+#             */
/*   Updated: 2022/06/28 15:32:45 by ardayalman       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_gen.h"

void	write2file(struct s_info *main)
{
	FILE	*fp;
	int		i;
	char	**map;

	fp = fopen(main->name,"w");
	map = mapgen(main);
	i = 0;
	for (; i < main->height-1;i++)
		fprintf(fp,"%s\n",map[i]);
	fprintf(fp,"%s",map[i]);
	fclose(fp);
	free_map(main, map);
}

void	add_name_of_file(struct s_info *ret)
{
	int		i;
	char	*decoy;

	for (;ret->name[i];i++);
	decoy = malloc(i+5);
	for (i = 0;ret->name[i];i++)
		decoy[i] = ret->name[i];
	decoy[i] = '.';
	decoy[i+1] = 'b';
	decoy[i+2] = 'e';
	decoy[i+3] = 'r';
	decoy[i+4] = '\0';
	ret->name = ft_strdup(decoy);
	free(decoy);
}

struct s_info	*info_init(int ac, char **av)
{
	struct s_info	*ret;

	ret = (struct s_info *) malloc(sizeof(struct s_info));
	ret->name = ft_strdup(av[1]);
	add_name_of_file(ret);
	ret->width = ft_atoi(av[2]);
	ret->height = ft_atoi(av[3]);
	ret->collectibles = find_min(ret->width, ret->height) * 2;
	ret->exits = 1;
	if (ac > 4)
	{
		int	ex = ft_atoi(av[4]);
		ret->collectibles = (ex>0 && ex < 100)?ex:5;
	}
	if (ac > 5)
	{
		int	ex = ft_atoi(av[5]);
		ret->exits = (ex>0 && ex < 5)?ex:5;
	}
	return (ret);
}

void	free_map(struct s_info *main,char **map)
{
	for (int i = 0; i < main->height;i++)
		free(map[i]);
}