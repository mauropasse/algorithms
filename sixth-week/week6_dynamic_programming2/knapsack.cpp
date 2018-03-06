#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(void)
{
    int W,n;
    cin >> W;
    cin >> n;

    //As all bars ar golden, same value as weight for each (1)
    vector<int> v(n+1);
    vector<int> weight(n+1);

    v[0]=0;
    weight[0]=0;
    for(int i=1;i<=n;i++) 
    {
        cin >> weight[i];
        v[i] = weight[i];
    }

    vector<vector<int> >value;
    value.resize(W+1,vector<int>(n+1));

    for(int j=0;j<=n;j++) 
        value[0][j] = 0;
    for(int w=0;w<W;w++) 
        value[w][0] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=W;w++)
        {
            value[w][i] = value[w][i-1]; 
            if(weight[i] <= w)
            {
                int val = value[ w - weight[i] ][i-1] + v[i]; 
                value[w][i] = max(val, value[w][i]);
            }
        }
    }

//    for(int i=0;i<=n;i++)
//    {
//        for(int w=0;w<=W;w++)
//        {
//            cout << right << setw(2) << value[w][i] << " ";
//        }
//        cout << endl;
//    }

    cout << value[W][n] << endl;


    return 0;
}
    

