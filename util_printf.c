#include "ft_printf.h"
#include <unistd.h>

int len(char *d)
{
	int i = 0;
	while(d[i])
		i++;
	return i;
}

int legal_base_check(char *base)
{
	int i, j;
	i = 0;
    
	if (base[0] == '\0' || base[1] == '\0')
        	return (0);
    	while (base[i]) // loops over the base string
    	{
        	j = 0;
        	while (base[j])
        	{
            		if (i!= j && base[i] == base[j])
                	return (0);
            	j++;
        	}
		if (base[i] == '+' || base[i] == '-')
            		return (0);
        	if (base[i] < 32 || base[i] > 126)
            		return (0);
		i++;
	}
	return (1);
}


void	ft_putchar(char c)
{	
	write(1, &c, 1);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	int i;
	int	base_size;
	int	nbr_str[500];
	
	i = 0;
	base_size = 0;
	if (legal_base_check(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[base_size])
			base_size++;
		while (nbr)
		{
			(unsigned long) base_size;
			nbr_str[i] = nbr % base_size;
			nbr = nbr / base_size;
			i++;
		}     
		while (i-- > 0)
            ft_putchar(base[nbr_str[i]]);
	}
}

void ptr(void* p)
{
	char* base =  "0123456789abcdef";
	unsigned long x = (unsigned long) p;
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_base(x,base);
}

//  NEXXT
//char *ft_utoa(unsigned int n);
//char *ft_ultoa_base(unsigned long n, int base);

