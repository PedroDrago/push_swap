#include "../includes/push_swap.h"

int	check_invalid_characters(char *tab[], int count)
{
	int	count2;

	while (tab[count])
	{
		count2 = 0;
		while (tab[count][count2])
		{
			if ((tab[count][count2] != '-'
				&& tab[count][count2] != '+' )
				&& !ft_isdigit(tab[count][count2]))
				return (FALSE);
			count2++;
		}
		count++;
	}
	return (TRUE);
}

static int	validate_minus(char *tab[], int count, int count2)
{
	if ((count2 != 0 && tab[count][count2 - 1] != ' ')
		|| (!ft_isdigit(tab[count][count2 + 1])))
		return (FALSE);
	return (TRUE);
}

int	check_invalid_minus(char *tab[], int is_argv)
{
	int	count;
	int	count2;

	count = is_argv;
	while (tab[count])
	{
		count2 = 0;
		while (tab[count][count2])
		{
			if (tab[count][count2] == '-' || tab[count][count2] == '+')
				if (!validate_minus(tab, count, count2))
					return (FALSE);
			count2++;
		}
		count++;
	}
	return (TRUE);
}

int	validate_tab(char *tab[], int is_argv)
{
	int	count;

	count = 0;
	if (is_argv)
		count = 1;
	if (!tab[count])
	{
		write(2, "Error\n", 6);
		return (FALSE);
	}
	if (!check_invalid_characters(tab, is_argv))
	{
		write(2, "Error\n", 6);
		return (FALSE);
	}
	if (!check_invalid_minus(tab, is_argv))
	{
		write(2, "Error\n", 6);
		return (FALSE);
	}
	if (!validate_integers(tab, is_argv))
	{
		write(2, "Error\n", 6);
		return (FALSE);
	}
	return (TRUE);
}

int	validate(int argc, char *argv[])
{
	char	**tab;
	int		is_argv;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		is_argv = 0;
	}
	else
	{
		tab = argv;
		is_argv = 1;
	}
	return (validate_tab(tab, is_argv));
}
