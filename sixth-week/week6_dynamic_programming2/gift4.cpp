#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int dp(int k, int i, int j)
{
    if(k<0 || i<0 || j<0) return 0;
    cout << "Using " << k << " numbers to get ";
    cout << i << " and " << j << endl;

    for(int m=0;m<k;m++)
        cout << arr[m] << " ";
    cout << endl;
    

    return ( dp(k-1,i-arr[k-1],j) | 
             dp(k-1,i,j-arr[k-1]) | 
             dp(k-1,i,j) );
}

int main(void)
{
    int n;
    cin >> n;

    
    int sum = 0;
    for(int i=0;i<n;i++)
    {
         int v;
         cin >> v;
         arr.push_back(v);
         sum += v;
    }
    
    if(sum%3 != 0)
    {
        cout << "no es posible" << endl;
        cout << 0 << endl;
    }
    else 
    {
        cout << dp(n,sum/3,sum/3) << endl;
    }
    return 0;
}

