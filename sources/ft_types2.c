/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:59:52 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/22 03:36:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u(va_list ap, t_flags flags)
{
	unsigned int	nb;

	flags = flags;
	nb = va_arg(ap, unsigned int);
	return (ft_uitoa_base(nb, "012346789abcdef"));	
}

char	*ft_x(va_list ap, t_flags flags)
{
	int	nb;

	flags = flags;
	nb = va_arg(ap, int);
	return (ft_itoa_base(nb, "012346789abcdef"));
}

char	*ft_xu(va_list ap, t_flags flags)
{
	int	nb;

	flags = flags;
	nb = va_arg(ap, int);
	return (ft_itoa_base(nb, "012346789ABCDEF"));
}

char	*ft_per(va_list ap, t_flags flags)
{
	ap = ap;
	flags = flags;
	return (ft_strdup("%"));	
}