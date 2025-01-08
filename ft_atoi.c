/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:45:41 by kmogami           #+#    #+#             */
/*   Updated: 2025/01/08 15:55:48 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ult.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	num;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num > LONG_MAX / 10) || ((num == LONG_MAX / 10) && (*str > 55)))
		{
			if (sign == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		num = (num * 10) + (str[i++] - '0');
	}
	return ((int)(num * sign));
}
