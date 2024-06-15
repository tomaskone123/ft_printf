#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int				i;
	unsigned int	a;

	i = -1234;
	a = i;
	// printf("%u\n", -1);
	// printf("%d\n", printf("%x\n", 100));
	// printf("%d\n", ft_printf("Hello %s%i%d %u %c %%\n", "  ", -1234, 5678, 1234,
	// 		'c'));
	printf("%d\n",ft_printf("%X\n", -123456));
	printf("%d\n",printf("%X\n", -123456));

}
