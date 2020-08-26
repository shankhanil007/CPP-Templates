

// The idea is that just like right view we had a level and a maxlevel rowise. Now we will have such a level column wise bcuz the view is different.
// The center root node is at level 0, Whenever we move left we decrease the level and whenever we move right we increase the level.
// For each level we push the node in a map.
// The last node of each level int the map are the answers.




#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define setp(n) cout << fixed << setprecision(n)
#define mset(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define checkbit(x,i) (x&(1ll<<i))?1:0
#define setbit(x,i) x|(1ll<<i)
#define compbit(x,i) x^(1ll<<i)
#define ff first
#define ss second
#define mod 1000000007
#define N 100010


class node
{
public:
    int data;
    node*left,*right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *buildtreeLevel()
{
    int d;
    cin>>d;
    queue<node *>q;
    node *root=new node(d);
    q.push(root);
    int c1,c2;
    while(!q.empty())
    {
        node *f=q.front();
        q.pop();
        cin>>c1>>c2;
        if(c1!=-1)
        {
            f->left=new node(c1);
            q.push(f->left);
        }
        if(c2!=-1)
        {
            f->right=new node(c2);
            q.push(f->right);
        }
    }
    return root;
}

map <int,int> mp;

void print_top_view(node*root,int level)
{

	queue<pair<node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair <node*, int> f = q.front();

            auto it = mp.find(f.second);

			if(it!=mp.end())
			{
				mp.erase(it);
				mp.insert({f.second,f.first->data});
			}
			else
			{
				mp.insert({f.second,f.first->data});
			}

            q.pop();

            if(f.first->left){
                q.push(make_pair(f.first->left,f.second-1));
            }
            if(f.first->right){
                q.push(make_pair(f.first->right,f.second+1));
            }

    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node*root=buildtreeLevel();

    print_top_view(root,0);

    for (auto i : mp)
   	cout << i.second<<" ";

    return 0;
}
