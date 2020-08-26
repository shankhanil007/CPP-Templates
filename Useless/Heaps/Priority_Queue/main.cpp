#include <iostream>
#include  <queue>
using namespace std;


int main()
{

    priority_queue <int> pq;    // max priority queue

   // priority_queue <int, vector <int>, greater<int>> pq;   // min priority queue

    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int no; cin>>no;
        pq.push(no);            // O(logN)
    }


    //Remove the elements from the queue
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }


    return 0;
}
