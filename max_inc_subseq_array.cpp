#include <iostream>
#include <vector>
#include <utility>
using namespace std;


vector<int> longest_inc_sub_arr(vector<int> arr)
{
    vector<pair<int,int> > maxseq;

    for(int i=0;i<arr.size();++i)
    {
        int val=1,prev=-1;
        for(int j=0;j<i;++j)
            if(arr[i]>arr[j] && maxseq[j].first+1>val)
            {
                val=maxseq[j].first+1;
                prev=j;
            }

        maxseq.push_back(pair<int,int>(val,prev));
    }
    //to check if the max seq array working fine or not
    /*for(auto a:maxseq)
        cout<<a<<" ";
    */
    vector<int> seq;
    int i=maxseq[maxseq.size()-1].second;
    while(i>=0)
    {
        seq.insert(seq.begin(),arr[i]);
        i=maxseq[i].second;
    }
    if(arr[arr.size()-1]>arr[maxseq[maxseq.size()-1].second])
        seq.push_back(arr[arr.size()-1]);

    return seq;
}


int main(int argc, char const *argv[])
{
    int arr[]={10,22,9,33,21,50,41,60,80};
    vector<int> vec(arr,arr+9);

    for(auto a: longest_inc_sub_arr(vec))
        cout<<a<<" ";

    return 0;
}
