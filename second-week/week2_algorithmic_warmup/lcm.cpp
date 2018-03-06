#include <iostream>

int main(void)
{
    long a,b,d,_a,_b;
    std::cin>>a>>b;
    _a = a;
    _b = b;
    while(true)
    {
        d = a%b;    
        if(!d) break;
        a = b;
        b = d;
    }
    std::cout<< _a * (_b / b) <<std::endl;
    return 0;
}
