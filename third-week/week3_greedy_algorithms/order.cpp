#include <iostream>
using namespace std;

int main(void)
{
    unsigned int n;

    cin >> n;
    
    unsigned long v[n];

    for(unsigned int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    for(unsigned int j=0; j<n-1; j++)
    {
        int changes = 0;
        for(unsigned int i=0; i<n-1; i++)
        {
            if(v[i]<v[i+1])
            {
                unsigned long aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                changes++;
            }
            cout << v[i];
        }
        cout << v[n-1] << endl;
        if(changes <= 1)
        {
            cout << "finished" << endl;
            if(n>3) break;
        }
    }
}
