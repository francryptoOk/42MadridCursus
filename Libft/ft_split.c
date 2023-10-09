/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantill <fsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:00:43 by fsantill          #+#    #+#             */
/*   Updated: 2023/10/09 17:22:39 by fsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substr_in_str(const char *s, char c)
{
	int		i;
	size_t	countsubstr;

	i = 0;
	countsubstr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			countsubstr++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (countsubstr);
}

static void	*arrays_freedom(char **ptr, int m)
{
	while (m > 0)
	{
		m--;
		free (ptr[m]);
	}
	free (ptr);
	return (NULL);
}

static char	**aux_strslip(char **auxstrslip, char *s, char c, \
size_t numofsubstr)
{
	int		j;
	int		x;
	size_t	len;

	j = 0;
	x = 0;
	while (j < (int)numofsubstr)
	{
		len = 0;
		while (s[x] == c)
			x++;
		while (s[x + len] != '\0' && s[x + len] != c)
			len++;
		auxstrslip[j] = ft_substr(&s[x], 0, len);
		if (!auxstrslip[j])
			return (arrays_freedom(auxstrslip, j));
		x += len;
		j++;
	}
	auxstrslip[j] = NULL;
	return (auxstrslip);
}

char	**ft_split(const char *s, char c)
{
	int		j;
	size_t	countsubstr;
	char	**strslip;
	char	**result;

	j = 0;
	countsubstr = count_substr_in_str(s, c);
	strslip = (char **)malloc((countsubstr + 1) * sizeof(char *));
	if (!strslip)
		return (NULL);
	result = aux_strslip(strslip, (char *)s, c, countsubstr);
	return (result);
}
/**
 * The static function `count_substr_in_str` counts the number of substrings
 * in a given string that are separated by a specified character.
 * 
 * @param s The parameter `s` is a pointer to a character array (string)
 * that represents the input string.
 * @param c The parameter `c` is a character that we want to count the
 * occurrences of in the string `s`.
 * 
 * @return the number of occurrences of a character 'c' in a given string 's'.
 */

/**
 * Static function `arrays_freedom` frees the memory allocated for a 2D array
 * of characters.
 * 
 * @param ptr ptr is a pointer to a pointer to a character. It represents a
 * dynamically allocated 2D array of characters.
 * @param m The parameter `m` represents the number of elements in the
 * array `ptr`.
 * 
 * @return 0.
 */

/**
 * The function `aux_strslip` takes a string `s` and a character `c`, and
 * splits `s` into substrings based on the delimiter `c`, returning an
 * array of the substrings.
 * 
 * @param auxstrslip A pointer to a pointer to a character array. This is
 * used to store the substrings of the input string.
 * @param s A pointer to a string that needs to be split into substrings.
 * @param c The parameter 'c' is a character that is used as a delimiter
 * to split the string 's' into substrings.
 * @param numofsubstr The parameter `numofsubstr` represents the number
 * of substrings that need to be extracted from the string `s`.
 * 
 * @return a pointer to a character array (char **) called auxstrslip.
 */

/**
 * The function `ft_split` takes a string `s` and a character `c` as input
 * and splits the string into substrings based on the delimiter `c`.
 * 
 * @param s The parameter `s` is a pointer to a constant character string.
 * It represents the input string that needs to be split into substrings based
 * on the delimiter `c`.
 * @param c The parameter 'c' is a character that is used as a delimiter to
 * split the string 's' into substrings.
 * 
 * @return The function `ft_split` is returning a pointer to a pointer of
 * characters (`char **`).
 */