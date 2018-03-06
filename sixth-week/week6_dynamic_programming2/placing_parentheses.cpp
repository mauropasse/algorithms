#include <iostream>
#include <iomanip>
#include <climits>
#include <cassert>
#include <string>
#include <vector>

using namespace std;
using std::vector;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

//void print_matrix(vector<vector<long long> >& m, vector<vector<long long> >& M)
//{
//  int n = m.size()-1;
//  //Print matrix M
//  cout << "M: " << endl;
//  for(int i=1;i<=n;i++)
//  {
//    for(int l=1;l<=n;l++)
//        cout << right << setw(3) << M[i][l] << ' ';
//    cout << endl;
//  }
//
//  //Print matrix m
//  cout << "m: " << endl;
//  for(int i=1;i<=n;i++)
//  {
//    for(int l=1;l<=n;l++)
//        cout << right << setw(3) << m[i][l] << ' ';
//    cout << endl;
//  }
//  cout << endl;
//}

void MinAndMax(int i, int j, long long& min_val, long long& max_val,
        vector<vector<long long> >& m, vector<vector<long long> >& M,
        vector<char>& op)
{
    max_val = LLONG_MIN;
    min_val = LLONG_MAX;

    for(int k=i;k<=j-1;k++)
    {
        long long a = eval(M[i][k], M[k+1][j], op[k]);
        long long b = eval(M[i][k], m[k+1][j], op[k]);
        long long c = eval(m[i][k], M[k+1][j], op[k]);
        long long d = eval(m[i][k], m[k+1][j], op[k]);

        min_val = min(min_val,a);
        min_val = min(min_val,b);
        min_val = min(min_val,c);
        min_val = min(min_val,d);

        max_val = max(max_val,a);
        max_val = max(max_val,b);
        max_val = max(max_val,c);
        max_val = max(max_val,d);
    }
}

void parentheses(vector<int>& d, vector<char>& op, 
        vector<vector<long long> >& m, vector<vector<long long> >& M)
{
    int n = d.size()-1;
    for(int i=1;i<=n;i++)
    {
        m[i][i] = M[i][i] = d[i];
    }

    for(int s=1;s<=n-1;s++)
    {
        for(int i=1;i<=n-s;i++)
        {
            int j = i + s;
            long long min_val, max_val;
            MinAndMax(i,j,min_val,max_val,m,M,op);
            m[i][j] = min_val;
            M[i][j] = max_val;
        }
    } 
    //print_matrix(m,M);
}

long long get_maximum_value(const string &exp) {
    int s_length=exp.length();
    int n = (s_length-1)/2;
    n++;

    //We do it one size longer to be consistent with the presentation. 
    vector<int> d(n+1);
    vector<char> op(n);
    d[0]=0;
    op[0]='0';

    for(int i=0,j=1;i<=s_length;i+=2,j++)
      d[j]=(int)exp.at(i) - 48;

    for(int i=1,j=1;i<s_length;i+=2,j++)
      op[j]=exp.at(i);

//    for(int i=1;i<=n;i++)
//      cout << d[i] << ' ';
//    cout << endl;
//    for(int i=1;i<n;i++)
//      cout << op[i] << ' ';
//    cout << endl << endl;

    // Create matrixs m & M 
    vector<vector<long long> > m; 
    vector<vector<long long> > M;
    m.resize(n+1);
    M.resize(n+1);
    for(long i=0;i<=n;i++)
    {
        m[i].resize(n+1);
        M[i].resize(n+1);
    }

    for(int i=0;i<=n;i++)
    for(int l=0;l<=n;l++)
        m[i][l] = M[i][l] = 0;

    parentheses(d,op,m,M);

    return M[1][n];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
