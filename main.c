#include "ft_printf.h"
#include <limits.h>

int main()
{
    int ret = 0;

    ret = ft_printf("%-5.1s\n", "Hello");
    printf("%d\n", ret);
    ret = printf("%-5.1s\n", "Hello");
    printf("%d\n", ret);

    return (0);
}