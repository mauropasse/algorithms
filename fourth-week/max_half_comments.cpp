#include <iostream>
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
        {
            count++;
        }
    }
    if(count > n/2)
    {
        cout << "Element " << element << " is majority" << endl;
        return 1;
    }
    cout << "Element " << element << " is NOT majority" << endl;
    return 0;
}

long divide(const vector<long>& a)
{
    int n = a.size();
    
    cout << "Array:" << endl;
    for (int i=0;i<n;i++) 
    {
       cout << a[i] << " ";
    }
    cout << endl;

    if(n/2 > 1) 
    {
        cout << "Big array, divide" << endl;
        vector<long> l(n/2);
        for(int i=0;i<n/2;i++)
        {
            l[i]=a[i];
        }
        long pos_maj = divide(l); 
        cout << endl;
        
        
        cout << "En pos_maj esta el left majority: " << pos_maj << endl;
        if(pos_maj != -1)
        {
            cout << "Left maj present, full check now"  << endl;
            long is_maj = get_maj_in_array(pos_maj,a); 
            if(is_maj)
            {
                return pos_maj;
            }
            else
            {
                cout << "Check the RIGHT side now" << endl;
                vector<long> r(n-n/2);
                for(int i=n/2;i<n;i++)
                {
                    r[i-n/2]=a[i];
                }
                long pos_rmaj = divide(r); 
                cout << "In pos_rmaj is the right maj: " << pos_rmaj << endl;
                if(pos_rmaj != -1)
                {
                    cout << "Was majority in right side" << endl;
                    cout << "Check maj in whole array" << endl;
                    long is_rmaj = get_maj_in_array(pos_rmaj,a); 
                    if(is_rmaj)
                    {
                        return pos_rmaj;
                    }
                    else
                    {
                        cout << "Wasn't majority neither in right side" << endl;
                        return -1;
                    }
                }
                else
                {
                    cout << "Wasn't majority neither in right side" << endl;
                    return -1;
                }

            }
        }
        else
        {
            cout << "NOT left maj present"  << endl;
            cout << "Check the RIGHT side now" << endl;
            vector<long> r(n-n/2);
            for(int i=n/2;i<n;i++)
            {
                r[i-n/2]=a[i];
            }
            long pos_rmaj = divide(r); 
            cout << "In pos_rmaj is the right maj: " << pos_rmaj << endl;
            if(pos_rmaj != -1)
            {
                cout << "Was majority in right side" << endl;
                cout << "Check maj in whole array" << endl;
                long is_rmaj = get_maj_in_array(pos_rmaj,a); 
                if(is_rmaj)
                {
                    return pos_rmaj;
                }
                else
                {
                    cout << "Wasn't majority neither in right side" << endl;
                    return -1;
                }
            }
            else
            {
                cout << "Wasn't majority neither in right side" << endl;
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
        cout << "Check the right side now" << endl;
        if(n==2)    
        {
            cout << "We dont check, right side is only 1 element" << endl;
            return -1;
        }
        else
        {
            cout << "Are elements in right side equal? ";
            if(a[1]==a[2])
            {
                cout << "Yes!!" << endl;
                return a[1];
            }
            else
            {
                cout << "No!!" << endl;
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
       m[i] = a[i];
    }
    cout << endl;
    //order(m);
    //long greedy_answer = get_max(m);
    long divide_answer = divide(a);

    //cout << "greedy_answer "<< greedy_answer << endl;
    cout << "divide_answer "<< divide_answer << endl;

//    if(greedy_answer != divide_answer)
//    {
//        cout << "Error!!!!" << endl;
//        for (int i=0;i<n;i++) 
//        {
//           cout << a[i] << " ";
//        }
//        cout << endl;
//    }

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


