/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:19:49 by msimic            #+#    #+#             */
/*   Updated: 2024/01/03 21:19:49 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int argument)
{
	return (argument >= 0 && argument <= 127);
}
