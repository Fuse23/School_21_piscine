#include "ft_rash.h"

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		str++;
	}
	write(1, " ", 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*find_key(t_dict *dict, char digit, int len)
{
	while (dict)
	{
		if ((dict->key[0] - digit == 0) && ft_strlen(dict->key) == len)
			return (dict->value);
		dict++;
	}
	return (NULL);
}

char    *find_key_2(t_dict *dict, char digit)
{
    while (dict)
    {
        if (ft_strlen(dict->key) == 2)
            if (dict->key[1] - digit == 0 && dict->key[0] == '1')
                return (dict->value);
        dict++;
    }
    return (NULL);
}

char    *ft_creat_number(int size, char *num)
{
    int i;
    int j;
    char    *number;
    i = 0;
    number = malloc(size);
    while (i < size - 1)
    {
        number[i] = '0';
        i++;
    }
    number[size - 1] = '\0';
    j = i - ft_strlen(num);
    i = 0;
    while (num[i] != '\0')
    {
        number[j] = num[i];
        i++;
        j++;
    }
    return (number);
}

void    ft_strncat(char *dest[1], char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (dest[0][len] != '\0')
		len++;
	while (src[i] != '\0' && i < nb)
	{
		dest[0][len + i] = src[i];
		i++;
	}
	dest[0][len + i] = '\0';
}

int no_null(char *number, int index)
{
    int i;

    i = index - 3;
    while (number[i] != '\0' && i <= index + 3)
    {
        if (number[i] != '0')
            return (1);
        i++;
    }
    return (0);
}

void ft_to_letters(t_dict *dict, char *num)
{
    int three;
    int size;
    char    *trip;
    char    *number;
    int     t;

    size = ft_strlen(num);
    three = size / 3;
    trip = malloc(4);
    if (size % 3 == 2)
    {
        trip[0] = '0';
        ft_strncat(&trip, num, 2);
        size++;
        three++;
    }
    else if (size % 3 == 1)
    {
        trip[0] = '0';
        trip[1] = '0';
        ft_strncat(&trip, num, 1);
        size += 2;
        three++;
    }
    else
        ft_strncat(&trip, num, 3);
    trip[3]= '\0';
    number = ft_creat_number(size + 1, num);
    while (three > 0)
    {
        t = 0;
        if (trip[0] != '0')
        {
            ft_print(find_key(dict, trip[0], 1));
            ft_print(find_key(dict, '1', 3));
        }
        if (trip[1] != '0')
        {
            if (trip[1] == '1')
            {
                t = 1;
                ft_print(find_key_2(dict, trip[2]));
            }
            else
                ft_print(find_key(dict, trip[1], 2));
        }
        if (trip[2] != '0' && t != 1)
            ft_print(find_key(dict, trip[2], 1));
        if (three > 1 && no_null(number, size - ((three - 1) * 3)))
            ft_print(find_key(dict, '1', (3 * (three - 1) + 1)));
        if (three > 1)
        {
            trip[0] = number[size - ((three - 1) * 3)];
            trip[1] = number[size  - ((three - 1) * 3) + 1];
            trip[2] = number[size - ((three - 1) * 3) + 2];
        }
        three--;
    }
    free(trip);
    free(number);
}
