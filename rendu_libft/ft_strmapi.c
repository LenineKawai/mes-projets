/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:32:32 by mgolinva          #+#    #+#             */
/*   Updated: 2021/11/15 10:07:50 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		i;
	char	*dup;

	if (!str)
		return (0);
	i = 0;
	dup = ft_strdup(str);
	if (!dup)
		return (0);
	while (dup[i])
	{
		dup[i] = (*f)(i, dup[i]);
		i ++;
	}
	return (dup);
}
