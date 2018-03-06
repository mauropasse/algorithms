#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//void show(vector<long>& a)
//{
//    int n=a.size();
//    for(int i=0;i<n;i++)
//    {
//        cout << a[i] << ' ';
//    }
//    cout << endl;
//}

void partition3(vector<long>& a, int l, int r,int& m1, int& m2)
{
    long x=a[l];
    m1=l; 
    m2=r; 
     
    if (r-l <= 1)
    {
        if (a[r] < a[l])
            swap(a[r], a[l]);
        return;
    }

    for(int i=l+1;i<=m2;)
    {
        if (a[i]<x)
        {
            swap(a[m1], a[i]);
            m1++;
            i++;
        }
        else if (a[i]==x)
        {
            i++;
        }
        else if (a[i]>x)
        {
            swap(a[i], a[m2]);
            m2--;
        }
    }
}

void sort(vector<long>& a,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    
    int k = l + rand() % (r - l + 1);
    swap(a[l],a[k]);

    int m1,m2; 
    partition3(a,l,r,m1,m2);
    
    sort(a,l,m1-1);
    sort(a,m2+1,r);
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
    sort(a,0,n-1);
    //show(a);
    return 0;
}

