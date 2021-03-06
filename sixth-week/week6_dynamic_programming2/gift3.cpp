#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    long n;
    cin >> n;

    vector<long> w;

    w.push_back(0);
    
    for(long i=0;i<n;i++)
    {
         long v;
         cin >> v;
         w.push_back(v);
    }

    long W =0;
    for(long i=0;i<=n;i++)
        W += w[i];

    if (W%3 == 0)
    {
        W = W/3;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }
    
    vector<vector<long> > value;
    value.resize(W+1);
    for(long w=0;w<=W;w++)
        value[w].resize(n+1);

    for(long w=0;w<=W;w++)
        value[w][0] = 0;
    for(long j=0;j<=n;j++)
        value[0][j] = 0;

    long count = 0;
    while(true)
    {
        count++;

        for(long i=1;i<=n;i++)
        {
            for(long j=1;j<=W;j++)
            {
                value[j][i] = value[j][i-1];
                if (w[i]<=j)
                {
                    long val = value[j - w[i]][i-1] + w[i];
                    value[j][i] = max(value[j][i],val);
                }
            }
        }

        long i = n;
        for(long j=W;i>0;i--)
        {
            if(j<w[i]) continue;
            long pre_val = value[j-w[i]][i-1]; 
            if(value[j][i] == value[j][i-1])
                continue;
            else if(value[j][i] == pre_val + w[i])
            {
                j = j - w[i];
                w[i] = 0;
            }
        }
        
        if(value[W][n] == W && count == 3)
        {
            cout << 1 << endl;
            return 1;
            break;
        }
        if(value[W][n] != W)
        {
            cout << 0 << endl;
            return 0;
            break;
        }
    }
    return -1;
}

