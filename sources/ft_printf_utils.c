/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:41:25 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/04 17:27:57 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parse	ft_init_parse(void)
{
	t_parse	data;

	data.padding = 0;
	data.width = 0;
	data.precision = -1;
	data.fill = ' ';
	data.type = 0;
	return (data);
}

void	ft_print_buffer(t_buffer *buffer)
{
	write(1, buffer->data, buffer->i);
	buffer->len += buffer->i;
	ft_bzero(buffer->data, PRINTF_BUFFER_SIZE);
	buffer->i = 0;
}

void	ft_insert_in_buffer(t_buffer *buffer, char c)
{
	buffer->data[buffer->i++] = c;
	if (buffer->i == PRINTF_BUFFER_SIZE - 1)
		ft_print_buffer(buffer);
}

void	ft_insert_format(t_buffer *buffer, t_parse *data, char c)
{
	ft_insert_in_buffer(buffer, c);
	data->width--;
}

void	ft_insert_str(t_buffer *buffer, t_parse *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_insert_format(buffer, data, str[i++]);
}
