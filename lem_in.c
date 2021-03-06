/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:42:13 by ichubare          #+#    #+#             */
/*   Updated: 2017/10/01 17:53:44 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	join_fn(t_lem_in *lem_in, char *str)
{
	char	*res;
	char	*temp;
	int		sum;

	sum = (int)(2 + ft_strlen(lem_in->output) + ft_strlen(str));
	temp = lem_in->output;
	res = (char *)malloc(sum * sizeof(char));
	ft_strcpy(res, lem_in->output);
	ft_strcat(res, str);
	ft_strcat(res, "\n");
	free(temp);
	lem_in->output = res;
}

void	error_message(void)
{
	ft_putstr("ERROR\n");
	exit(0);
}

void	init_struct(t_lem_in **lem_in)
{
	(*lem_in) = (t_lem_in *)malloc(sizeof(t_lem_in));
	(*lem_in)->num_ants = 0;
	(*lem_in)->num_rooms = 0;
	(*lem_in)->room_end = 0;
	(*lem_in)->room_start = 0;
	(*lem_in)->num_ways = 0;
	(*lem_in)->found_start = 0;
	(*lem_in)->found_end = 0;
	(*lem_in)->found_link = 0;
	(*lem_in)->flag_rooms = 0;
	(*lem_in)->iter = 0;
	(*lem_in)->output = ft_strnew(0);
	(*lem_in)->rooms = NULL;
	(*lem_in)->links = NULL;
	(*lem_in)->ways = NULL;
	(*lem_in)->temp_room = NULL;
	(*lem_in)->temp_link = NULL;
}

int		main(void)
{
	t_lem_in	*lem_in;

	init_struct(&lem_in);
	fill_struct(lem_in);
	fill_graph(lem_in);
	ft_putstr(lem_in->output);
	write(1, "\n", 1);
	sort_ways(lem_in);
	clear_ways(lem_in);
	push_ants(lem_in);
	free_struct(lem_in);
	return (0);
}
