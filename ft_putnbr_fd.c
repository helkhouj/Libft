/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:32:10 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 13:32:35 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    if(n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
        return;
    }

    if(n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }

    if(n >= 10)
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd((n % 10) + '0', fd);
}