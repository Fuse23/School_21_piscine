#include "ft_rash.h"

int main(void)
{
    int     i;
    t_dict  *dict;

    i = 0;
    dict = malloc(sizeof(t_dict*) * 8);
    dict[0].key = "3";
    dict[0].value = "three";
    dict[1].key = "6";
    dict[1].value = "six";
    dict[2].key = "30";
    dict[2].value = "thirty";
    dict[3].key = "100";
    dict[3].value = "hundred";
    dict[4].key = "1000";
    dict[4].value = "thousand";
    dict[5].key = "1000000";
    dict[5].value = "million";
    dict[6].key = "10";
    dict[6].value = "ten";
    dict[7].key = "1000000000";
    dict[7].value = "billion";
    ft_to_letters(dict, "333333333333");
    free(dict);
    write(1, "\n", 1);
    return (0);
}
