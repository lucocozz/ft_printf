/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:38:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/04 17:37:56 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rigth_padding(t_parse data, t_buffer *buffer, char *str, int nb)
{
	int	len;

	len = ft_nbrlen((nb < 0 ? nb * -1 : nb), 10);
	if (nb < 0)
		ft_insert_format(buffer, &data, '-');
	while (data.precision > len)
	{
		ft_insert_format(buffer, &data, '0');
		data.precision--;
	}
	if (!nb && !data.precision && data.width)
		ft_insert_format(buffer, &data, ' ');
	else if (nb || data.precision)
		ft_insert_str(buffer, &data, str);
	while (data.width > 0)
		ft_insert_format(buffer, &data, ' ');
}

static void	ft_left_padding(t_parse data, t_buffer *buffer, char *str, int nb)
{
	int	len;

	len = ft_nbrlen((nb < 0 ? nb * -1 : nb), 10);
	if (nb < 0 && data.fill == '0')
		ft_insert_in_buffer(buffer, '-');
	while (data.width > len && data.width > data.precision)
	{
		if (nb < 0 && (data.width == len + 1 ||
		data.width == data.precision + 1))
			break ;
		ft_insert_format(buffer, &data, data.fill);
	}
	if (nb < 0 && data.fill == ' ')
		ft_insert_in_buffer(buffer, '-');
	else if (nb < 0 && data.precision > len)
		ft_insert_format(buffer, &data, '0');
	while (data.precision > len)
	{
		ft_insert_format(buffer, &data, '0');
		data.precision--;
	}
	if (!nb && !data.precision && data.width)
		ft_insert_format(buffer, &data, ' ');
	else if (nb || data.precision)
		ft_insert_str(buffer, &data, str);
}

void		ft_d(va_list ap, t_parse data, t_buffer *buffer)
{
	int		nb;
	char	*str;

	nb = va_arg(ap, int);
	if (nb == -2147483648)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa((nb < 0 ? nb * -1 : nb));
	if (data.padding)
		ft_rigth_padding(data, buffer, str, nb);
	else
		ft_left_padding(data, buffer, str, nb);
	ft_strdel(str);
}

void		ft_i(va_list ap, t_parse data, t_buffer *buffer)
{
	ft_d(ap, data, buffer);
}
