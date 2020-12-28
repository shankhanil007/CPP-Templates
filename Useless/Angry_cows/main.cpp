#include <iostream>

using namespace std;

int main()
{
    int len, cows;
    cin>>len>>cows;
    int arr[len];
    for(int i=0;i<len;i++)
    {
        cin>>arr[i];
    }

    int low=0, high=arr[len-1]; int mid; int ans;
    while(low<=high)
    {
        mid=(low+high)/2;
        int count=1, prev_cow=arr[0];
        for(int i=1;i<len;i++)
        {
            if(arr[i]-prev_cow>=mid)
            {
                count++;
                prev_cow=arr[i];
            }
            if(count==cows)
            {
                ans=mid;
                low=mid+1;
                break;
            }
        }
        if(count!=cows)
        {
            high=mid-1;
        }
    }
    cout<<ans;
}
