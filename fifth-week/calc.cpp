#include <iostream>
using namespace std;
int power2(int n)
{
    result = 1;
    for(int i=0;i<n;i++) 
        result *= 2;

}
int main(void)
{
    int n;
    //cin >> n;
    n=1;
    n=5;
    n=10;

    int operations[n+1];
    operations[0]=0;
    operations[1]=0;

    
    for(int i=2; i<=n; i++)
    {
         operations[i] = 1000;
        int op_suma =  operations[i-1] + 1;
        int op_trip=1000;
        int op_dup=1000;
        int op_dup_trip=1000;
        
        if(i%3 == 0)
            op_trip = i/3;
        if(i%3 == 1)
            op_trip = i/3 + 1;
        if(i%2 == 0)
            op_dup = i/2;
        if(i%2 == 1)
            op_dup = i/2 + 1;
        if(i%2 == 0)
            if(((i/2) % 3)==0)
                op_dup_trip = (i/2)/3 + 1;
        cout<<endl;
        cout<<"i: "<<i<<endl;
        cout<<"suma: "<<op_suma<<endl;
        cout<<"trip: "<<op_trip<<endl;
        cout<<"dup: "<<op_dup<<endl;
        cout<<"dup_trip: "<<op_dup_trip<<endl;
        
        if(op_suma< operations[i])
             operations[i]=op_suma;
        if(op_trip< operations[i])
             operations[i]=op_trip;
        if(op_dup< operations[i])
             operations[i]=op_dup;
        if(op_dup_trip< operations[i])
             operations[i]=op_dup_trip;

        cout<<"min operations: "<<operations[i]<<endl;

    }
    
    cout << endl;
}
