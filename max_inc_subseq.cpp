#include <iostream>
#include <vector>
using namespace std;


int length_max_inc_subseq(vector<int> arr)
{
    vector<int> maxseq;
    for(int i=0;i<arr.size();++i)
    {
        int val=1;
        for(int j=0;j<i;++j)
            if(arr[i]>arr[j] && maxseq[j]+1>val)
                val=maxseq[j]+1;
        maxseq.push_back(val);
    }
    //to check if the max seq array working fine or not
    /*for(auto a:maxseq)
        cout<<a<<" ";
    */
    return maxseq[arr.size()-1];
}


int main(int argc, char const *argv[]) {
    int arr[]={10,22,9,33,21,50,41,60,80};
    vector<int> vec(arr,arr+9);
    cout<<length_max_inc_subseq(vec);
    return 0;
}
