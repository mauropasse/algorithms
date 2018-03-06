#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);
    int long_a = a.length()+1;
    int long_b = b.length()+1;

    vector <vector<int> > d;
    d.resize(long_a,vector<int>(long_b));
   
    for(int i=0;i<long_a;i++)
        d[i][0] = i; 
    for(int j=0;j<long_b;j++)
        d[0][j] = j; 

    for(int j=1;j<long_b;j++)
    {
        for(int i=1;i<long_a;i++)
        {
            d[i][j] = d[i][j-1]+1; 
            d[i][j] = min(d[i][j], d[i-1][j]+1); 
            if(a.at(i-1) == b.at(j-1))
                d[i][j] = min(d[i][j], d[i-1][j-1]); 
            else
                d[i][j] = min(d[i][j], d[i-1][j-1]+1); 
        }
    }
//    for(int i=0;i<long_a;i++)
//    {
//        for(int j=0;j<long_b;j++)
//            cout << d[i][j] << " ";
//        cout << endl;
//    }

   cout << d[long_a-1][long_b-1]<<endl;
   return 0;
}
