int	main(int argc, char **argv)
{
	int word_cnt = 0;
	int i = 0;
	long *arr;
	char *str;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = (argv[1]);
		arr = str_to_numbers(str);
		if (arr == 0)
		{
			free(arr);
			ft_error();
		}
		word_cnt = word_count(str);
		ft_printf("%p\n", arr);
	}
	if (argc > 2)
	{
		str = words_to_str(argc, argv);
		arr = str_to_numbers(str);
		if (arr == 0 || str == 0)
		{
			free(str);
			free(arr);
			ft_error();
		}
		word_cnt = word_count(str);
	}
	while (i < word_cnt)
	{
		ft_printf("%d\n", arr[i++]);
	}
	free(str);
	free(arr);
}