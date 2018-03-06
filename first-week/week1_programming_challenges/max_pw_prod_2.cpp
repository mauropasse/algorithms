#include <iostream>

int main(void)
{
    unsigned long n;
    std::cin >> n;

    unsigned long a[n];
    unsigned long first_max = 0;
    unsigned long index = 0;
    unsigned long second_max = 0;

    for(unsigned long i=0;i<n;i++)
    {
        std::cin >> a[i];
        if(a[i] > first_max)
        {
            index = i;
            first_max = a[i];
        }
    }

    for(unsigned long i=0;i<n;i++)
    {
        if(a[i] > second_max && i != index)
        {
            second_max = a[i];
        }
    }

    std::cout << second_max * first_max << std::endl;
    return 0;       
}
