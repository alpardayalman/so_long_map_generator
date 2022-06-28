/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ardayalman <ardayalman@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:32:38 by ardayalman        #+#    #+#             */
/*   Updated: 2022/06/28 15:32:39 by ardayalman       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_gen.h"

//char name, int width int height, int collectibles, int exits.
int main(int ac, char **av)
{
	struct s_info	*main;

	system("CLEAR");
	if (ac < 4 || ac > 6)
		return 0;
	main = info_init(ac, av);
	write2file(main);
	ft_putstr_color_fd(ANSI_GREEN,"Your file has been created as: ",1);
	ft_putstr_color_fd(ANSI_YELLOW,main->name,1);
	printf("\n");
	system("LS");
	ft_putstr_color_fd(ANSI_RED,"You can find your .ber file in maps directory.\n",1);
	system("MV *.ber maps/");
	system("ls maps/");
}