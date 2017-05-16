#include "libft.h"

int		find_in_arr(int *arr, int arr_len, int val)
{
	int i;

	i = -1;
	while (++i < arr_len)
		if (arr[i] == val)
			return (i);
	return (-1);
}