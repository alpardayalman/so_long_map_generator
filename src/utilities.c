/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardayalman <ardayalman@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:32:41 by ardayalman        #+#    #+#             */
/*   Updated: 2022/06/28 15:32:42 by ardayalman       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_gen.h"

int	give_random_no()
{
	return (rand() % 100);
}

int	find_min(int i, int j)
{
	return (i<j?i:j);
}

int	find_max(int i, int j)
{
	return (i<j?j:i);
}

char	**mapgen(struct s_info *main)
{
	char	**ret;
	bool	flag;

	flag = true;
	ret = (char **)malloc(sizeof(char *) * main->height);
	for (int i = 0,j=0; i < main->height; i++)
	{
		ret[i] = malloc(main->width+1);
		j = 0;
		for (; j < main->width;j++)
		{
			ret[i][j] = (j==0||i==0||i==main->height-1||j==main->width-1)?
			'1':(give_random_no()>=90&&main->exits-- >0)?
			'E':(give_random_no()<8&&main->collectibles-->0)?
			'C':(give_random_no()<30&&flag)?
			'P':(give_random_no()>=75||give_random_no()<=15)?
			'1':'0';
			if (ret[i][j] == 'P')
				flag = false;
		}
		ret[i][j] = '\0';
	}
	return (ret);
}
