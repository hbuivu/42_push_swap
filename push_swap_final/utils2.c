/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:30:12 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/02/16 16:14:41 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	neg;

	i = 0;
	neg = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			neg *= -1;
	while (*str >= '0' && *str <= '9')
		i = (i * 10) + (*(str++) - 48);
	if ((i * neg) > 2147483647 || (i * neg) < -2147483648)
		return (3000000000);
	return (i * neg);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	i;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	buffer = malloc(count * size);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < count)
		((unsigned char *)buffer)[i++] = (unsigned char) '\0';
	return (buffer);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && (i < n -1) && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
