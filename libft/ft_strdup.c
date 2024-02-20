/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:01:22 by akrid             #+#    #+#             */
/*   Updated: 2024/02/12 14:08:09 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s_len;
	char	*dup;

	if (s1 == NULL)
		return (NULL);
	s_len = ft_strlen(s1);
	dup = (char *)malloc((s_len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < s_len + 1)
	{
		dup[i] = (char)s1[i];
		i ++;
	}
	return (dup);
}
