#ifdef FT_PRINTF_H
#define FT_PRINTF_H


#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void ft_putchar(char c);
void ft_putstr(char *s);
size_t ft_strlen(const char *s);
char *ft_itoa(int n);
void ptr(void* p);
int ft_printf(const char format,...);


#endif
