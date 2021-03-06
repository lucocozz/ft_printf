/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:36:30 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/04 17:27:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_padding(char c, t_parse *data)
{
	int	pad;

	pad = (c == '-' ? 1 : 0);
	data->padding = pad;
	if (pad)
		data->fill = ' ';
	return (pad);
}

int		ft_parse_fill(char c, t_parse *data)
{
	int	fill;

	fill = (c == '0' ? 1 : 0);
	if (fill && data->precision == -1)
		data->fill = '0';
	else
		data->fill = ' ';
	return (fill);
}

int		ft_parse_width(const char *s, t_parse *data, va_list ap)
{
	int	i;
	int	nb;

	i = 0;
	if (s[i] == '*')
	{
		data->width = va_arg(ap, int);
		if (data->width < 0)
		{
			data->width = (data->width < 0 ? data->width * -1 : data->width);
			ft_parse_padding('-', data);
		}
		i++;
	}
	else
	{
		nb = ft_atoi(s);
		data->width = (nb < 0 ? nb * -1 : nb);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

int		ft_parse_precision(const char *s, t_parse *data, va_list ap)
{
	int	i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			data->precision = va_arg(ap, int);
			if (data->precision < 0)
				data->precision = -1;
			i++;
		}
		else
			data->precision = ft_atoui(&s[i]);
		if (data->precision < 0 && data->fill == '0')
			data->fill = '0';
		else
			data->fill = ' ';
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}
