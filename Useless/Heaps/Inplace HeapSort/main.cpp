#include <iostream>
#include <vector>
using namespace std;



    void print(vector <int> v){
        for(int x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }


    bool minHeap = false;


    bool compare(int a, int b){
        if(minHeap)
            return a<b;
        else
            return a>b;
    }

   void heapify(vector <int> &v, int idx, int size)
    {
        int left = 2*idx;
        int right = left+1;

        int min_idx = idx;
        int last = size -1;

        // You also need to check whether left and right indices exist or not
        if(left<=last && compare(v[left],v[idx])){
            min_idx = left;
        }

        if(right<=last && compare(v[right],v[min_idx])){
            min_idx = right;
        }

        if(min_idx != idx){
            swap(v[idx], v[min_idx]);
            heapify(v,min_idx,size);
        }

    }

    void buildHeap(vector <int> &v){
        for(int i=(v.size()-1)/2;i>=1;i--)
        {
            heapify(v,i,v.size());
        }
    }




    void heapsort(vector <int> &arr){

        buildHeap(arr);
        int n = arr.size();

        //remove n-1 elements from the heap
        while(n>1){
            swap(arr[1], arr[n-1]);
            //remove that element from the heap
            n--;
            heapify(arr,1,n);
        }
    }








int main()
{
    vector <int> v{-1,10,12,13,14,9,8,6};
    heapsort(v);
    print(v);


    return 0;
}
