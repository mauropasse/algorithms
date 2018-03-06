#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

long get_maj_in_array(long element, const vector<long>& a)
{
    int n = a.size();
    int count = 0;
    for (int i=0;i<n;i++) 
    {
        if(a[i] == element)
            count++;
    }
    if(count > n/2)
        return 1;
    else
        return 0;
}

long divide(const vector<long>& a)
{
    int n = a.size();
    
    if(n/2 > 1) 
    {
        vector<long> l(n/2);
        for(int i=0;i<n/2;i++)
        {
            l[i]=a[i];
        }
        long pos_maj = divide(l); 
        
        if(pos_maj != -1)
        {
            long is_maj = get_maj_in_array(pos_maj,a); 
            if(is_maj)
            {
                return pos_maj;
            }
            else
            {
                vector<long> r(n-n/2);
                for(int i=n/2;i<n;i++)
                {
                    r[i-n/2]=a[i];
                }
                long pos_rmaj = divide(r); 
                if(pos_rmaj != -1)
                {
                    long is_rmaj = get_maj_in_array(pos_rmaj,a); 
                    if(is_rmaj)
                    {
                        return pos_rmaj;
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }

            }
        }
        else
        {
            vector<long> r(n-n/2);
            for(int i=n/2;i<n;i++)
            {
                r[i-n/2]=a[i];
            }
            long pos_rmaj = divide(r); 
            if(pos_rmaj != -1)
            {
                long is_rmaj = get_maj_in_array(pos_rmaj,a); 
                if(is_rmaj)
                {
                    return pos_rmaj;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                return -1;
            }
        }
    }
    
    long is_maj = get_maj_in_array(a[0],a); 
    if(is_maj)
    {
        return a[0];
    }
    else
    {
        if(n==2)    
        {
            return -1;
        }
        else
        {
            if(a[1]==a[2])
            {
                return a[1];
            }
            else
            {
                return -1;
            }
        }
    }
}


int main(void)
{
    int n;
    cin >> n;
    vector<long> a(n); 
    vector<long> m(n); 

    for (int i=0;i<n;i++) 
    {
       cin >> a[i];
    }

    long divide_answer = divide(a);
    if(divide_answer == -1)
        cout << 0;
    else
        cout << 1;
    return 0;
}

