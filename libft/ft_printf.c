/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:53:26 by nlyamani          #+#    #+#             */
/*   Updated: 2024/11/13 19:35:58 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	select_option(const char *format, int ind, va_list args)
{
	int	cnt;

	cnt = 0;
	if (*(format + ind + 1) == '%')
		cnt += ft_putchar('%');
	else if (*(format + ind + 1) == 'c')
		cnt += ft_putchar((char) va_arg(args, int));
	else if (*(format + ind + 1) == 'd' || *(format + ind + 1) == 'i')
		cnt += ft_putnbr(va_arg(args, int));
	else if (*(format + ind + 1) == 'u')
		cnt += ft_putunsnbr(va_arg(args, unsigned int));
	else if (*(format + ind + 1) == 'X')
		cnt += ft_puthex(va_arg(args, unsigned int), 1);
	else if (*(format + ind + 1) == 'x')
		cnt += ft_puthex(va_arg(args, unsigned int), 0);
	else if (*(format + ind + 1) == 's')
		cnt += ft_putstr(va_arg(args, char *));
	else if (*(format + ind + 1) == 'p')
		cnt += ft_putptr(va_arg(args, void *));
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ind;
	int		cnt;

	ind = 0;
	cnt = 0;
	if (format != NULL)
	{
		va_start(args, format);
		while (*(format + ind) != '\0')
		{
			if ((*(format + ind) == '%' && *(format + ind + 1) != '\0'))
			{
				cnt += select_option((char *)format, ind, args);
				ind += 2;
			}
			else
				cnt += ft_putchar(*(format + ind++));
		}
		va_end(args);
	}
	return (cnt);
}
/*
#include <stdio.h>
int main(void)
{
	printf("Caso %% 1 : \n");
	int c1cntft = ft_printf("%%");
	int c1cntpf = printf("%%"); 
	printf("\n");
	ft_printf("c1cntft = %d ;;;;; c1cntpf %d", c1cntft, c1cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso %% 2 \n");
	int c2cntft = ft_printf("%% %% %%");
	int c2cntpf = printf("%% %% %%"); 
	printf("\n");
	ft_printf("c2cntft = %d ;;;;; c2cntpf %d", c2cntft, c2cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso char 3 : \n");
	int c3cntft = ft_printf("%c", 'a');
	int c3cntpf = printf("%c", 'a');
	printf("\n");
	ft_printf("c3cntft = %d ;;;;; c3cntpf = %d", c3cntft, c3cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso char 3sp : \n");
	int c3spcntft = ft_printf("%c", 12);
	int c3spcntpf = printf("%c", 12);
	printf("\n");
	ft_printf("c3spcntft = %d ;;;;; c3spcntpf = %d", c3spcntft, c3spcntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso char 4 : \n");
	int c4cntft = ft_printf("%c %c", '1', 'c');
	int c4cntpf = printf("%c %c", '1', 'c');
	printf("\n");
	ft_printf("c4cntft = %d ;;;;; c4cntpf = %d", c4cntft, c4cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso digit 5 : \n");
	int c5cntft = ft_printf("%d %d", 1, 0);
	int c5cntpf = printf("%d %d", 1, 0);
	printf("\n");
	ft_printf("c1cntft = %d ;;;;; c1cntpf = %d", c5cntft, c5cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso digit 6 : \n");
	int c6cntft = ft_printf("%d", -1);
	int c6cntpf = printf("%d", -1);
	printf("\n");
	ft_printf("c6cntft = %d ;;;;; c6cntpf = %d", c6cntft, c6cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso digit 7 : \n");
	int c7cntft = ft_printf("%d", 122355445);
	int c7cntpf = printf("%d", 122355445);
	printf("\n");
	ft_printf("c7cntft = %d ;;;;; c7cntpf = %d", c7cntft, c7cntpf);
	printf("\n");
	printf("/////////////////////////////////");


	printf("Caso digit 8 : \n");
	int c8cntft = ft_printf("%d", -122355445);
	int c8cntpf = printf("%d", -122355445);
	printf("\n");
	ft_printf("c8cntft = %d ;;;;; c8cntpf = %d", c8cntft, c8cntpf);
	printf("\n");
	printf("/////////////////////////////////");


	printf("Caso digit 9 : \n");
	int c9cntft = ft_printf("%d", 0);
	int c9cntpf = printf("%d", 0);
	printf("\n");
	ft_printf("c9cntft = %d ;;;;; c9cntpf = %d", c9cntft, c9cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso digit i 10 : \n");
	int c10cntft = ft_printf("%i", 0);
	int c10cntpf = printf("%i", 0);
	printf("\n");
	ft_printf("c10cntft = %d ;;;;; c10cntpf = %d", c10cntft, c10cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso u digit 11 : \n");
	int c11cntft = ft_printf("%u", -1);
	int c11cntpf = printf("%u", -1);
	printf("\n");
	ft_printf("c11cntft = %d ;;;;; c11cntpf = %d", c11cntft, c11cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso u digit 12 : \n");
	int c12cntft = ft_printf("%u", 0);
	int c12cntpf = printf("%u", 0);
	printf("\n");
	ft_printf("c12cntft = %d ;;;;; c12cntpf = %d", c12cntft, c12cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso u digit 13 : \n");
	int c13cntft = ft_printf("%u", 10);
	int c13cntpf = printf("%u", 10);
	printf("\n");
	ft_printf("c13cntft = %d ;;;;; c13cntpf = %d", c13cntft, c13cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso u digit 13 sp : \n");
	int c13spcntft = ft_printf("%u %u", 10, 13);
	int c13spcntpf = printf("%u %u", 10, 13);
	printf("\n");
	ft_printf("c13spcntft = %d ;;;;; c13spcntpf = %d", c13spcntft, c13spcntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso hex 14 : \n");
	int c14cntft = ft_printf("%X %x %X %x ", 10, 10, 2024, 2024);
	int c14cntpf = printf("%X %x %X %x ", 10, 10, 2024, 2024);
	printf("\n");
	ft_printf("c14cntft = %d ;;;;; c14cntpf = %d", c14cntft, c14cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	printf("Caso str 15 : \n");
	int c15cntft = ft_printf("%s ", "Ek gee dit nie vir julle soos die wêreld");
	int c15cntpf = printf("%s ", "Ek gee dit nie vir julle soos die wêreld");
	printf("\n");
	ft_printf("c15cntft = %d ;;;;; c15cntpf = %d", c15cntft, c15cntpf);
	printf("\n");
	printf("/////////////////////////////////");


	int ptr;
	printf("Caso ptr 16 : \n");
	int c16cntft = ft_printf("%p ", &ptr);
	int c16cntpf = printf("%p ", &ptr);
	printf("\n");
	ft_printf("c16cntft = %d ;;;;; c16cntpf = %d", c16cntft, c16cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	int ptr1;
	int *ptr2 = &ptr1;
	printf("Caso ptr 17 : \n");
	int c17cntft = ft_printf("%p ", ptr2);
	int c17cntpf = printf("%p ", ptr2);
	printf("\n");
	ft_printf("c17cntft = %d ;;;;; c17cntpf = %d", c17cntft, c17cntpf);
	printf("\n");
	printf("/////////////////////////////////");

	return (0);
}
*/
