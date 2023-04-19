/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:28:44 by maroy             #+#    #+#             */
/*   Updated: 2023/04/19 14:15:42 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//ft_printf
int		ft_printf(char *format, ...);

void	ft_putchar(int c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putunbr(unsigned int n, int *count);
void	ft_putstr(char *str, int *count);
void	ft_puthex(unsigned long n, int *count);
void	ft_putuphex(unsigned long n, int *count);
void	ft_putpointer(void *ptr, int *count);

//libft
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif