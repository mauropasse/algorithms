#include <iostream>

long get_period(long number, long mod)
{
   if(number == 0)      return 0;
   else if(number == 1) return 1;
   else
   {
       long long a[3];
       a[0]=0;
       a[1]=1;
        
       long t=1;
       long period=1;

       std::cout << "f: " << a[0%3] << ". Mod: " << a[0%3]%mod << std::endl;
       std::cout << "f: " << a[1%3] << ". Mod: " << a[1%3]%mod << std::endl;

       for(long i=2;i!=0;i++)
       {
           a[i%3]=a[(i+1)%3]+a[(i+2)%3];
           std::cout << "f: " << a[i%3] << ". Mod: " << a[i%3]%mod << std::endl;
           if(t==0 && (a[i%3]%mod)==1) 
               break;
           else
               period++;

           t = a[i%3]%mod;
       }
       std::cout << std::endl;
       std::cout << "period: " << period << std::endl;
       return period;
   }
}

long get_fibo_number(long number, long period, long mod) 
{
   if(number == 0)      return 0;
   else if(number == 1) return 1;
   else
   {
       number = number % period;
       unsigned long long a[3];
       a[0]=0;
       a[1]=1;
        
       for(unsigned long i=2;i<=number;i++)
       {
           a[i%3]=a[(i+1)%3]+a[(i+2)%3];
           std::cout << a[i%3]%mod << " ";
       }
       std::cout << "answer: " << a[number%3]%mod << std::endl;
       return a[number%3];
   }
}

int main(void)
{
    unsigned long number,mod;
    unsigned long fibo_number;
    std::cin >> number;
    std::cin >> mod;
    unsigned long period = get_period(number,mod);
    get_fibo_number(number,period,mod);
    return 0;
}

