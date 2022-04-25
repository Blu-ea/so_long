/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:18:55 by amiguez           #+#    #+#             */
/*   Updated: 2022/04/25 11:23:27 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//an strjoin malloc take 2 malloced char * and free them
char	*ft_str_malloc_join(char **s1, char **s2)
{
	char	*s_ret;

	if (!s1 || !s2)
		return (NULL);
	s_ret = ft_strjoin(*s1, *s2);
	free(*s1);
	free(*s2);
	return (s_ret);
}
