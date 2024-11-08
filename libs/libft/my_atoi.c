
int	my_atoi(const char *nptr)
{
	int	sign;
	int	n;
	int	i;

	sign = 1;
	n = 0;
	i = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	const char	n[] = "4638";

	printf("Minha própria atoi(): %i \n", my_atoi(n));
	printf("Função atoi() original: %i \n", atoi(n));
	return (0);
}*/
