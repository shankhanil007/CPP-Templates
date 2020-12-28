#include <iostream>

using namespace std;

int main()
{
    int no; cin>>no;
    int low=0; int high=no;
    int mid; float ans;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid*mid==no)
        {
            cout<<mid;
            break;
        }
        else if(mid*mid>no)
        {
            high=mid-1;
        }
        else
        {
            ans=mid;
            low=mid+1;
        }
    }

    float inc=0.1;
    for(int i=1;i<=10;i++)
    {
        ans+=inc;
        if(ans*ans<=no)
        {

        }
        else
        {
            ans-=inc;   // important
            inc/=10;
        }
    }


    cout<<ans;
}
