#include <stdio.h>
#include <stdarg.h>
#include<stdlib.h>
#include <unistd.h>
#include "libtf.h"  //a local library 



int check(char format, va_list ap)
{
        int i = 0;
        if (format =='c')
        {
                char c = (char) va_arg(ap,int);
                write(1,&c,1);
        }
        if (format == 's')
        {
                char* c =(char*) va_arg(ap,int);
                ft_putstr_fd(c,1);
        }
        if(format =='d')
        {
                int c = va_arg(ap,int);
                ft_putnbr_fd(c,1);
        }
        return 0;
}

int ft_printf(const char *format ,...)
{
        va_list ap;
        va_start(ap,format);
        int i= 0;
        while(format[i])
        {
                if(format[i] == '%')
                {
                        i++;
                        check(format[i],ap);
                }
                else
                        write(1,&format[i],1);
                i++;
        }
        return i;
}

