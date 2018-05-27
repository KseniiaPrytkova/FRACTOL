/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 18:29:51 by kprytkov          #+#    #+#             */
/*   Updated: 2017/12/20 18:29:56 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		how_many_digits(int n)
{
	int		counter;
	long		positive_n;

	counter = 0;
	positive_n = (long)n;
	if (n <= 0)
	{
		counter = counter + 1;
		positive_n = (long)(n);
		positive_n = -positive_n;
	}
	while (positive_n > 0)
	{
		positive_n = positive_n / 10;
		counter++;
	}
	return (counter);
}

static void		convert_positive(char *string, long positive_n)
{
	if (positive_n == 0)
		*(string - 1) = '0';
	while (positive_n > 0)
	{
		string--;
		*string = '0' + (positive_n % 10);
		positive_n = positive_n / 10;
	}
}

char			*ft_itoa(int n)
{
	char		*final_storage;
	char		*result;
	int		digits_nb;
	long		positive_n;

	digits_nb = how_many_digits(n);
	final_storage = malloc(sizeof(char) * digits_nb + 1);
	if (!(result = final_storage))
		return (NULL);
	positive_n = (long)n;
	if (n < 0)
	{
		positive_n = (long)(n);
		positive_n = -positive_n;
		*final_storage = '-';
	}
	final_storage = final_storage + digits_nb;
	*final_storage = '\0';
	convert_positive(final_storage, positive_n);
	return (result);
}
