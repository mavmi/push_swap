#include "input_handler.h"

static int	is_number(char *str)
{
	if (((*str == '-' || *str == '+') && ft_strlen(str) > 1)
		|| ft_isdigit(*str))
		str++;
	else
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static int	find_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

static t_stack	*nums_to_stack(int *arr, int size)
{
	int		iter;
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (NULL);
	iter = size - 1;
	while (iter >= 0)
		if (push_front(stack, arr[iter--]))
			exit_with_error(arr);
	free(arr);
	return (stack);
}

static int	is_int(char *num_str, char *input)
{
	size_t	padding_1;
	size_t	padding_2;
	int		return_value;

	if (!num_str)
		return (1);
	padding_1 = 0;
	padding_2 = 0;
	if (*num_str == '-' && *input == '-')
	{
		padding_1++;
		padding_2++;
	}
	if (*input == '+')
		padding_2++;
	while (*(num_str + padding_1) == '0')
		padding_1++;
	while (*(input + padding_2) == '0')
		padding_2++;
	return_value = ft_strncmp(num_str + padding_1, input + padding_2,
			ft_strlen(input) - padding_2);
	free(num_str);
	return (return_value);
}

t_stack	*input_handler(int argc, char **argv)
{
	int		args_iter;
	int		nums_iter;
	int		*nums;

	args_iter = argc - 1;
	nums_iter = argc - 2;
	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (!nums)
		exit_with_error(0);
	while (args_iter > 0)
	{
		if (!is_number(argv[args_iter]))
			exit_with_error(nums);
		nums[nums_iter] = ft_atoi(argv[args_iter]);
		if (is_int(ft_itoa(nums[nums_iter]), argv[args_iter]))
			exit_with_error(nums);
		args_iter--;
		nums_iter--;
	}
	if (find_duplicates(nums, argc - 1))
		exit_with_error(nums);
	return (nums_to_stack(nums, argc - 1));
}
