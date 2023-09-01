#include <stdio.h>

int add_ints(int a, int b);
int main(void)
{
    int x, y;
    x = 5;
    y = 6;
    int sum = add_ints(x, y);
    printf("%i,", sum);

}

int add_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}