#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

void order(vector<long>& v)
{
    int n = v.size();
    for(int j=0; j<n-1; j++)
    {
        for(int i=0; i<n-1; i++)
        {
            if(v[i]<v[i+1])
            {
                long aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
            //cout << v[i];
        }
        //cout << v[n-1] << endl;
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<long> a(n);
    vector<long> b(n);

    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }

    for(int i=0;i<n;++i)
    {
        cin >> b[i];
    }

    order(a);
    order(b);
    
    long sumatoria = 0;

    for(int i=0;i<n;i++)
    {
        sumatoria += a[i] * b[i];
    }
    cout << sumatoria << "\n";
}
