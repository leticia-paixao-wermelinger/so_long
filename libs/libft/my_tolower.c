
int	my_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(int argc, char *argv[])
{

	char	ca;
	char	co;
	char	carg;

	if (argc != 2)
	{
		printf("Favor digitar apenas uma letra minúscula \n");
		return (0);
	}
	int	i = 0;
	while (argv[1][i])
		i++;
	if (i > 1)
	{
		printf("Favor digitar apenas uma letra minúscula \n");
		return (0);
	}
	int	a;
	int	original;

	a = my_tolower(argv[1][0]);
	ca = (char)a;
	carg = (char)argv[1][0];
	original = tolower(argv[1][0]);
	co = (char)original;
	printf("O caractere digitado foi %i (ou seja, %c) e, com a minha toupper, \
			ele ficou %i (ou seja, %c) \n", argv[1][0], carg, a, ca);
	printf("O caractere digitado foi %i (ou seja, %c) e, com a minha toupper, \
			ele ficou %i (ou seja, %c) \n", argv[1][0], carg, a, co);
	return (0);
}*/
