/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeruma <jmeruma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:05:51 by jmeruma           #+#    #+#             */
/*   Updated: 2022/11/18 10:51:57 by jmeruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	lenght(int n);
static void	calc(char *ptr, int n, int sign, int counter);
static char	*checkmin(void);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		counter;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	if (n < 0)
	{
		sign = -1;
		n *= sign;
	}
	if (n == -2147483648)
	{
		ptr = checkmin();
		return (ptr);
	}
	counter = lenght(n);
	if (sign == -1)
		counter++;
	ptr = ft_calloc(counter + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	calc(ptr, n, sign, counter);
	return (ptr);
}

static int	lenght(int n)
{
	int		i;
	int		counter;

	i = 10;
	counter = 1;
	while (n >= 10)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static void	calc(char *ptr, int n, int sign, int counter)
{
	int	i;

	i = 0;
	if (sign == -1)
		ptr[i] = '-';
	ptr[counter] = '\0';
	counter--;
	while (counter >= 0 && ptr[counter] != '-')
	{
		ptr[counter] = n % 10 + '0';
		n /= 10;
		counter--;
	}
}

static char	*checkmin(void)
{
	char	*ptr;

	ptr = ft_strdup("-2147483648");
	return (ptr);
}
