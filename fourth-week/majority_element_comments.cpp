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
        cout << "Existing majority in whole array: " << count << endl;
        cout << "n/2 = " << n/2 << "<" << count << " = count " << endl;
        return 1;
    }
    else
    {
        cout << "Existing majority but not in whole array: " << count << endl;
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

    cout << endl;
    cout << "* * * * Left part of array analized: * * * * *" << endl;
    for(int i=0;i<size_left;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "* * * * Right part of array analized: * * * * *" << endl;
    for(int i=size_left;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Is size left = " << size_left << " > 2??" << endl;
    if(size_left>2)
    {
        cout << "Yes, lets divide again: " << endl;

        vector<long> left(size_left);
        for(int i=0;i<size_left;i++)
        {
            left[i]=a[i];
            cout << left[i] << " ";
        }
        cout << endl;

        majority_left = divide(left);

        cout << "MAYORITY LEFT: " << majority_left << endl;
        
        if(majority_left != -1)
        {
            cout << "Mayority left finded: " << majority_left << endl;
            cout << "Look in the whole array now " << endl;
            majority_detected = check_majority_in_array(majority_left, a);
            if(majority_detected)
            {
                return majority_left;
            }
            else
            {
                cout << "Mayority left finded but not whole, but RIGHT??? " << endl;
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
            cout << "Mayority left not finded, but RIGHT??? " << endl;
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
        cout << "No, size is 1. Mayority element: " << a[0]<< endl;
        majority_left = a[0]; 
    }
    else if(size_left == 2)
    {
        cout << "No, size is 2,";
        if(a[0] == a[1])
        {
            cout << " and elements are equals = " << a[0] << endl;
            majority_left = a[0]; 
        }
        else
        {
            cout << " and elements are different" <<  endl;
            cout << "Looooking for majority in right. " << endl;
            if(size_right < 3)
            {
                if(a[size_left] == a[size_left+1])
                {
                     majority_right = a[size_left]; 
                     cout << "Existing majority in right: " <<majority_right << endl;
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
                     cout << "Elements in right not equals " << endl;
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
        cout << "No, size is 0. Mayority element: " << a[0] << endl;
        return a[0];
    }

    if(majority_left != -1)
    {
        cout << "Existing majority in left: " << majority_left << endl;
        majority_detected = check_majority_in_array(majority_left, a);
        if(majority_detected)
        {
            return majority_left;
        }
        else if(size_right > 1)
        {
            cout << "Looking for majority in right. " << endl;
            cout << "Size right:  " << size_right;
            if(size_right < 3)
            {
                cout << " < 3" << endl;
                cout << "Comparing " <<  a[size_left] << " and " << a[size_left+1] << endl;
                if(a[size_left] == a[size_left+1])
                {
                     majority_right = a[size_left]; 
                     cout << "Existing majority in right: " <<majority_right << endl;
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
                     cout << "Elements in right not equals " << endl;
                     return -1;
                }
            }
            else
            {
                cout << " = 3" << endl;
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
    cout << "The majority element is: " << majority << endl;
}
