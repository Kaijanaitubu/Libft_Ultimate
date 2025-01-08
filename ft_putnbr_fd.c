/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubu <tubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:50:11 by kmogami           #+#    #+#             */
/*   Updated: 2025/01/08 15:55:33 by tubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ult.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		len;
	char	num[13];

	len = 1;
	while (!(n / power(10, len - 1) < 10 && n / power(10, len - 1) > -10))
		len++;
	i = 0;
	if (n < 0)
		num[i++] = '-';
	while (len-- > 0)
		num[i++] = abs(n / power(10, len) % 10) + '0';
	num[i] = '\0';
	write(fd, num, i);
}
