#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(void)
{
    int n;

    cin >> n;
    vector<int> w(n+1);
    vector<int> v(n+1);
    v[0] = w[0] = 0;

    for(int i=1;i<=n;i++)
        cin >> w[i]; 
    for(int i=1;i<=n;i++)
        v[i] = w[i];

    ///////////////////////////////////////////////////////////////////////
    //n = 11;
    //n = 3;
    //the iterator constructor can also be used to construct from arrays:
    //int myints[] = {0,1,8};
    //std::vector<int> w (myints, myints + sizeof(myints) / sizeof(int) );
    //std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    ///////////////////////////////////////////////////////////////////////

    int W =0;
    for(int i=0;i<=n;i++)
        W += w[i];

    if (W%3 == 0)
    {
        W = W/3;
        cout << "W = " << W << endl;
    }
    else
    {
        cout << "All is lost!" << endl;
        cout << 0 << endl;
        return 1;
    }
    
    vector<vector<int> > value;
    value.resize(W+1);
    for(int w=0;w<=W;w++)
        value[w].resize(n+1);

    for(int w=0;w<=W;w++)
        value[w][0] = 0;
    for(int j=0;j<=n;j++)
        value[0][j] = 0;

    int count = 0;
    while(true)
    {
        cout << "array: ";
        for(int j=0;j<=n;j++)
            cout << w[j] << ' ';
        cout << endl;
        count++;
        int weight = 0, element = 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                value[j][i] = value[j][i-1];
                if (w[i]<=j)
                {
                    int val = value[j - w[i]][i-1] + v[i];
                    value[j][i] = max(value[j][i],val);
                    if(value[j][i] == W) 
                    {
                        weight = j;
                        element = i;
                    }
                }
            }
        }
        
        cout << endl;
        for(int j=weight;element>0;element--)
        {
            cout << "j= " << j <<". " << "Element: " << element;
            if(j<w[element]) continue;
            cout << ". v[el]=" << w[element]<<". "<< endl;
            int pre_val = value[j-w[element]][element-1]; 
            cout << "lastval: " << value[j][element];
            cout << " - arrival: " << value[j][element-1];
            cout << " - preval: " << pre_val << endl;
            if(value[j][element] == value[j][element-1])
            {
                cout << "Iguales, no se uso el elemento " << element << endl;
                cout << endl;
                continue;
            }
            else if(value[j][element] == pre_val + v[element])
            {
                cout << "Eran iguale! Se uso el elemento " << element << endl;
                j = j - w[element];
                v[element] = 0;
                w[element] = 0;
            }
            else
            {
                cout << "No equal! NO se uso el elemento " << element << endl;
            }
            cout << endl;
        }
        cout << endl;
        for(int w=0;w<=W;w++)
            cout << left << setw(2) << w << " ";

        for(int j=0;j<=n;j++)
        {
            cout << endl;
            for(int w=0;w<=W;w++)
                cout << left << setw(2) << value[w][j] << " ";
        }
        cout << endl;
        if(value[W][n] == W && count == 3)
        {
            cout << "Yay!!" << endl;
            break;
        }
        if(value[W][n] != W)
        {
            cout << "ouchhh, almost!!!" << endl;
            cout << "count: " << count << endl;
            cout << 0 << endl;
            break;
        }
        cout << endl << "Value[w,j] = Value[" <<W<<','<<n<<"] = ";
        cout <<value[W][n] << endl;
    }

    cout << endl << "Value[w,j] = Value[" <<W<<','<<n<<"] = ";
    cout <<value[W][n] << endl;
}

