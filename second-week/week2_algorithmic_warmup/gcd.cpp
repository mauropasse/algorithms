#include <iostream>

int main(void)
{
    long a,b,d;
    std::cin>>a>>b;
    while(true)
    {
        d = a%b;    
        if(!d) break;
        a = b;
        b = d;
    }
    std::cout<<b<<std::endl;
    return 0;
}
