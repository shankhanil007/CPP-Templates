#include<iostream>
#include<queue>
using namespace std;

int main() {

	int q,k; cin>>q>>k;

    priority_queue <int, vector <int>, greater<int>> pq;   // min priority queue

	for(int w=1;w<=q;w++)
	{
        int choice; cin>>choice;
        if(choice==1)
        {
            int x,y; cin>>x>>y;
            int dis = x*x+y*y;
            pq.push(dis);
        }
        else
        {
            vector <int> v;
            for(int i=0;i<k-1;i++)
            {
                v.push_back(pq.top());
                pq.pop();
            }
            //cout<<pq.top()<<endl;
            for(auto i:v)
            {
                pq.push(v[i]);
            }
            v.empty();
        }

	}



	return 0;
}
