#include <iostream>
#include <iomanip>

unsigned int get_index_max_ratio(unsigned long* v, unsigned long* w, unsigned int n)
{
    double max_ratio = 0;
    unsigned int index = 0;
    for(unsigned int i=0; i<n; i++)
    {
        double ratio = (double)v[i]/w[i];
        if(ratio>max_ratio)
        {
            max_ratio = ratio;
            index = i;
        }
    }
    return index;
}

double get_max_value(unsigned long W, unsigned long* v, unsigned long* w, unsigned int n)
{
    double max_val = 0;
    while(W)
    {
        unsigned int i = get_index_max_ratio(v,w,n);

        if(w[i] <= W)
        {
            W = W - w[i];
            max_val = max_val + v[i];
            if(W == 0)
                break;
        }
        else
        {
            double ratio = W /(double)w[i];
            max_val = max_val + ratio*v[i];
            break;
        }
        
        v[i]=0;
    }
    return max_val;
}

int main(void)
{
    unsigned int n;
    unsigned long W;

    std::cin >> n >> W;
    
    unsigned long v[n], w[n];

    for(unsigned int i=0; i<n; i++)
    {
        std::cin >> v[i] >> w[i];
    }

    double max_value = get_max_value(W,v,w,n);

    //cout << "Max Value: " << std::fixed << std::setprecision(4) << max_value << endl;
    std::cout << std::fixed << std::setprecision(4) << max_value << std::endl;
}
