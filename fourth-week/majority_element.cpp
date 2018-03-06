#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int check_majority_in_array(long majority_left, vector<long>& a)
{
    int n = a.size();
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == majority_left)
            count++;
    }
    if(count > n/2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

long divide(vector<long>& a)
{
    int n = a.size();
    int size_left = n/2;
    int size_right = n - size_left;
    long majority_left = -1;
    long majority_right = -1;
    int majority_detected;

    if(size_left>2)
    {
        vector<long> left(size_left);
        for(int i=0;i<size_left;i++)
        {
            left[i]=a[i];
        }

        majority_left = divide(left);
        
        if(majority_left != -1)
        {
            majority_detected = check_majority_in_array(majority_left, a);
            if(majority_detected)
            {
                return majority_left;
            }
            else
            {
                vector<long> right(size_right);
                for(int i=size_left;i<n;i++)
                {
                    right[i-size_left]=a[i];
                }
                return divide(right);
            }
        }
        else
        {
            vector<long> right(size_right);
            for(int i=size_left;i<n;i++)
            {
                right[i-size_left]=a[i];
            }
            return divide(right);
        }
    }
    else if(size_left == 1)
    {
        majority_left = a[0]; 
    }
    else if(size_left == 2)
    {
        if(a[0] == a[1])
        {
            majority_left = a[0]; 
        }
        else
        {
            if(size_right < 3)
            {
                if(a[size_left] == a[size_left+1])
                {
                     majority_right = a[size_left]; 
                     majority_detected = check_majority_in_array(majority_right, a);
                     if(majority_detected)
                     {
                         return majority_right;
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
            else
            {
                vector<long> right(size_right);
                for(int i=size_left;i<n;i++)
                {
                    right[i-size_left]=a[i];
                }
                return divide(right);
            }

        }
    }
    else
    {
        return a[0];
    }

    if(majority_left != -1)
    {
        majority_detected = check_majority_in_array(majority_left, a);
        if(majority_detected)
        {
            return majority_left;
        }
        else if(size_right > 1)
        {
            if(size_right < 3)
            {
                if(a[size_left] == a[size_left+1])
                {
                     majority_right = a[size_left]; 
                     majority_detected = check_majority_in_array(majority_right, a);
                     if(majority_detected)
                     {
                         return majority_right;
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
            else
            {
                vector<long> right(size_right);
                for(int i=size_left;i<n;i++)
                {
                    right[i-size_left]=a[i];
                }
                return divide(right);
            }
        }
        else
            return -1;
    }
}

int main(void)
{
    int n;
    cin >> n;
    vector<long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    long majority = divide(a);
    if(majority == -1)
        cout << 0 << endl;
    else
        cout << 1 << endl;

}
