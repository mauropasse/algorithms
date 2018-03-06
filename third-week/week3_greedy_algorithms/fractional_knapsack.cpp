#include <iostream>
#include <iomanip>

using namespace std;
void order_max_to_min(unsigned long* v, unsigned long* w, unsigned int n)
{
    for(unsigned int j=0; j<n-1; j++)
    {
        int changes = 0;
        for(unsigned int i=0; i<n-1; i++)
        {
            float ratio[2];
            ratio[0]=(float)v[i]/w[i];
            ratio[1]=(float)v[i+1]/w[i+1];

            //cout << " ->ratio1 : " << ratio[0] << endl;
            //cout << " ->ratio2 : " << ratio[1] << endl;
            
            if(ratio[0]<ratio[1])
            {
                unsigned long aux= v[i];
                v[i] = v[i+1];
                v[i+1] = aux;

                aux= w[i];
                w[i] = w[i+1];
                w[i+1] = aux;

                changes++;
            }
        }
        if(changes <= 1)
        {
            if(n>3) break;
        }
    }
}

float get_max_value(unsigned long W, unsigned long* v, unsigned long* w, unsigned int n)
{
    float max_val = 0;
    for(unsigned int i=0; i<n; i++)
    {
        if(w[i] <= W)
        {
            W = W - w[i];
            max_val = max_val + v[i];
            if(W == 0)
                break;
        }
        else
        {
            float ratio = W /(float)w[i];
            max_val = max_val + ratio*v[i];
            break;
        }

    }
    return max_val;
}

int main(void)
{
    unsigned int n;
    unsigned long W;

    cin >> n >> W;
    
    unsigned long v[n], w[n];

    for(unsigned int i=0; i<n; i++)
    {
        cin >> v[i] >> w[i];
    }

//    for(unsigned int i=0; i<n; i++)
//    {
        //cout << v[i] << " " << w[i];
//        float ratio=v[i]/w[i];
        //cout << " ->ratio: " << ratio << endl;
//    }
    
    //cout << endl;

    if(n>1)
    {
        //cout << "order!!!"<< endl;
        order_max_to_min(v,w,n);

        for(unsigned int i=0; i<n; i++)
        {
            //cout << v[i] << " " << w[i];
            float ratio=v[i]/w[i];
            //cout << " ->ratio: " << ratio << endl;
        }
    }

    float max_value = get_max_value(W,v,w,n);

    //cout << "Max Value: " << std::fixed << std::setprecision(4) << max_value << endl;
    cout << std::fixed << std::setprecision(4) << max_value << endl;
}
