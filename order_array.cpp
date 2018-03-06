#include <iostream>
#include <vector>
using namespace std;

void order(vector<long>& a)
{
    int n = a.size();
    for (int i=0;i<n-1;i++) 
    {
        for (int j=0;j<n-1;j++) 
        {
            if(a[j]<a[j+1])
            {
                long aux = a[j];
                a[j]=a[j+1];
                a[j+1]=aux;
            }
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<long> a(n); 

    for (int i=0;i<n;i++) 
    {
       cin >> a[i];
    }

    cout << endl;
    order(a);

    for (int i=0;i<n;i++) 
    {
       cout << a[i];
       cout << " ";
    }
    cout << endl;
    return 0;
}
