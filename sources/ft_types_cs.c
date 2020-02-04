/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/04 17:08:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(va_list ap, t_parse data, t_buffer *buffer)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (data.padding)
	{
		ft_insert_format(buffer, &data, c);
		while (data.width > 0)
			ft_insert_format(buffer, &data, ' ');
	}
	else
	{
		while (data.width > 1)
			ft_insert_format(buffer, &data, data.fill);
		ft_insert_format(buffer, &data, c);
	}
}

static void	ft_rigth_padding(t_parse data, t_buffer *buffer, char *str)
{
	int	i;

	i = 0;
	if (data.precision == -1)
		while (str[i])
			ft_insert_format(buffer, &data, str[i++]);
	else
		while (str[i] && data.precision-- > 0)
			ft_insert_format(buffer, &data, str[i++]);
	while (data.width > 0)
		ft_insert_format(buffer, &data, ' ');
}

static void	ft_left_padding(t_parse data, t_buffer *buffer, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (data.precision == -1)
		len = len;
	else
		len = (len < data.precision ? len : data.precision);
	while (data.width > len)
		ft_insert_format(buffer, &data, data.fill);
	while (len-- > 0)
		ft_insert_in_buffer(buffer, str[i++]);
}

void	ft_s(va_list ap, t_parse data, t_buffer *buffer)
{
	char	*str;

	str = va_arg(ap, char*);
	str = (!str ? "(null)" : str);
	if (data.padding)
		ft_rigth_padding(data, buffer, str);
	else
		ft_left_padding(data, buffer, str);
}
