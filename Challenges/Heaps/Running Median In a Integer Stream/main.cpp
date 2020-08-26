#include <iostream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int q; cin>>q;
    for(int w=1;w<=q;w++)
    {
        int n; cin>>n;

        priority_queue <int> max;
        priority_queue <int, vector <int>, greater<int>> min;

        int no; cin>>no;

        double median = no;
        max.push(no);

        cout<<median<<" ";


        for(int i=1;i<n;i++)
        {
            cin>>no;
            int min_size = min.size();
            int max_size = max.size();

            if(no<=median)
            {
                if(max_size < min_size)
                {
                    max.push(no);
                    median = (max.top()+min.top())/2;
                }
                else if(min_size == max_size)
                {
                    max.push(no);
                    median = max.top();
                }
                else
                {
                    min.push(max.top());
                    max.pop();
                    max.push(no);
                    median = (max.top()+min.top())/2;
                }
            }

            else if(no>median)
            {
                if(min_size < max_size)
                {
                    min.push(no);
                    median = (min.top()+max.top())/2;
                }
                else if(min_size == max_size)
                {
                    min.push(no);
                    median = min.top();
                }
                else
                {
                    max.push(min.top());
                    min.pop();
                    min.push(no);
                    median = (max.top()+min.top())/2;
                }
            }

            cout<<median<<" ";

        }

        cout<<endl;
    }


    return 0;
}
