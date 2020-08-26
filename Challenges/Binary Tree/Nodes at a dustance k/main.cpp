#include<bits/stdc++.h>
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


class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

};



node* build(int *pre, int *in, int s, int e)
{
    static int i=0;

    if(s>e)
        return NULL;

    node* root = new node(pre[i]);

    int index=-1;
    for(int j=s;s<=e;j++)
    {
        if(pre[i]==in[j])
        {
            index = j;
            break;
        }
    }

    i++;

    root->left = build(pre, in, s, index-1);
    root->right = build(pre, in, index+1, e);

	return root;

}


int flag=0;
vector <int> v;

// Function to print the Kth level of the tree starting from a given node
void printKthLevel(node* root, int k)
{
    if(root == NULL)
        return;

    if(k == 0)
    {
        v.push_back(root->data);
		flag=1;
        return;
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);

    return;
}


// Function to find the nodes at a distance K from a given node
int printAtDistanceK(node* root, int target, int k)
{
    // base case
    if(root == NULL){
        return -1;
    }

    //reach the target node
    if(root->data == target){
        printKthLevel(root , k);
        return 0;
    }

    // next step - ancestor
    int dl = printAtDistanceK(root->left, target, k);

    if(dl != -1){

        // Again there are 2 cases
        // Ancestor itself or you need to go to the right ancestor
        if(dl+1 == k){
            v.push_back(root->data);
			flag=1;
        }
        else{
            printKthLevel(root->right, k-2-dl);
        }

        return dl+1;
    }

    // next step - ancestor
    int dr = printAtDistanceK(root->right, target, k);

    if(dr != -1){

        // Again there are 2 cases
        // Ancestor itself or You need to go to the left ancestor
        if(dr+1 == k){
            v.push_back(root->data);
			flag=1;
        }
        else{
            printKthLevel(root->left, k-2-dr);
        }

        return dr+1;
    }

    //node was not present in left and right subtree
    return -1;
}



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n; cin>>n;
    int pre[n]; int in[n];
    for(int j=0;j<n;j++)
        cin>>pre[j];
    for(int j=0;j<n;j++)
        cin>>in[j];

    node* root = build(pre,in,0,n-1);

    int q; cin>>q;
    for(int w=1;w<=q;w++)
    {
        int target; cin>>target;
        int k; cin>>k;
        printAtDistanceK(root, target, k);
		if(flag==0)
			cout<<"0";
		else
		{
			sort(v.begin(),v.end());
			for(auto p : v)
				cout<<p<<" ";
		}
        cout<<endl;
		flag=0;
		v.clear();
    }

    return 0;
}

