#include <iostream>

int main(void)
{
    unsigned long n;
    std::cin >> n;

    unsigned long a[n];
    for(unsigned long i=0;i<n;i++)
    {
        std::cin >> a[i];
    }
    
    unsigned long max_pw_pr = 0;
    unsigned long idx = n-1;

    for(unsigned long j=0; j< n; j++)
    {
        for(unsigned long i=0; i<idx; i++)
        {
            max_pw_pr = (max_pw_pr < (a[idx]*a[i])) ? a[idx]*a[i] : max_pw_pr;
        }
        idx--;
    }

    std::cout << max_pw_pr << std::endl;
    return 0;       

}
