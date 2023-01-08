#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putstr(char  *stringy)
{
	int count = 0;
	while (stringy[count])
		write(1, &stringy[count++], 1);
	return count;
}

int ft_printnbr(int num)
{
	int count = 0;
	char *str = "0123456789";
	if (num > 10)
		count += ft_printnbr(num / 10);
	return (count + write(1, &str[num%10], 1));
}

int ft_putnbr(int num)
{
	int count = 0; 
	int sign = 1; 
	if (num < 0)
	{
		sign = -1;
		count += write(1, "-", 1);
		if (num == -2147483648)
			return (count + write(1, "2147483648", 10));
	}
	return (count += ft_printnbr(sign * num));
}

int ft_puthex(unsigned long long hex_thingy)
{
	int count = 0;
	char *str = "0123456789abcdef";
	if (hex_thingy > 16)
		count += ft_puthex(hex_thingy / 16);
	return (count + write(1, &str[hex_thingy%16], 1));
}

int ft_printf(const char *stringy, ... )
{
	va_list	args;
	int	i = 0;
	int	count = 0;

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
				count += ft_puthex(va_arg(args, unsigned long long));
		}
		else
			count += write(1, &stringy[i], 1);
		i++;
	}
	return count;
	va_end(args);
}

int main(int argc, char const *argv[])
{
	int count = 0; 
	int county = 0; 
	// count = printf("%d\n", -2147483649);
	// county = ft_printf("%d\n", -2147483649);
	count = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("count: %d\n", count);
	county = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("county: %d\n", county);

	return 0;
}
