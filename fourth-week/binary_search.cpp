#include <iostream>
#include <vector>

int find_index(std::vector<long>& a, int b, int l, int r)
{
    int m = (l + r) / 2; 

    if(a[m] == b)
        return m;
    else if(a[m] < b)
        l = m+1;
    else
        r = m-1; 

    if(l > r)
        return -1;
    else
        return find_index(a,b,l,r);
}

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<long> a(n);
    for(int i=0;i<n;i++)
    {
        std::cin >> a[i];
    } 

    int k;
    std::cin >> k;
    std::vector<long> b(k);
    for(int i=0;i<k;i++)
    {
        std::cin >> b[i];
    } 
    
    for(int i=0;i<k;i++)
    {
        int index = find_index(a,b[i], 0, n-1);      
        std::cout << index << " ";
    }
}
