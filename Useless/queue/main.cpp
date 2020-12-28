#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>
using namespace std;


// Maximum element in every window of size k

/*int main()
{
    deque <int> q;
    //int arr[]={12,1,78,90,57,89,56};
    int arr[]={1,3,2,1,4,5,2,3,6};

    int k=3;
    int i;

    for(i=0;i<k;i++)
    {
        while((!q.empty()) && arr[i]>=arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }

    for(;i<9;i++)
    {
        cout<<arr[q.front()]<<endl;
        while(!q.empty() && q.front()<=i-k)
            q.pop_front();
        while(!q.empty() && arr[i]>=arr[q.back()])
            q.pop_back();
        q.push_back(i);
        cout<<arr[q.front()]<<endl;
    }


    return 0;
}*/



// First non repeating character in a stream
int main()
{
    char ch;
    queue <char> q;
    unordered_map <char, int> mp;


    while(ch!='.')
    {
        cin>>ch;
        q.push(ch);
        mp[ch]++;

        while(!q.empty() && mp[q.front()]>1)
            q.pop();

        if(q.empty())
            cout<<"-1"<<endl;
        else
            cout<<q.front()<<endl;
    }



    return 0;
}
