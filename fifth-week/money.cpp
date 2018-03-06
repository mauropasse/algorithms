#include <iostream>
using namespace std;
int main(void)
{
    int money;
    cin >> money;

    //money=34;
    int coins[]={1,3,4};
    int min_num_coins[money+1];
    min_num_coins[0]=0;

    
    for(int m=1; m<=money; m++)
    {
        min_num_coins[m] = 1000;
        for(int c=0;c<3;c++)
        {
            if(coins[c] <= m)
            {
                int num_coins = min_num_coins[m-coins[c]] + 1;
                if(num_coins < min_num_coins[m])
                {
                    min_num_coins[m] = num_coins;
                }
            }
        }
    }
    
//    for(int i=0;i<money;i++)    {
//        cout << min_num_coins[i];
//    }
//    cout << endl;
    cout << min_num_coins[money] << endl;
}
