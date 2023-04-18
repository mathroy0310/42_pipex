/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:28:44 by maroy             #+#    #+#             */
/*   Updated: 2023/04/18 18:46:18 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//ft_printf
int					ft_printf(char *format, ...);

void				ft_putchar(int c, int *count);
void				ft_putnbr(int n, int *count);
void				ft_putunbr(unsigned int n, int *count);
void				ft_putstr(char *str, int *count);
void				ft_puthex(unsigned long n, int *count);
void				ft_putuphex(unsigned long n, int *count);
void				ft_putpointer(void *ptr, int *count);

size_t	            ft_strlen(char *s);

#endif