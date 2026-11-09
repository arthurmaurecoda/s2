#include <stdio.h>

void print_str(char *str)
{
    printf("%s\n", str);
}
int main(void)
{
    print_str("hello");
    return 0;
}