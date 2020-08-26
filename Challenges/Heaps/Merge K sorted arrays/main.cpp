#include <iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;


typedef pair<int,pair <int,int>> node;



vector <int> MergeKSortedArray(vector <vector<int>> v, int k, int n)
{
    priority_queue <node, vector <node>, greater<node>> pq;

    for(int i=0;i<k;i++)
    {
        pq.push(make_pair(v[i][0],make_pair(i,0)));
    }

    vector <int> ans;

    while(!pq.empty())
    {
        node no = pq.top();
        pq.pop();

        ans.push_back(no.first);

        if(no.second.second+1<n)
        {
            pq.push(make_pair(v[no.second.first][no.second.second+1],make_pair(no.second.first,no.second.second+1)));
        }
    }

    return ans;

}




int main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int k,n; cin>>k>>n;

   vector<vector<int>> v;

    for(int i=0;i<k;i++)
    {
        vector <int> temp;

        for(int j=0;j<n;j++)
        {
            int no; cin>>no;
            temp.push_back(no);
        }
        v.push_back(temp);
        temp.clear();
    }


    vector <int> ans = MergeKSortedArray(v,k,n);

    for(auto i: ans)
        cout<<i<<" ";

    return 0;

}
