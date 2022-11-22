#include <unistd.h>
#include <stdarg.h>

int	ft_putstr(char *stringy)
{
	int	count;

	count = 0;
	while (stringy[count])
		write(1, &stringy[count++], 1);
	return (count);
}

int	ft_putnbr(int nbr)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789";
	if (nbr >= 10)
		count += ft_putnbr(nbr/10);
	return (write(1, &str[nbr%10], 1));
}

int	ft_puthex(unsigned long long nbr)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_puthex(nbr/16);
	return (write(1, &str[nbr%16], 1));
}

int ft_printf(const char *stringy, ... )
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, stringy);
	while (stringy[i])
	{
		if (stringy[i] == '%')
		{
			i++;
			if (stringy[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (stringy[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if (stringy[i] == 'x')
				count += ft_puthex(va_arg(args, unsigned int));
		}
		else
			count += write(1, &stringy[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	// ft_printf("Hello %s\n", "toto");
// 	// ft_printf("Magic %s is %d", "number", 42);
// 	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// 	return 0;
// }
