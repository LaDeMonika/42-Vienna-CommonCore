/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimic <msimic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:00:22 by msimic            #+#    #+#             */
/*   Updated: 2023/09/15 17:34:05 by msimic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_check(char const s, char const c)
{
	if (s == c)
		return (1);
	else
		return (0);
}

static int	count(char const *str, char const c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && c_check(str[i], c))
			++i;
		if (str[i] != '\0')
			++count;
		while (str[i] != '\0' && !c_check(str[i], c))
			++i;
	}
	return (count);
}

static char	*ft_word(char const *str, char const c)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	len = 0;
	while (str[len] && !c_check(str[len], c))
		++len;
	word = (char *)malloc((len + 1) * sizeof (char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

static int	checknull(char **array, size_t i)
{
	size_t	f;

	f = 0;
	if (array[i] == NULL)
	{
		while (f < i)
		{
			free (array[f]);
			f++;
		}
		free (array);
		return (0);
	}
	else
		return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**array;

	i = 0;
	j = 0;
	array = (char **) malloc((count(s, c) + 1) * sizeof(char *));
	if (!s || array == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && c_check(s[j], c))
			++j;
		if (s[j] != '\0')
		{
			array[i++] = ft_word(&s[j], c);
			if (checknull(array, i - 1) == 0)
				return (0);
		}
		while (s[j] != '\0' && !c_check(s[j], c))
			++j;
	}
	array[i] = 0;
	return (array);
}
