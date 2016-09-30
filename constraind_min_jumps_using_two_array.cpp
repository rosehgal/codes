/*
You are given two strings, say A and B, of the same length, say N. You can swap A[i] and B[i] for all i between 1 and N, inclusive. You cannot swap two characters within A, or within B. Also, you can only swap a character in A with the character at the same index in B, and with no other character. You can perform this operation zero or more times.
You wish to modify the strings through the operations in such a way that the number of unique characters in the strings is small. In fact if n(A) is the number of unique characters in A and n(B) is the number of unique characters in B; you wish to perform the operations such that max(n(A),n(B)) is as small as possible.
Print the value of max(n(A),n(B)) after all the operations.
*/

#include <bits/stdc++.h>
using namespace std;

int min_penlaty(vector<int> a,vector<int> b,int k,int shift_penalty)
{
    vector<pair<int,char> > penalty(a.size(),pair<int,char>(INT_MAX,'a'));
    penalty[0]=pair<int,char>(a[0],'a');
    for(int i=1;i<a.size();++i)
    {
        if(penalty[i-1].second=='a')
        {
            for(int j=i;j<i+k && j<a.size();++j)
                penalty[j]=pair<int,char>(min(penalty[j].first,penalty[i-1].first+a[j]),'a');
            for(int j=i;j<i+k && j<b.size();++j)
                if(penalty[j].first>penalty[i-1].first+b[j]+shift_penalty)
                    penalty[j]=pair<int,char>(penalty[i-1].first+b[j]+shift_penalty,'b');
        }
        else
        {
            for(int j=i;j<i+k && j<b.size();++j)
                penalty[j]=pair<int,char>(min(penalty[j].first,penalty[i-1].first+b[j]),'b');
            for(int j=i;j<i+k && j<b.size();++j)
                if(penalty[j].first>penalty[i-1].first+a[j]+shift_penalty)
                    penalty[j]=pair<int,char>(penalty[i-1].first+b[j]+shift_penalty,'a');
        }

        for(auto a:penalty)
            cout<<a.first<<","<<a.second<<"\t";
        cout<<"\n";

    }
    return penalty[a.size()-1].first;
}


int main()
{
    vector<int> a{1,20,20,20,20},b{10,1,1,1,1};
    int k,shift_penalty;
    cin>>k>>shift_penalty;
    cout<<min(min_penlaty(a,b,k,shift_penalty),min_penlaty(b,a,k,shift_penalty));
    return 0;
}
