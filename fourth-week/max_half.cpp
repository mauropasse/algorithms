#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void order(vector<long>& a);
long get_max(const vector<long>& a);

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
    while(true)
    {
        n = rand() % 10 + 1;
        cout << "n: " << n << endl;
        vector<long> a(n); 
        vector<long> m(n); 

        for (int i=0;i<n;i++) 
        {
           a[i]=rand()%10;
        }

        for (int i=0;i<n;i++) 
        {
           m[i] = a[i];
        }
        order(m);
        long divide_answer = divide(a);
        cout << "divide_answer "<< divide_answer << endl;
        long greedy_answer = get_max(m);
        cout << "greedy_answer "<< greedy_answer << endl;


        if(greedy_answer != divide_answer)
        {
            cout << "Error!!!!" << endl;
            for (int i=0;i<n;i++) 
            {
               cout << a[i] << " ";
            }
            cout << endl;
            break;
        }
    }
    return 0;
}

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

long get_max(const vector<long>& a)
{
    int n = a.size();
    int count = 1;
    int max_count = 1;
    int index = 0;
    for (int i=0;i<n-1;i++) 
    {
        if(a[i]==a[i+1])
        {
            count++;
            if(count > max_count)
            {
                max_count = count;
                index=i;
            }
        }
        else
        {
            count = 1;
        }
    }
    
    if(max_count > n/2)
    {
        return a[index];
    }
    return -1;
}


