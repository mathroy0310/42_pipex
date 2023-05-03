/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:11:37 by maroy             #+#    #+#             */
/*   Updated: 2023/04/21 16:10:26 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	len = (int) ft_strlen(s1) + 1;
	s2 = malloc(sizeof (char) * len);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
