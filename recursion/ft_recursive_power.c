#include <stdio.h>

int     ft_recursive_power(int x, int lambda)
{
    if (lambda == 0)
        return 1;
    
    int half_power = ft_recursive_power(x, lambda / 2);
    if(lambda % 2 == 0)
    {
        return (half_power * half_power);
    }
    else 
        return (half_power * half_power * x);
    

}
int main(void)
{
    int x = 2, n = 5;
    printf("%d^%d = %d\n",x,n, ft_recursive_power(x,n));
    return (0);
}