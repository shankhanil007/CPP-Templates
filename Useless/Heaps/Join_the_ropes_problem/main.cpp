#include <iostream>
#include <queue>
using namespace std;

int main()
{

    priority_queue <int, vector <int>, greater<int>> pq;

    int arr[4]={4,3,2,6};

    for(int i=0;i<4;i++)
    {
        pq.push(arr[i]);
    }

    int cost=0;

    while(pq.size()>1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        cost+=a+b;

        pq.push(a+b);
    }

    cout<<cost;


    return 0;
}
