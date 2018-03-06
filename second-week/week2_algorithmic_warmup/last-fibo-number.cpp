#include <iostream>

int get_fibo_number(long number)
{
   if(number == 0)      return 0;
   else if(number == 1) return 1;
   else
   {
       int a[3];
       a[0]=0;
       a[1]=1;

       //std::cout << "i=" << 0 << ". i%3=" << 0 << ". Fibo= " << a[0] << std::endl;
       //std::cout << "i=" << 1 << ". i%3=" << 1 << ". Fibo= " << a[1] << std::endl;

       for(long i=2;i<=number;i++)
       {
           a[i%3]=(a[(i+1)%3]+a[(i+2)%3])%10;
           //std::cout << "i=" << i << ". i%3=" << i%3 << ". Fibo= " << a[i%3] << std::endl;
       }
       return a[number%3];
   }
}

int main(void)
{
    long number;
    int fibo_number;
    std::cin >> number;
    std::cout << get_fibo_number(number) << std::endl;
    return 0;
}

