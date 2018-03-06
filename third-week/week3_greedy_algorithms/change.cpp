#include <iostream>

int main(void)
{
    int m;
    std::cin >> m;
    int coins = (m/10) + (m%10)/5 + m%5;
    std::cout << coins << std::endl;
}
