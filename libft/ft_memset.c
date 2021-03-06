/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojustine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:55:13 by ojustine          #+#    #+#             */
/*   Updated: 2020/03/04 13:55:14 by ojustine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	register unsigned char	*mem;
	register uint64_t		stamp_64;
	register uint64_t		*ptr_64;

	mem = (unsigned char*)b;
	if (n >= 8)
	{
		stamp_64 = 0xffU & (uint32_t)c;
		stamp_64 = (stamp_64 << 0x8U) | stamp_64;
		stamp_64 = (stamp_64 << 0x10U) | stamp_64;
		stamp_64 = (stamp_64 << 0x20U) | stamp_64;
		ptr_64 = (uint64_t*)mem;
		while (n >= 8)
		{
			*ptr_64++ = stamp_64;
			mem += 8;
			n -= 8;
		}
	}
	while (n--)
		*mem++ = (unsigned char)c;
	return (b);
}
