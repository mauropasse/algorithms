#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

int loop(void)
{
    int n;
    cout << endl;
    //cin >> n;

////////////////////////////////////////
    vector<long> res;
    long sumatoria = 0;
    int indice = 0;
    long max_num = rand()%500;
    while(true)
    {
        long random = rand()%30 + 1;
        if(sumatoria + random < max_num)
        {
            res.push_back(random);
            sumatoria += random;
            cout << random << ' ';
        }
        else
        {
            random = max_num - sumatoria;
            sumatoria += random;
            res.push_back(random);
            cout << random << ' ';
            cout << "sumatoria: "<<sumatoria << endl;
            sumatoria = 0;
            if(++indice == 3) break;
        }
    }
    cout << endl;
////////////////////////////////////////
    n = res.size();
    vector<int> w(n+1);
    vector<int> v(n+1);
    vector<int> r(n+1);
    int index = 0;
    int idx = 0;

    v[0] = w[0] = 0;

    for(int i=1;i<=n;i++)
        v[i] = w[i] = res[i-1]; 
    //for(int i=1;i<=n;i++)
    //    cout << v[i] << " "; 
    //cout << endl; 

    //for(int i=1;i<=n;i++)
    //    cin >> w[i]; 
    //for(int i=1;i<=n;i++)
    //    v[i] = w[i];

    long W =0;
    for(int i=0;i<=n;i++)
        W += w[i];

    if (W%3 == 0)
    {
        W = W/3;
        cout << "Es divisible!" << endl; 
    }
    else
    {
        cout << "W: " << W << endl; 
        cout << "No es divisible!" << endl; 
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

    int count = 0;
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
                    long val = value[j - w[i]][i-1] + v[i];
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
            else if(value[j][i] == pre_val + v[i])
            {
                j = j - w[i];
////////////////////////////////////////
                r[index++] = v[i];
////////////////////////////////////////
                v[i] = w[i] = 0;
            }
        }
        
////////////////////////////////////////
        int result = 0;
        for(int i=idx;i<index;i++)
        {
           result += r[i];
           cout << r[i] << '+';
        }
        cout << " = " << result << endl;
        idx=index;
////////////////////////////////////////
        if(value[W][n] == W && count == 3)
        {
            cout << 1 << endl;
            cout << "lo hizo!!!" << endl;
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

    cout << "****************************************" << endl;
    return 0;
}

int main(void)
{
    while(loop());
    cout << "todo mal" << endl;
    return 1;
}
