#include <iostream>
using namespace std;

void order(long* v, int n)
{
    for(unsigned int j=0; j<n-1; j++)
    {
        int changes = 0;
        for(unsigned int i=0; i<n-1; i++)
        {
            if(v[i]<v[i+1])
            {
                long aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                changes++;
            }
            //cout << v[i];
        }
        //cout << v[n-1] << endl;
        if(changes <= 1)
        {
            //cout << "finished" << endl;
            if(n>3) break;
        }
    }
}

int main(void)
{
    int n;
    //cin >> n;
    n = 1000;
    long a[n],b[n];

    for(int i=0;i<n;i++)
    {
        //cin >> a[i];
        a[i] = 100000;
        b[i] = -100000;
    }

    //for(int i=0;i<n;i++)
    //{
    //    cin >> b[i];
    //}

    //order(a,n);
    //order(b,n);
    
    long long sumatoria = 0;

    for(int i=0;i<n;i++)
    {
        sumatoria += a[i]*b[i];
        cout << sumatoria << endl;
    }
    //cout << sumatoria << endl;
}
