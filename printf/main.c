#include "ft_printf.h"
#include <limits.h>

int main()
{
    int ret = 0;

//  ("%.20d", INT_MAX + 1)
//  ("%.20d", INT_MIN)


    ret = ft_printf("%.20d\n", INT_MAX + 1);
    printf("%d\n", ret);


    ret = printf("%.20d\n", INT_MAX + 1);
    printf("%d\n", ret);

    return (0);
}