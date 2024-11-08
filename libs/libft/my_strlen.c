
#include "libft.h" 

size_t	my_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
/*
int	main(int argc, char *argv[])
{
	#include <string.h>

//	char	string[] = "ABACAXI GELADO";
	long unsigned int	count_returned;

	if (argc != 2)
	{
		printf("Favor digitar apenas um argumento");
	}
	count_returned = my_strlen(argv[1]);
	printf("Minha função: %li\n", count_returned);
	printf("Função Original: %li\n", strlen(argv[1]));
	return (0);
}*/
