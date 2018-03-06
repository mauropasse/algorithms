#include <iostream>
using namespace std;

int main(void)
{
    long n;
    cin >> n;
    
    long min_step[n+1];
    min_step[0]=0;
    min_step[1]=0;
    for(long i=2;i<n+1;i++)
    {
        min_step[i] = min_step[i-1]+1;
        if(i%2 == 0) min_step[i] = min(min_step[i/2]+1,min_step[i]);
        if(i%3 == 0) min_step[i] = min(min_step[i/3]+1,min_step[i]);
    }
    
    cout << min_step[n] << endl;

    long result[min_step[n]];
    long j=0;
    result[j++]=n;
    for(long i=n;i>1;)
    {
        if((i%3 == 0) && (min_step[i] == min_step[i/3]+1))
            i=i/3; 
        else if((i%2 == 0) && (min_step[i] == min_step[i/2]+1))
            i=i/2; 
        else
            i=i-1; 

        result[j++]=i; 
    }
    for(int i=--j;i>=0;i--)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
}

