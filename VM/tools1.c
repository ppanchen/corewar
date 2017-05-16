#include "vm.h"

int		find_pc_in_arr(int *arr, int val)
{
	int i;

	i = -1;
	if (!arr)
		return (-1);
	while (arr[++i] != -1)
		if (arr[i] == val)
			return (i);
	return (-1);
}